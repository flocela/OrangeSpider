#include "SpRightLeg.hpp"

#include <numbers>

SpRightLeg::SpRightLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles)
:   SpLeg(spLegAnatomy, spLegAngles)
{}

float SpRightLeg::getTopAngleFromHoriz()
{
    return (std::numbers::pi_v<float>/2.0f) + _spLegAngles.getTopAngle();
}

float SpRightLeg::getMidAngleFromHoriz()
{
    return getTopAngleFromHoriz() + _spLegAngles.getMidAngle();
}

float SpRightLeg::getBotAngleFromHoriz()
{
    return getMidAngleFromHoriz() + _spLegAngles.getBotAngle();
}
