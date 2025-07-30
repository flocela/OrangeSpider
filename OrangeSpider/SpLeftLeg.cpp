#include "SpLeftLeg.hpp"
#include <iostream>

#include <numbers>

SpLeftLeg::SpLeftLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles, SpLegAngles minExtension, SpLegAngles maxExtension)
:   SpLeg{spLegAnatomy, spLegAngles, minExtension, maxExtension}
{}

float SpLeftLeg::getTopAngleFromHoriz() const
{
    return (std::numbers::pi_v<float>/2.0f) - _spLegAngles.getConnectionAngle();
}

float SpLeftLeg::getMidAngleFromHoriz() const
{
    return getTopAngleFromHoriz() - _spLegAngles.getMid1Angle();
}

float SpLeftLeg::getBotAngleFromHoriz() const
{   
    return getMidAngleFromHoriz() - _spLegAngles.getMid2Angle();
}
