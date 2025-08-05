#include "first_app.hpp"
#include <stdexcept>

namespace lve
{
    
    FirstApp::FirstApp()
    {
        loadModels();
        
        // 1. Need a VkPipelineLayout to initialize Pipeline in createPipeline().
        createPipelineLayout();
        
        // 2. Creates a LvePipeline. LvePipeline constructor takes in the VkPipelineLayout.
        recreateSwapChainAndPipeline();
        
        // 3. LvePipeline contains a graphics pipeline. LvePipeline binds the commandBuffer to this graphicsPipeline in createCommandBuffers.
        createCommandBuffers();
    }
    
    FirstApp::~FirstApp()
    {
        vkDestroyPipelineLayout(lveDevice.device(), pipelineLayout, nullptr);
    }
    
    void FirstApp::freeCommandBuffers()
    {
        vkFreeCommandBuffers(lveDevice.device(), lveDevice.getCommandPool(), static_cast<float>(commandBuffers.size()), commandBuffers.data());
        commandBuffers.clear();
    }
        
    void FirstApp::run()
    {
        while(!lveWindow.shouldClose())
        {
            glfwPollEvents();
            drawFrame();
        }

        vkDeviceWaitIdle(lveDevice.device());
    }

    void FirstApp::loadModels()
    {
        std::vector<LveModel::Vertex> vertices
        {
            {{0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}},
            {{0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}},
            {{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}}
        };
        lveModel = std::make_unique<LveModel>(lveDevice, vertices);
    }

    void FirstApp::createPipelineLayout()
    {
        // pipelineLayoutInfo has pSetLayouts and pPushConstantRanges. This is information
        // that is sent to the shader programs.
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0;
        // pSetLayouts is used to pass data other than vertex data to our vertex and fragment shaders (that is textures and uniform buffer objects).
        pipelineLayoutInfo.pSetLayouts = nullptr;
        pipelineLayoutInfo.pushConstantRangeCount = 0;
        // push constants send small amount of data to shader programs.
        pipelineLayoutInfo.pPushConstantRanges = nullptr;
        if(vkCreatePipelineLayout(lveDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create pipeline layout!");
        }
    }

    void FirstApp::createPipeline()
    {
        assert(lveSwapChain != nullptr && "Cannot create pipeline before swap chain.");
        assert(pipelineLayout != nullptr && "Cannot create pipeline before pipelinelayout.");
        
        LvePipelineConfigInfo pipelineConfig{};
        LvePipeline::defaultPipelineConfigInfo(pipelineConfig);
        
        pipelineConfig.renderPass = lveSwapChain->getRenderPass();
        
        pipelineConfig.pipelineLayout = pipelineLayout;
        
        lvePipeline = std::make_unique<LvePipeline>(
            lveDevice,
            "/Users/flo/LocalDocuments/Projects/VulkanLearning/OrangeSpider/OrangeSpider/shaders/simple_shader.vert.spv",
            "/Users/flo/LocalDocuments/Projects/VulkanLearning/OrangeSpider/OrangeSpider/shaders/simple_shader.frag.spv",
            pipelineConfig
        );
    }
    
    void FirstApp::recreateSwapChainAndPipeline()
    {
        auto extent = lveWindow.getExtent();
        while(extent.width == 0 || extent.height == 0)
        {
            extent = lveWindow.getExtent();
            glfwWaitEvents();
        }
        vkDeviceWaitIdle(lveDevice.device());
        
        if (lveSwapChain == nullptr)
        {
            lveSwapChain = std::make_unique<LveSwapChain>(lveDevice, extent);
        }
        else
        {
            lveSwapChain = std::make_unique<LveSwapChain>(lveDevice, extent, std::move(lveSwapChain));
            if (lveSwapChain->imageCount() != commandBuffers.size())
            {
                freeCommandBuffers();
                createCommandBuffers();
            }
        }
        
        createPipeline();
    }

    void FirstApp::createCommandBuffers()
    {
        commandBuffers.resize(lveSwapChain->imageCount());
        VkCommandBufferAllocateInfo allocInfo{};
        allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocInfo.commandPool = lveDevice.getCommandPool();
        allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());
        
        if( VK_SUCCESS != 
            vkAllocateCommandBuffers(lveDevice.device(), &allocInfo, commandBuffers.data())
        )
        {
            throw std::runtime_error("failed to allocate command buffers!");
        }
    }
    
    void FirstApp::recordCommandBuffer(int imageIndex)
    {
        VkCommandBufferBeginInfo beginInfo{};
        beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        
        
        if( vkBeginCommandBuffer(commandBuffers[imageIndex], &beginInfo) != VK_SUCCESS )
        {
            throw std::runtime_error("failed to begin recording command buffer!");
        }
        
        VkRenderPassBeginInfo renderPassInfo{};
        renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        renderPassInfo.renderPass = lveSwapChain->getRenderPass();
        renderPassInfo.framebuffer = lveSwapChain->getFrameBuffer(imageIndex);
        
        renderPassInfo.renderArea.offset = {0, 0};
        renderPassInfo.renderArea.extent = lveSwapChain->getSwapChainExtent();
        
        std::array<VkClearValue, 2> clearValues{};
        clearValues[0].color = {0.1f, 0.1f, 0.1f, 1.0f};
        clearValues[1].depthStencil = {1.0f, 0};
        renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
        renderPassInfo.pClearValues = clearValues.data();
        
        vkCmdBeginRenderPass(commandBuffers[imageIndex], &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
        
        VkViewport viewport{};
        viewport.x = 0.0f;
        viewport.y = 0.0f;
        viewport.width = static_cast<float>(lveSwapChain->getSwapChainExtent().width);
        viewport.height = static_cast<float>(lveSwapChain->getSwapChainExtent().height);
        viewport.minDepth = 0.0f;
        viewport.maxDepth = 1.0f;
        VkRect2D scissor{{0, 0}, lveSwapChain->getSwapChainExtent()};
        vkCmdSetViewport(commandBuffers[imageIndex], 0, 1, &viewport);
        vkCmdSetScissor(commandBuffers[imageIndex], 0, 1, &scissor);
        
        
        lvePipeline->bind(commandBuffers[imageIndex]); // link graphicsPipeline to commandBuffer
        
        lveModel->bind(commandBuffers[imageIndex]); // vkCmdBindVertexBuffers, binds commandBuffers and vertex buffers.
        lveModel->draw(commandBuffers[imageIndex]); // vkCmdDraw
        
        // draw 3 vertices and only one instance.
        //vkCmdDraw(commandBuffers[i], 3, 1, 0, 0);
        
        vkCmdEndRenderPass(commandBuffers[imageIndex]);
        if(vkEndCommandBuffer(commandBuffers[imageIndex]) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to record command buffer!");
        }
    }

    void FirstApp::drawFrame()
    {
        uint32_t imageIndex;
        
        // Fetches the index of the frame we should render to next.
        // Automatically handles all the CPU and GPU synchronization surrounding double and
        // triple buffering.
        auto result = lveSwapChain->acquireNextImage(&imageIndex);
        
        if (result == VK_ERROR_OUT_OF_DATE_KHR)
        {
            recreateSwapChainAndPipeline();
            return;
        }
        
        if(result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
        {
            throw std::runtime_error("failed to acquire swap chain image!");
        }
        
        recordCommandBuffer(imageIndex);
        
        // Submits provided command buffer to the device graphics queue while handling synchronization.
        // The command buffer will then be executed.
        result = lveSwapChain->submitCommandBuffers(&commandBuffers[imageIndex], &imageIndex);
        if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || lveWindow.wasWindowResized())
        {
            lveWindow.resetWindowResizedFlag();
            recreateSwapChainAndPipeline();
            return;
        }
        if(result != VK_SUCCESS)
        {
            throw std::runtime_error("failed to present swap cahin image!");
        }
    }

}// namespace lve
