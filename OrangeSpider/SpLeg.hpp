#ifndef SpLeg_hpp
#define SpLeg_hpp

#include "SpLegAnatomy.hpp"
#include "SpLegAngles.hpp"

#include <glm/glm.hpp>

class SpLeg
{
    public:
    
    SpLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles, SpLegAngles minExtension, SpLegAngles maxExtension);
    virtual ~SpLeg() = default;
    
    float getTopAngle();
    float getMidAngle();
    float getBotAngle();
    float getTopLength();
    float getMidLength();
    float getBotLength();

    // Top length top point is always {0, 0, 0}.
    // It's the origin for the leg. So all other points
    // are from this origin.
    glm::vec3 getTopLengthTopPoint();
    glm::vec3 getMidLengthTopPoint();
    glm::vec3 getBotLengthTopPoint();
    glm::vec3 getBotLengthBotPoint();
    
    float getMinExtension(float topConnectionElevation);
    float getMaxExtension(float topConnectionElevation);
    bool minExtensionViable(float topConnectionElevation);
    bool maxExtensionViable(float topConnectionElevation);
    
    
    protected:
    
    SpLegAngles _spLegAngles;
    SpLegAngles _minExtensionAngles;
    SpLegAngles _maxExtensionAngles;
    
    
    virtual float getTopAngleFromHoriz() = 0;
    virtual float getMidAngleFromHoriz() = 0;
    virtual float getBotAngleFromHoriz() = 0;
    
    private:
    
    SpLegAnatomy _spLegAnatomy;
   
    
};

#endif /* SpLeg_hpp */
