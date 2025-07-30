#include "SpRightLeg.hpp"

#include <numbers>

SpRightLeg::SpRightLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles, SpLegAngles minExtension, SpLegAngles maxExtension)
:   SpLeg(spLegAnatomy, spLegAngles, minExtension, maxExtension)
{}

float SpRightLeg::getTopAngleFromHoriz() const
{
    return (std::numbers::pi_v<float>/2.0f) + _spLegAngles.getConnectionAngle();
}

float SpRightLeg::getMidAngleFromHoriz() const
{
    return getTopAngleFromHoriz() + _spLegAngles.getMid1Angle();
}

float SpRightLeg::getBotAngleFromHoriz() const
{
    return getMidAngleFromHoriz() + _spLegAngles.getMid2Angle();
}
