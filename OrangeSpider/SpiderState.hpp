#ifndef SpiderState_hpp
#define SpiderState_hpp

#include "SpLeg.hpp"
#include "SpRightLeg.hpp"
#include "SpHeadAnatomy.hpp"

#include <glm/glm.hpp>

#include <memory>
#include <vector>

class SpiderState
{
    public:
    
    SpiderState(
        SpHeadAnatomy spHead,
        float headElevation, // bottom of head.
        float ratioedLegConnectionElevation,
        std::shared_ptr<SpLeg> spLeg0,
        float angle0_r,
        std::shared_ptr<SpLeg>spLeg1,
        float angle1_r,
        std::shared_ptr<SpLeg> spLeg2,
        float angle2_r,
        std::shared_ptr<SpLeg> spLeg3,
        float angle3_r,
        std::shared_ptr<SpLeg> spLeg4,
        float angle4_r,
        std::shared_ptr<SpLeg> spLeg5,
        float angle5_r,
        std::shared_ptr<SpLeg> spLeg6,
        float angle6_r,
        std::shared_ptr<SpLeg> spLeg7,
        float angle7_r
    );

    float getTopLength(int legIndex);
    float getMidLength(int legIndex);
    float getBotLength(int legIndex);
    
    float getTopAngle(int legIndex);
    float getMidAngle(int legIndex);
    float getBotAngle(int legIndex);
    
    float getHeadHeight();
    float getHeadRadius();
    float getTopOfHeadElevation();
    float getMidOfHeadElevation();
    float getBotOfHeadElevation();
    
    glm::vec3 getElevationBotOfHeadPos();
    
    // Connection point for top of leg to spider head.
    glm::vec3 getConnectionPoint(uint32_t legIndex);
    glm::vec3 getMid1Point(uint32_t legIndex);
    glm::vec3 getMid2Point(uint32_t legIndex);
    glm::vec3 getBotPoint(uint32_t legIndex);
    
    private:
        
    SpHeadAnatomy          _head;
    float                  _headElevation = 0.0f;
    float                  _legConnectionElevation;
    std::vector<std::shared_ptr<SpLeg>>     _legs; // TODO should this be shared or unique
    std::vector<float>     _legPolarAngles;
    std::vector<glm::vec3> _topLegConnectionPoints;

};

#endif /* SpiderState_hpp */
