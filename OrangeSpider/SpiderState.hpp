#ifndef SpiderState_hpp
#define SpiderState_hpp

#include "SpLeg.hpp"
#include "SpHeadAnatomy.hpp"

#include <memory>
#include <vector>

class SpiderState
{
    public:
    
    SpiderState(
        SpHeadAnatomy spHead,
        float headElevation, // bottom of head.
        SpLeg spLeg0,
        float angle0_r,
        SpLeg spLeg1,
        float angle1_r,
        SpLeg spLeg2,
        float angle2_r,
        SpLeg spLeg3,
        float angle3_r,
        SpLeg spLeg4,
        float angle4_r,
        SpLeg spLeg5,
        float angle5_r,
        SpLeg spLeg6,
        float angle6_r,
        SpLeg spLeg7,
        float angle7_r
    );
    
    float getTopLength(int legIndex);
    float getMidLength(int legIndex);
    float getBotLength(int legIndex);
    
    float getTopAngle(int legIndex);
    float getMidAngle(int legIndex);
    float getBotAngle(int legIndex);
    
    
    
    private:
        
    std::vector<SpLeg> _legs;
    
};

#endif /* SpiderState_hpp */
