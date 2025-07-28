#include "SpLegAngles.hpp"

SpLegAngles::SpLegAngles(float top_r, float mid_r, float bottom_r)
:   _connectionAngle_r{top_r},
    _mid1Angle_r{mid_r},
    _mid2Angle_r{bottom_r}
{
}

bool SpLegAngles::operator==(const SpLegAngles& o) const
{
    return (_connectionAngle_r == o._connectionAngle_r) &&
           (_mid1Angle_r == o._mid1Angle_r) &&
           (_mid2Angle_r == o._mid2Angle_r);
}

float SpLegAngles::getConnectionAngle()
{
    return _connectionAngle_r;
}

float SpLegAngles::getMid1Angle()
{
    return _mid1Angle_r;
}

float SpLegAngles::getMid2Angle()
{
    return _mid2Angle_r;
}




    
