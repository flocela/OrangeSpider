#include "SpHeadAnatomy.hpp"

SpHeadAnatomy::SpHeadAnatomy(float height, float radius)
:   _height{height},
    _radius{radius}
{}

float SpHeadAnatomy::getHeight() const
{
    return _height;
}

float SpHeadAnatomy::getRadius() const
{
    return _radius;
}

bool SpHeadAnatomy::operator== (const SpHeadAnatomy& o) const
{
    return ( _height == o._height ) &&
           ( _radius == o._radius );
    
}
