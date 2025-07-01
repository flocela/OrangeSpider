#ifndef first_app_hpp
#define first_app_hpp

//#include <stdio.h>
#include "lve_window.hpp"
#include "lve_pipeline.hpp"

namespace lve
{
    class FirstApp
    {
        public:
        
        static constexpr int WIDTH  = 800;
        static constexpr int HEIGHT = 600;
        
        void run();
        
        private:
        
        LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        LvePipeline lvePipeline{"/Users/flo/LocalDocuments/Projects/VulkanLearning/OrangeSpider/OrangeSpider/shaders/simple_shader.vert.spv",
            "/Users/flo/LocalDocuments/Projects/VulkanLearning/OrangeSpider/OrangeSpider/shaders/simple_shader.frag.spv"};
    };
}

#endif /* first_app_hpp */
