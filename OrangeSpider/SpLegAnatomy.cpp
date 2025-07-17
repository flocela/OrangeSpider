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

bool SpLegAnatomy::operator== (const SpLegAnatomy& o) const
{
    return ( _topLength == o._topLength ) &&
           ( _midLength == o._midLength ) &&
           ( _botLength == o._botLength );
}
