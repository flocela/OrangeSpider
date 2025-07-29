#include "SpLeg.hpp"

#include <iostream>
#include <numbers>

SpLeg::SpLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles, SpLegAngles minExtension, SpLegAngles maxExtension)
:   _spLegAnatomy{spLegAnatomy},
    _spLegAngles{spLegAngles},
    _minExtensionAngles{minExtension},
    _maxExtensionAngles{maxExtension}
{
    
}
    
float SpLeg::getConnectionAngle()
{
    return _spLegAngles.getConnectionAngle();
}

float SpLeg::getMid1Angle()
{
    return _spLegAngles.getMid1Angle();
}

float SpLeg::getMid2Angle()
{
    return _spLegAngles.getMid2Angle();
}


float SpLeg::getTopLength()
{
    return _spLegAnatomy.getTopLength();
}

float SpLeg::getMidLength()
{
    return _spLegAnatomy.getMidLength();
}

float SpLeg::getBotLength()
{
    return _spLegAnatomy.getBotLength();
}

glm::vec3 SpLeg::getConnectionPoint()
{
    return glm::vec3{
        0.0f,
        0.0f,
        0.0f
    };
}

glm::vec3 SpLeg::getM1Point()
{
    glm::vec3 topPoint {0.0f, 0.0f, 0.0f};
    
    return glm::vec3{
        topPoint.x + cos(getTopAngleFromHoriz()) * _spLegAnatomy.getTopLength(),
        topPoint.y + sin(getTopAngleFromHoriz()) * _spLegAnatomy.getTopLength(),
        topPoint.z + 0.0f
    };
}

glm::vec3 SpLeg::getM2Point()
{
    // Mid length top point.
    glm::vec3 mltp = getM1Point();

    return glm::vec3{
        mltp.x + cos(getMidAngleFromHoriz()) * _spLegAnatomy.getMidLength(),
        mltp.y + sin(getMidAngleFromHoriz()) * _spLegAnatomy.getMidLength(),
        mltp.z + 0.0f
    };
}

glm::vec3 SpLeg::getBotPoint()
{
    // Mid length top point.
    glm::vec3 bltp = getM2Point();
    
    return glm::vec3{
        bltp.x + cos(getBotAngleFromHoriz()) * _spLegAnatomy.getBotLength(),
        bltp.y + sin(getBotAngleFromHoriz()) * _spLegAnatomy.getBotLength(),
        bltp.z + 0.0f
    };
}

// This is an absolute value
float SpLeg::getMinExtension(float topConnectionElevation)
{
    // These angles are min extension angles.
    float connectionAngleFromHoriz = (std::numbers::pi_v<float> / 2.0f) - _minExtensionAngles.getConnectionAngle();
    float mid1AngleFromHoriz = connectionAngleFromHoriz - _minExtensionAngles.getMid1Angle();
    float mid2AngleFromHoriz = mid1AngleFromHoriz - _minExtensionAngles.getMid2Angle();

    glm::vec3 mid1Point{
        0.0f + (cos(connectionAngleFromHoriz) * _spLegAnatomy.getTopLength()),
        topConnectionElevation + (sin(connectionAngleFromHoriz) * _spLegAnatomy.getTopLength()),
        0.0f
    };
    
    glm::vec3 mid2Point{
        mid1Point.x + (cos(mid1AngleFromHoriz) * _spLegAnatomy.getMidLength()),
        mid1Point.y + (sin(mid1AngleFromHoriz) * _spLegAnatomy.getMidLength()),
        mid1Point.z + 0.0f
    };
    
    return mid2Point.x - std::sqrt((getBotLength() * getBotLength()) - (mid2Point.y * mid2Point.y));
}

float SpLeg::getMaxExtension(float topConnectionElevation)
{
    // These angles are maxextension angles.
    float connectionAngleFromHoriz = (std::numbers::pi_v<float> / 2.0f) - _maxExtensionAngles.getConnectionAngle();
    float mid1AngleFromHoriz = connectionAngleFromHoriz - _maxExtensionAngles.getMid1Angle();
    float mid2AngleFromHoriz = mid1AngleFromHoriz - _maxExtensionAngles.getMid2Angle();

    glm::vec3 mid1Point{
        0.0f + (cos(connectionAngleFromHoriz) * _spLegAnatomy.getTopLength()),
        topConnectionElevation + (sin(connectionAngleFromHoriz) * _spLegAnatomy.getTopLength()),
        0.0f
    };
    
    glm::vec3 mid2Point{
        mid1Point.x + (cos(mid1AngleFromHoriz) * _spLegAnatomy.getMidLength()),
        mid1Point.y + (sin(mid1AngleFromHoriz) * _spLegAnatomy.getMidLength()),
        mid1Point.z + 0.0f
    };


    return mid2Point.x + std::sqrt((getBotLength() * getBotLength()) - (mid2Point.y * mid2Point.y));
}

bool SpLeg::minExtensionViable(float topConnectionElevation)
{
    return false;
}

bool SpLeg::maxExtensionViable(float topConnectionElevation)
{
    return false;
}
