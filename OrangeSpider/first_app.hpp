#ifndef first_app_hpp
#define first_app_hpp


#include <stdio.h>
#include "lve_window.hpp"
#include "lve_game_object.hpp"
#include "lve_renderer.hpp"
#include "lve_device.hpp"
#include "lve_descriptors.hpp"
#include <memory>
#include <vector>

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
        
        LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        LveDevice lveDevice{lveWindow};
        LveRenderer lveRenderer{lveWindow, lveDevice};
        
        // note: order of declarations matters
        std::unique_ptr<LveDescriptorPool> globalPool{};
        LveGameObject::Map gameObjects;
        float MAX_FRAME_TIME = 2.0f;
        
    };
}

#endif /* first_app_hpp */
