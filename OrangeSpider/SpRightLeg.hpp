#ifndef SpRightLeg_hpp
#define SpRightLeg_hpp

#include "SpLeg.hpp"

class SpRightLeg : public SpLeg
{

    public:
    SpRightLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles);
    //SpLeftLeg() = delete;
    ~SpRightLeg() = default;
    
    protected:
    
    float getTopAngleFromHoriz();
    float getMidAngleFromHoriz();
    float getBotAngleFromHoriz();
    
    private:
    
};

#endif /* SpRightLeg_hpp */
