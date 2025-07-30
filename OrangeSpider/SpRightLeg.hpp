#ifndef SpRightLeg_hpp
#define SpRightLeg_hpp

#include "SpLeg.hpp"

class SpRightLeg : public SpLeg
{

    public:
    SpRightLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles, SpLegAngles minExtension, SpLegAngles maxExtension);
    //SpLeftLeg() = delete;
    ~SpRightLeg() = default;
    
    protected:
    
    float getTopAngleFromHoriz() const;
    float getMidAngleFromHoriz() const;
    float getBotAngleFromHoriz() const;
    
    private:
    
};

#endif /* SpRightLeg_hpp */
