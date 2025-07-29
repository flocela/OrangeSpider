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
    return getTopAngleFromHoriz() - _spLegAngles.getMid1Angle();
}

float SpLeftLeg::getBotAngleFromHoriz()
{   
    return getMidAngleFromHoriz() - _spLegAngles.getMid2Angle();
}
