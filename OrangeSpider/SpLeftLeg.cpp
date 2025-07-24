#include "SpLeftLeg.hpp"
#include <iostream>

SpLeftLeg::SpLeftLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles)
:   SpLeg{spLegAnatomy, spLegAngles}
{}

float SpLeftLeg::getTopAngleFromHoriz()
{
    return 1.57079f - _spLegAngles.getTopAngle();
    
}

float SpLeftLeg::getMidAngleFromHoriz()
{
    float topAnglePrime = getTopAngleFromHoriz();
    
    return _spLegAngles.getMidAngle() - topAnglePrime;
}

float SpLeftLeg::getBotAngleFromHoriz()
{   
    float midAnglePrime = getMidAngleFromHoriz();
    return 6.28319 - (_spLegAngles.getBotAngle() + midAnglePrime);
}
