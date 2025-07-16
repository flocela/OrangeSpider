#include "SpHeadAnatomy.hpp"

SpHeadAnatomy::SpHeadAnatomy(float height, float radius)
:   _height{height},
    _radius{radius}
{}

float SpHeadAnatomy::getHeight()
{
    return _height;
}

float SpHeadAnatomy::getRadius()
{
    return _radius;
}

bool SpHeadAnatomy::operator== (const SpHeadAnatomy& o) const
{
    if (this == &o)
    {
        return true;
    }
    
    return ( _height == o._height ) &&
           ( _radius == o._radius );
    
}
