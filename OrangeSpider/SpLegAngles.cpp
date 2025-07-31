#include "SpLegAngles.hpp"
#include <numbers>

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

float SpLegAngles::getConnectionAngle() const
{
    return _connectionAngle_r;
}

float SpLegAngles::getMid1Angle() const
{
    return _mid1Angle_r;
}

float SpLegAngles::getMid2Angle() const
{
    SpLegAngles::construct(1.0f, 1.0f, 1.0f);
    return _mid2Angle_r;
}

float SpLegAngles::getConnectionAngleFromHorizontal() const
{
    return (std::numbers::pi_v<float>/2.0f) - _connectionAngle_r;
}

float SpLegAngles::getMid1AngleFromHorizontal() const
{
    return (std::numbers::pi_v<float>/2.0f) - _connectionAngle_r - _mid1Angle_r;
}

float SpLegAngles::getMid2AngleFromHorizontal() const
{
    return (std::numbers::pi_v<float>/2.0f) - _connectionAngle_r - _mid1Angle_r - _mid2Angle_r;
}

SpLegAngles SpLegAngles::construct(float top_d, float mid_d, float bot_d)
{
    return SpLegAngles(top_d * std::numbers::pi_v<float> / 180.0f, mid_d * std::numbers::pi_v<float> / 180.0f, bot_d * std::numbers::pi_v<float> / 180.0f);
}

