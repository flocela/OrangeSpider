#include "first_app.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#include "keyboard_movement_controller.hpp"
#include "lve_camera.hpp"
#include "simple_render_system.hpp"

#include <stdexcept>
#include <chrono>

namespace lve
{
    FirstApp::FirstApp()
    {
        loadGameObjects();
    }
    
    FirstApp::~FirstApp()
    {}

    void FirstApp::run()
    {
    
        SimpleRenderSystem simpleRenderSystem{lveDevice, lveRenderer.getSwapChainRenderPass()};
        LveCamera camera{};
        
        camera.setViewTarget(glm::vec3(-1.f, -2.f, 2.f), glm::vec3(0.0f, 0.0f, 2.5f));
        auto viewerObject = LveGameObject::createGameObject();
        KeyboardMovementController cameraController{};
        
        auto currentTime = std::chrono::high_resolution_clock::now();
        
        while(!lveWindow.shouldClose())
        {
            glfwPollEvents();
            
            auto newTime = std::chrono::high_resolution_clock::now();
            float frameTime = std::chrono::duration<float, std::chrono::seconds::period>(newTime - currentTime).count();
            currentTime = newTime;
            
            frameTime = glm::min(frameTime, MAX_FRAME_TIME);
            
            cameraController.moveInPlaneXZ(lveWindow.getGLFWwindow(), frameTime, viewerObject);
            camera.setViewYXZ(viewerObject.transform.translation, viewerObject.transform.rotation);    
            
            float aspect = lveRenderer.getAspectRatio();
            camera.setPerspectiveProjection(glm::radians(50.f), aspect, 0.1f, 10.f);
            
            if (auto commandBuffer = lveRenderer.beginFrame())
            {
                lveRenderer.beginSwapChainRenderPass(commandBuffer);
                simpleRenderSystem.renderGameObjects(commandBuffer, gameObjects, camera);
                lveRenderer.endSwapChainRenderPass(commandBuffer);
                lveRenderer.endFrame();
            }
        }

        vkDeviceWaitIdle(lveDevice.device());
    }

    void FirstApp::loadGameObjects()
    {
    
        std::shared_ptr<LveModel> lveModel = LveModel::createModelFromFile(lveDevice, "/Users/flo/LocalDocuments/Projects/VulkanLearning/OrangeSpider/OrangeSpider/models/flat_vase.obj");
            
        auto gameObject = LveGameObject::createGameObject();
        gameObject.model = lveModel;
        gameObject.transform.translation = {0.0f, .5f, 2.5f};
        gameObject.transform.scale = {3.f, 3.f, 3.f};
        
        gameObjects.push_back(std::move(gameObject));
    }

}// namespace lve
