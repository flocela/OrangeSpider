#include "SpLeftLeg.hpp"
#include <iostream>

#include <numbers>

SpLeftLeg::SpLeftLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles)
:   SpLeg{spLegAnatomy, spLegAngles}
{}

float SpLeftLeg::getTopAngleFromHoriz()
{
    return (std::numbers::pi_v<float>/2.0f) - _spLegAngles.getTopAngle();
}

float SpLeftLeg::getMidAngleFromHoriz()
{
    return _spLegAngles.getMidAngle() - getTopAngleFromHoriz();
}

float SpLeftLeg::getBotAngleFromHoriz()
{   
    return (std::numbers::pi_v<float> * 2.0f) - (_spLegAngles.getBotAngle() + getMidAngleFromHoriz());
    
}
