//
//  SpiderState.cpp
//  OrangeSpider
//
//  Created by Flo Maldonado on 7/21/25.
//

#include "SpiderState.hpp"

SpiderState::SpiderState(
    SpHeadAnatomy spHead,
    float headElevation, // bottom of head.
    SpLeg spLeg0,
    float angle0_r,
    SpLeg spLeg1,
    float angle1_r,
    SpLeg spLeg2,
    float angle2_r,
    SpLeg spLeg3,
    float angle3_r,
    SpLeg spLeg4,
    float angle4_r,
    SpLeg spLeg5,
    float angle5_r,
    SpLeg spLeg6,
    float angle6_r,
    SpLeg spLeg7,
    float angle7_r
)
{
    _legs.push_back(spLeg0);
    _legs.push_back(spLeg1);
    _legs.push_back(spLeg2);
    _legs.push_back(spLeg3);
    _legs.push_back(spLeg4);
    _legs.push_back(spLeg5);
    _legs.push_back(spLeg6);
    _legs.push_back(spLeg7);
}

float SpiderState::getTopLength(int legIndex)
{
    return _legs[legIndex].getTopLength();
}

float SpiderState::getMidLength(int legIndex)
{
    return _legs[legIndex].getMidLength();
}

float SpiderState::getBotLength(int legIndex)
{
    return _legs[legIndex].getBotLength();
}

    
float SpiderState::getTopAngle(int legIndex)
{
    return _legs[legIndex].getTopAngle();
}

float SpiderState::getMidAngle(int legIndex)
{
    return _legs[legIndex].getMidAngle();
}

float SpiderState::getBotAngle(int legIndex)
{
    return _legs[legIndex].getBotAngle();
}

