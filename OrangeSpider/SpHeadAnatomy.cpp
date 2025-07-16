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
