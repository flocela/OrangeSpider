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

    float getTopLength(int legIndex) const;
    float getMidLength(int legIndex) const;
    float getBotLength(int legIndex) const;
    
    float getTopAngle(int legIndex) const;
    float getMidAngle(int legIndex) const;
    float getBotAngle(int legIndex) const;
    
    float getHeadHeight() const;
    float getHeadRadius() const;
    float getTopOfHeadElevation() const;
    float getMidOfHeadElevation() const;
    float getBotOfHeadElevation() const;
    
    std::vector<glm::vec3> getBottomPointsPerLeg() const;
    std::vector<glm::vec3> getConnectionPointPerLeg() const;
    std::vector<float> getMinExtensionsPerLeg() const;
    std::vector<float> getMaxExtensionsPerLeg() const;
    
    
    glm::vec3 getElevationBotOfHeadPos() const;
    
    // Connection point for top of leg to spider head.
    glm::vec3 getConnectionPoint(uint32_t legIndex) const;
    glm::vec3 getMid1Point(uint32_t legIndex) const;
    glm::vec3 getMid2Point(uint32_t legIndex) const;
    glm::vec3 getBotPoint(uint32_t legIndex) const;
    
    private:
        
    SpHeadAnatomy          _head;
    float                  _headElevation = 0.0f;
    float                  _legConnectionElevation;
    std::vector<std::shared_ptr<SpLeg>>     _legs; // TODO should this be shared or unique
    std::vector<float>     _legPolarAngles;
    std::vector<glm::vec3> _topLegConnectionPoints;

};

#endif /* SpiderState_hpp */
