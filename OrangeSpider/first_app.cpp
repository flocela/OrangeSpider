#include "first_app.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#include <stdexcept>

namespace lve
{
    struct SimplePushConstantData
    {
        glm::mat2 transform{1.f};
        glm::vec2 offset;
        alignas(16)glm::vec3 color;
    };

    FirstApp::FirstApp()
    {
        loadGameObjects();
        
        // 1. Need a VkPipelineLayout to initialize Pipeline in createPipeline().
        createPipelineLayout();
        createPipeline();
    }
    
    FirstApp::~FirstApp()
    {
        vkDestroyPipelineLayout(lveDevice.device(), pipelineLayout, nullptr);
    }
    void FirstApp::run()
    {
        while(!lveWindow.shouldClose())
        {
            glfwPollEvents();
            if (auto commandBuffer = lveRenderer.beginFrame())
            {
                lveRenderer.beginSwapChainRenderPass(commandBuffer);
                renderGameObjects(commandBuffer);
                lveRenderer.endSwapChainRenderPass(commandBuffer);
                lveRenderer.endFrame();
            }
        }

        vkDeviceWaitIdle(lveDevice.device());
    }

    void FirstApp::loadGameObjects()
    {
        std::vector<LveModel::Vertex> vertices
        {
            {{0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}},
            {{0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}},
            {{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}}
        };
        auto lveModel = std::make_shared<LveModel>(lveDevice, vertices);
        auto triangle = LveGameObject::createGameObject();
        triangle.model = lveModel;
        triangle.color = {0.1f, 0.8f, 0.1f};
        triangle.transform2d.translation.x = 0.2f;
        triangle.transform2d.scale = {2.0f, 0.5f};
        triangle.transform2d.rotation = 0.25f * glm::two_pi<float>();
        
        gameObjects.push_back(std::move(triangle));
    }

    void FirstApp::createPipelineLayout()
    {
        VkPushConstantRange pushConstantRange{};
        pushConstantRange.stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
        pushConstantRange.offset = 0;
        pushConstantRange.size = sizeof(SimplePushConstantData);
        // pipelineLayoutInfo has pSetLayouts and pPushConstantRanges. This is information
        // that is sent to the shader programs.
        VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
        pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
        pipelineLayoutInfo.setLayoutCount = 0;
        // pSetLayouts is used to pass data other than vertex data to our vertex and fragment shaders (that is textures and uniform buffer objects).
        pipelineLayoutInfo.pSetLayouts = nullptr;
        pipelineLayoutInfo.pushConstantRangeCount = 1;
        // push constants send small amount of data to shader programs.
        pipelineLayoutInfo.pPushConstantRanges = &pushConstantRange;
        if(vkCreatePipelineLayout(lveDevice.device(), &pipelineLayoutInfo, nullptr, &pipelineLayout) != VK_SUCCESS)
        {
            throw std::runtime_error("failed to create pipeline layout!");
        }
    }

    void FirstApp::createPipeline()
    {
        assert(pipelineLayout != nullptr && "Cannot create pipeline before pipelinelayout.");
        
        LvePipelineConfigInfo pipelineConfig{};
        LvePipeline::defaultPipelineConfigInfo(pipelineConfig);
        
        pipelineConfig.renderPass = lveRenderer.getSwapChainRenderPass();
        
        pipelineConfig.pipelineLayout = pipelineLayout;
        
        lvePipeline = std::make_unique<LvePipeline>(
            lveDevice,
            "/Users/flo/LocalDocuments/Projects/VulkanLearning/OrangeSpider/OrangeSpider/shaders/simple_shader.vert.spv",
            "/Users/flo/LocalDocuments/Projects/VulkanLearning/OrangeSpider/OrangeSpider/shaders/simple_shader.frag.spv",
            pipelineConfig
        );
    }
    
    void FirstApp::renderGameObjects(VkCommandBuffer commandBuffer)
    {
        lvePipeline->bind(commandBuffer);
        for (auto& obj: gameObjects)
        {
            obj.transform2d.rotation = glm::mod(obj.transform2d.rotation + 0.01f, glm::two_pi<float>());
            SimplePushConstantData push{};
            push.offset = obj.transform2d.translation;
            push.color = obj.color;
            push.transform = obj.transform2d.mat2();
            vkCmdPushConstants(
                commandBuffer,
                pipelineLayout,
                VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT,
                0,
                sizeof(SimplePushConstantData),
                &push);
            obj.model->bind(commandBuffer);
            obj.model->draw(commandBuffer);
        }
    }

}// namespace lve
