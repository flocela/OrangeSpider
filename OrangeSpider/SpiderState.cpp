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
    float ratioedLegConnectionElevation,
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
):  _head{spHead},
    _headElevation(headElevation)
{
    _head = spHead;
    _headElevation = headElevation;
    _legConnectionElevation = _headElevation + (_head.getHeight() * ratioedLegConnectionElevation),
    _legs.push_back(spLeg0);
    _legs.push_back(spLeg1);
    _legs.push_back(spLeg2);
    _legs.push_back(spLeg3);
    _legs.push_back(spLeg4);
    _legs.push_back(spLeg5);
    _legs.push_back(spLeg6);
    _legs.push_back(spLeg7);
    _legPolarAngles.push_back(angle0_r);
    _legPolarAngles.push_back(angle1_r);
    _legPolarAngles.push_back(angle2_r);
    _legPolarAngles.push_back(angle3_r);
    _legPolarAngles.push_back(angle4_r);
    _legPolarAngles.push_back(angle5_r);
    _legPolarAngles.push_back(angle6_r);
    _legPolarAngles.push_back(angle7_r);
    _topLegConnectionPoints.push_back(glm::vec3(std::sin(angle0_r)*spHead.getRadius(), _legConnectionElevation, std::cos(angle0_r)*spHead.getRadius()));
    _topLegConnectionPoints.push_back(glm::vec3(std::sin(angle1_r)*spHead.getRadius(), _legConnectionElevation, std::cos(angle1_r)*spHead.getRadius()));
    _topLegConnectionPoints.push_back(glm::vec3(std::sin(angle2_r)*spHead.getRadius(), _legConnectionElevation, std::cos(angle2_r)*spHead.getRadius()));
    _topLegConnectionPoints.push_back(glm::vec3(std::sin(angle3_r)*spHead.getRadius(), _legConnectionElevation, std::cos(angle3_r)*spHead.getRadius()));
    _topLegConnectionPoints.push_back(glm::vec3(std::sin(angle4_r)*spHead.getRadius(), _legConnectionElevation, std::cos(angle4_r)*spHead.getRadius()));
    _topLegConnectionPoints.push_back(glm::vec3(std::sin(angle5_r)*spHead.getRadius(), _legConnectionElevation, std::cos(angle5_r)*spHead.getRadius()));
    _topLegConnectionPoints.push_back(glm::vec3(std::sin(angle6_r)*spHead.getRadius(), _legConnectionElevation, std::cos(angle6_r)*spHead.getRadius()));
    _topLegConnectionPoints.push_back(glm::vec3(std::sin(angle7_r)*spHead.getRadius(), _legConnectionElevation, std::cos(angle7_r)*spHead.getRadius()));
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

float SpiderState::getHeadHeight()
{
    return _head.getHeight();
}

float SpiderState::getHeadRadius()
{
    return _head.getRadius();
}

float SpiderState::getTopOfHeadElevation()
{
    return _headElevation + _head.getHeight();
}

float SpiderState::getMidOfHeadElevation()
{
    return _headElevation + (_head.getHeight()/2.0f);
}

float SpiderState::getBotOfHeadElevation()
{
    return _headElevation;
}

glm::vec3 SpiderState::getElevationBotOfHeadPos()
{
    return glm::vec3{0.0f, _headElevation, 0.0f};
}

glm::vec3 SpiderState::getRatioedElevation(float portionOfHeadAboveBottom)
{
    return glm::vec3(0.0f, _headElevation + (_head.getHeight() * portionOfHeadAboveBottom), 0.0f);
}

glm::vec3 SpiderState::getTopLengthTopPoint(uint32_t legIndex)
{
    return _topLegConnectionPoints[legIndex];
}

glm::vec3 SpiderState::getMidLengthTopPoint(uint32_t legIndex)
{
    glm::vec3 topLegConnectionPoint = getTopLengthTopPoint(legIndex);
    return glm::vec3(
        topLegConnectionPoint.x + std::sin(_legs[legIndex].getTopAngle()) * _legs[legIndex].getTopLength(),
        topLegConnectionPoint.y + std::cos(_legs[legIndex].getTopAngle()) * _legs[legIndex].getTopLength(),
        topLegConnectionPoint.z
        );
}

glm::vec3 SpiderState::getBotLengthTopPoint(uint32_t legIndex)
{
    return glm::vec3(0.0f, 0.0f, 0.0f);
}

glm::vec3 getBotLengthBotPoint(uint32_t legIndex)
{
    return glm::vec3(0.0f, 0.0f, 0.0f);
}

