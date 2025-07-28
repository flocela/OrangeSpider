#include "SpRightLeg.hpp"

#include <numbers>

SpRightLeg::SpRightLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles, SpLegAngles minExtension, SpLegAngles maxExtension)
:   SpLeg(spLegAnatomy, spLegAngles, minExtension, maxExtension)
{}

float SpRightLeg::getTopAngleFromHoriz()
{
    return (std::numbers::pi_v<float>/2.0f) + _spLegAngles.getConnectionAngle();
}

float SpRightLeg::getMidAngleFromHoriz()
{
    return getTopAngleFromHoriz() + _spLegAngles.getMid1Angle();
}

float SpRightLeg::getBotAngleFromHoriz()
{
    return getMidAngleFromHoriz() + _spLegAngles.getMid2Angle();
}
