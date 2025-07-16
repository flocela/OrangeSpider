#include "SpLegAnatomy.hpp"

SpLegAnatomy::SpLegAnatomy(float topLength, float midLength, float botLength)
:   _topLength{topLength},
    _midLength{midLength},
    _botLength{botLength}
{
}

float SpLegAnatomy::getTopLength()
{
    return _topLength;
}

float SpLegAnatomy::getMidLength()
{
    return _midLength;
}

float SpLegAnatomy::getBotLength()
{
    return _botLength;
}
