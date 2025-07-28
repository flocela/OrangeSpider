#ifndef SpLeftLeg_hpp
#define SpLeftLeg_hpp

#include "SpLeg.hpp"

class SpLeftLeg : public SpLeg
{

    public:
    SpLeftLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles);
    //SpLeftLeg() = delete;
    ~SpLeftLeg() = default;
    
    static float getTopAngleFromHz(SpLegAngles spLegAngles);
    static float getMidAngleFromHz(SpLegAngles spLegAngles);
    static float getBotAngleFromHz(SpLegAngles spLegAngles);
    
    protected:
    
    float getTopAngleFromHoriz();
    float getMidAngleFromHoriz();
    float getBotAngleFromHoriz();
    
    private:
    
};




#endif /* SpLeftLeg_hpp */
