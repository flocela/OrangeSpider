#ifndef SpLeftLeg_hpp
#define SpLeftLeg_hpp

#include "SpLeg.hpp"

class SpLeftLeg : public SpLeg
{

    public:
    SpLeftLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles);
    //SpLeftLeg() = delete;
    ~SpLeftLeg() = default;
    
    float getTopAngleFromHoriz();
    float getMidAngleFromHoriz();
    float getBotAngleFromHoriz();
    
    protected:
    
    
    
    private:
    


};




#endif /* SpLeftLeg_hpp */
