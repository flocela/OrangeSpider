#pragma once

#include "lve_pipeline.hpp"
#include "lve_game_object.hpp"
#include "lve_device.hpp"
#include <memory>
#include <vector>

namespace lve
{
    
    class SimpleRenderSystem
    {
        public:
        
        SimpleRenderSystem(LveDevice& device, VkRenderPass renderPass);
        ~SimpleRenderSystem();
        SimpleRenderSystem(const SimpleRenderSystem& o) = delete;
        SimpleRenderSystem& operator=(const SimpleRenderSystem& o) = delete;
        
        void renderGameObjects(VkCommandBuffer commandBuffer, std::vector<LveGameObject>& gameObjects);
        
        private:
        
        void createPipelineLayout();
        void createPipeline(VkRenderPass renderPass);
        
        LveDevice& lveDevice;
        VkPipelineLayout pipelineLayout;
        std::unique_ptr<LvePipeline> lvePipeline;
        
    };
}
