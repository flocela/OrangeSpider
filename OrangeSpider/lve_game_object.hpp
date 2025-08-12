#pragma once

#include "lve_model.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

namespace lve
{

struct TransformComponent
{
    
    glm::vec3 translation{};
    glm::vec3 scale{1.f, 1.f, 1.f};
    glm::vec3 rotation{};
    
    // Matrix corresponds to translate * Ry * Rx * Rz scale transformation
    // Rotation convention uses tait-bryan angles with axis order Y(1), X(2), Z(3)
    glm::mat4 mat4();
    glm::mat3 normalMatrix();
};

class LveGameObject
{
    public:
    
    using id_t = unsigned int;
    
    static LveGameObject createGameObject()
    {
        static id_t currentId = 0;
        return LveGameObject{currentId++};
    }
    
    LveGameObject(const LveGameObject& o) = delete;
    LveGameObject& operator=(const LveGameObject& o) = delete;
    LveGameObject(LveGameObject&& o) = default;
    LveGameObject& operator=(LveGameObject&& o) = default;
    
    id_t getId()
    {
        return id;
    }
    
    std::shared_ptr<LveModel> model{};
    glm::vec3 color{};
    TransformComponent transform{};
    
    
    private:
    
    LveGameObject(id_t objId) : id{objId}
    {
        
    }
    
    id_t id;
    
};



}
