#include "SpLeftLeg.hpp"
#include <iostream>

#include <numbers>

SpLeftLeg::SpLeftLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles)
:   SpLeg{spLegAnatomy, spLegAngles}
{}

float SpLeftLeg::getTopAngleFromHoriz()
{
    return SpLeftLeg::getTopAngleFromHz(_spLegAngles);
}

float SpLeftLeg::getMidAngleFromHoriz()
{
    return SpLeftLeg::getMidAngleFromHz(_spLegAngles);
}

float SpLeftLeg::getBotAngleFromHoriz()
{   
    return SpLeftLeg::getBotAngleFromHz(_spLegAngles);
}

/*  static methods */
float SpLeftLeg::getTopAngleFromHz(SpLegAngles spLegAngles)
{
    return (std::numbers::pi_v<float>/2.0f) - spLegAngles.getTopAngle();
}

float SpLeftLeg::getMidAngleFromHz(SpLegAngles spLegAngles)
{
    return spLegAngles.getMidAngle() - SpLeftLeg::getTopAngleFromHz(spLegAngles);
}

float SpLeftLeg::getBotAngleFromHz(SpLegAngles spLegAngles)
{
    return (std::numbers::pi_v<float> * 2.0f) - (spLegAngles.getBotAngle() + SpLeftLeg::getMidAngleFromHz(spLegAngles));
}

/* end static methods*/
