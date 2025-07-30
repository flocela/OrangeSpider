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
    
    float getConnectionAngle() const;
    float getMid1Angle() const;
    float getMid2Angle() const;
    float getTopLength() const;
    float getMidLength() const;
    float getBotLength() const;

    // Top length top point is always {0, 0, 0}.
    // It's the origin for the leg. So all other points
    // are from this origin.
    glm::vec3 getConnectionPoint() const;
    glm::vec3 getM1Point() const;
    glm::vec3 getM2Point() const;
    glm::vec3 getBotPoint() const;
    
    float getMinExtension(float topConnectionElevation) const;
    float getMaxExtension(float topConnectionElevation) const;
    bool minExtensionViable(float topConnectionElevation) const;
    bool maxExtensionViable(float topConnectionElevation) const;
    
    
    protected:
    
    SpLegAngles _spLegAngles;
    SpLegAngles _minExtensionAngles;
    SpLegAngles _maxExtensionAngles;
    
    
    virtual float getTopAngleFromHoriz() const = 0;
    virtual float getMidAngleFromHoriz() const = 0;
    virtual float getBotAngleFromHoriz() const = 0;
    
    private:
    
    SpLegAnatomy _spLegAnatomy;
   
};

#endif /* SpLeg_hpp */
