#include "SpLeg.hpp"

#include <iostream>

SpLeg::SpLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles)
:   _spLegAnatomy{spLegAnatomy},
    _spLegAngles{spLegAngles}
{}
    
float SpLeg::getTopAngle()
{
    return _spLegAngles.getConnectionAngle();
}

float SpLeg::getMidAngle()
{
    return _spLegAngles.getMid1Angle();
}

float SpLeg::getBotAngle()
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

glm::vec3 SpLeg::getTopLengthTopPoint()
{
    return glm::vec3{
        0.0f,
        0.0f,
        0.0f
    };
}

glm::vec3 SpLeg::getMidLengthTopPoint()
{
    glm::vec3 topPoint {0.0f, 0.0f, 0.0f};
    
    return glm::vec3{
        topPoint.x + cos(getTopAngleFromHoriz()) * _spLegAnatomy.getTopLength(),
        topPoint.y + sin(getTopAngleFromHoriz()) * _spLegAnatomy.getTopLength(),
        topPoint.z + 0.0f
    };
}

glm::vec3 SpLeg::getBotLengthTopPoint()
{
    // Mid length top point.
    glm::vec3 mltp = getMidLengthTopPoint();
    
    return glm::vec3{
        mltp.x + cos(getMidAngleFromHoriz()) * _spLegAnatomy.getMidLength(),
        mltp.y + sin(getMidAngleFromHoriz()) * _spLegAnatomy.getMidLength(),
        mltp.z + 0.0f
    };
}

glm::vec3 SpLeg::getBotLengthBotPoint()
{
    // Mid length top point.
    glm::vec3 bltp = getBotLengthTopPoint();
    
    return glm::vec3{
        bltp.x + cos(getBotAngleFromHoriz()) * _spLegAnatomy.getBotLength(),
        bltp.y + sin(getBotAngleFromHoriz()) * _spLegAnatomy.getBotLength(),
        bltp.z + 0.0f
    };
}
