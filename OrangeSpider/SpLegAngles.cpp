#include "SpLegAngles.hpp"

SpLegAngles::SpLegAngles(float top_r, float mid_r, float bottom_r)
:   _topAngle_r{top_r},
    _midAngle_r{mid_r},
    _botAngle_r{bottom_r}
{
}

float SpLegAngles::getTopAngle()
{
    return _topAngle_r;
}

float SpLegAngles::getMidAngle()
{
    return _midAngle_r;
}

float SpLegAngles::getBotAngle()
{
    return _botAngle_r;
}


    
