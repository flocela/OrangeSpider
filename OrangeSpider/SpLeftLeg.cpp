#include "SpLeftLeg.hpp"
#include <iostream>

#include <numbers>

SpLeftLeg::SpLeftLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles, SpLegAngles minExtension, SpLegAngles maxExtension)
:   SpLeg{spLegAnatomy, spLegAngles, minExtension, maxExtension}
{}

float SpLeftLeg::getTopAngleFromHoriz()
{
    return (std::numbers::pi_v<float>/2.0f) - _spLegAngles.getConnectionAngle();
}

float SpLeftLeg::getMidAngleFromHoriz()
{
    return _spLegAngles.getMid1Angle() - getTopAngleFromHoriz();
}

float SpLeftLeg::getBotAngleFromHoriz()
{   
    return (std::numbers::pi_v<float> * 2.0f) - (_spLegAngles.getMid2Angle() + getMidAngleFromHoriz());
    
}
