#pragma once
#include "lve_device.hpp"

#include <vector>
#include <memory>

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
            glm::vec3 normal{};
            glm::vec2 uv{};
            
            static std::vector<VkVertexInputBindingDescription> createBindingDescriptions();
            static std::vector<VkVertexInputAttributeDescription> createAttributeDescriptions();
            
            
            bool operator==(const Vertex& other) const
            {
                return  position == other.position &&
                        color == other.color &&
                        normal == other.normal &&
                        uv == other.uv;
            }
            
            struct HashFunction
            {
                size_t operator()(const Vertex& vert) const
                {
                    uint32_t hashNum = 7;
                    hashNum = hashNum * 31 * vert.position.x;
                    hashNum %= 1000000;
                    hashNum = hashNum * 31 * vert.position.y;
                    hashNum %= 1000000;
                    hashNum = hashNum * 31 * vert.position.z;
                    hashNum %= 1000000;
                    hashNum = hashNum * 31 * vert.color.x;
                    hashNum %= 1000000;
                    hashNum = hashNum * 31 * vert.color.y;
                    hashNum %= 1000000;
                    hashNum = hashNum * 31 * vert.color.z;
                    hashNum %= 1000000;
                    hashNum = hashNum * 31 * vert.normal.x;
                    hashNum %= 1000000;
                    hashNum = hashNum * 31 * vert.normal.y;
                    hashNum %= 1000000;
                    hashNum = hashNum * 31 * vert.normal.z;
                    hashNum %= 1000000;
                    hashNum = hashNum * 31 * vert.uv.x;
                    hashNum %= 1000000;
                    hashNum = hashNum * 31 * vert.uv.y;
                    hashNum %= 1000000;
                  
                  return hashNum;
                }
            };
            
            
        };
        
        struct Builder
        {
            std::vector<Vertex> vertices{};
            std::vector<uint32_t> indices{};
            
            void loadModel(const std::string& filename);
            
        };
        
        LveModel(LveDevice& device, const LveModel::Builder &builder);
        ~LveModel();
        
        LveModel(const LveModel& o) = delete;
        LveModel& operator=(const LveModel& o) = delete;
        
        static std::unique_ptr<LveModel> createModelFromFile(LveDevice& device, const std::string& filepath);
        
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
