#ifndef first_app_hpp
#define first_app_hpp


#include <stdio.h>
#include "lve_pipeline.hpp"
#include "lve_window.hpp"
#include "lve_swap_chain.hpp"
#include "lve_game_object.hpp"
#include <memory>
#include <vector>
//
namespace lve
{
    
    class FirstApp
    {
        public:
        
        FirstApp();
        ~FirstApp();
        
        FirstApp(const FirstApp& o) = delete;
        FirstApp& operator=(const FirstApp& o) = delete;
        
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;
        
        void run();
        
        private:
        
        void loadGameObjects();
        void renderGameObjects(VkCommandBuffer commadnBuffer);
        LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        LveDevice lveDevice{lveWindow};
        std::unique_ptr<LveSwapChain> lveSwapChain;
        VkPipelineLayout pipelineLayout;
        std::unique_ptr<LvePipeline> lvePipeline;
        std::vector<VkCommandBuffer> commandBuffers;
        std::vector<LveGameObject> gameObjects;
        
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void freeCommandBuffers();
        void drawFrame();
        void recreateSwapChainAndPipeline();
        void recordCommandBuffer(int imageIndex);
        
    };
}

#endif /* first_app_hpp */
