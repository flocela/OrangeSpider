#ifndef SpLeftLeg_hpp
#define SpLeftLeg_hpp

#include "SpLeg.hpp"

class SpLeftLeg : public SpLeg
{

    public:
    SpLeftLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles, SpLegAngles minExtension, SpLegAngles maxExtension);
    //SpLeftLeg() = delete;
    ~SpLeftLeg() = default;
    
    protected:
    
    float getTopAngleFromHoriz();
    float getMidAngleFromHoriz();
    float getBotAngleFromHoriz();
    
    private:
    
};

#endif /* SpLeftLeg_hpp */
