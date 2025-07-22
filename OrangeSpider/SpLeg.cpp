#include "SpLeg.hpp"

SpLeg::SpLeg(SpLegAnatomy spLegAnatomy, SpLegAngles spLegAngles)
:   _spLegAnatomy{spLegAnatomy},
    _spLegAngles{spLegAngles}
{}
    
float SpLeg::getTopAngle()
{
    return _spLegAngles.getTopAngle();
}

float SpLeg::getMidAngle()
{
    return _spLegAngles.getMidAngle();
}

float SpLeg::getBotAngle()
{
    return _spLegAngles.getBotAngle();
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

