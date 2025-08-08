#pragma once

#include "lve_device.hpp"
#include "lve_swap_chain.hpp"
#include "lve_window.hpp"

#include <cassert>
#include <memory>
#include <vector>
//
namespace lve
{
    
    class LveRenderer
    {
        private:
        
        LveWindow& lveWindow;
        LveDevice& lveDevice;
        std::unique_ptr<LveSwapChain> lveSwapChain;
        std::vector<VkCommandBuffer> commandBuffers;
        
        void createCommandBuffers();
        void freeCommandBuffers();
        void drawFrame();
        void recreateSwapChain();
        
        uint32_t currentImageIndex;
        bool isFrameStarted = false;
        int currentFrameIndex{0};
        
        public:
        
        LveRenderer(LveWindow& window, LveDevice& device);
        ~LveRenderer();
        LveRenderer(const LveRenderer& o) = delete;
        LveRenderer& operator=(const LveRenderer& o) = delete;
        
        int getFrameIndex() const
        {
            assert(isFrameStarted && "Cannot get frame index when frame is in progress.");
            return currentFrameIndex;
        }
        
        bool isFrameInProgress() const { return isFrameStarted;}
        
        VkRenderPass getSwapChainRenderPass() const
        {
            return lveSwapChain->getRenderPass();
        }
        
        float getAspectRatio() const { return lveSwapChain->extentAspectRatio();}
        
        VkCommandBuffer getCurrentCommandBuffer() const 
        {
            assert(isFrameStarted && "Cannot get command buffer when frame not in progress.");
            return commandBuffers[currentFrameIndex];
        }
        
        VkCommandBuffer beginFrame();
        void endFrame();
        void beginSwapChainRenderPass(VkCommandBuffer commandBuffer);
        void endSwapChainRenderPass(VkCommandBuffer commandBuffer);
        
        
        
        
        
        
    };
}
