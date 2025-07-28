#ifndef SpRightLeg_hpp
#define SpRightLeg_hpp

#include "SpLeg.hpp"

class SpRightLeg : public SpLeg
{

    public:
    SpRightLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles);
    //SpLeftLeg() = delete;
    ~SpRightLeg() = default;
    
    static float getTopAngleFromHz(SpLegAngles spLegAngles);
    static float getMidAngleFromHz(SpLegAngles spLegAngles);
    static float getBotAngleFromHz(SpLegAngles spLegAngles);
    
    protected:
    
    float getTopAngleFromHoriz();
    float getMidAngleFromHoriz();
    float getBotAngleFromHoriz();
    
    private:
    
};

#endif /* SpRightLeg_hpp */
