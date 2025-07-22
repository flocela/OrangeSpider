#ifndef SpLeg_hpp
#define SpLeg_hpp

#include "SpLegAnatomy.hpp"
#include "SpLegAngles.hpp"

class SpLeg
{
    public:
    
    SpLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles);
    
    float getTopAngle();
    float getMidAngle();
    float getBotAngle();
    float getTopLength();
    float getMidLength();
    float getBotLength();
    
    
    private:
    
    SpLegAnatomy _spLegAnatomy;
    SpLegAngles  _spLegAngles;

};

#endif /* SpLeg_hpp */
