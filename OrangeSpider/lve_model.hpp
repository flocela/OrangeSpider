#pragma once
#include "lve_device.hpp"
#include <vector>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>


namespace lve
{
    class LveModel
    {
        public:
        
        struct Vertex{
            glm::vec3 position;
            glm::vec3 color;
            static std::vector<VkVertexInputBindingDescription> createBindingDescriptions();
            static std::vector<VkVertexInputAttributeDescription> createAttributeDescriptions();
        };
        
        struct Builder
        {
            std::vector<Vertex> vertices{};
            std::vector<uint32_t> indices{};
        };
        
        LveModel(LveDevice& device, const LveModel::Builder &builder);
        ~LveModel();
        
        LveModel(const LveModel& o) = delete;
        LveModel& operator=(const LveModel& o) = delete;
        
        void bind(VkCommandBuffer commandBuffer);
        void draw(VkCommandBuffer commandBuffer);
        
        private:
        
        void createVertexBuffers(const std::vector<Vertex> &vertices);
        void createIndexBuffers(const std::vector<uint32_t> &indices);
        
        LveDevice&     _lveDevice;
        
        VkBuffer       _vertexBuffer;
        VkDeviceMemory _vertexBufferMemory;
        uint32_t       _vertexCount;
        
        bool hasIndexBuffer = false;
        VkBuffer       _indexBuffer;
        VkDeviceMemory _indexBufferMemory;
        uint32_t       _indexCount;
        
    };
}
