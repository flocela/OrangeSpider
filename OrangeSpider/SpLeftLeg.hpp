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
    
    float getTopAngleFromHoriz() const;
    float getMidAngleFromHoriz() const;
    float getBotAngleFromHoriz() const;
    
    private:
    
};

#endif /* SpLeftLeg_hpp */
