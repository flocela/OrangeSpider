#include "SpiderState.hpp"

#include <iostream>
#include <numbers>

SpiderState::SpiderState(
    SpHeadAnatomy spHead,
    float headElevation, // bottom of head.
    float ratioedLegConnectionElevation,
    std::shared_ptr<SpLeg> spLeg0,
    float angle0_r,
    std::shared_ptr<SpLeg> spLeg1,
    float angle1_r,
    std::shared_ptr<SpLeg> spLeg2,
    float angle2_r,
    std::shared_ptr<SpLeg> spLeg3,
    float angle3_r,
    std::shared_ptr<SpLeg> spLeg4,
    float angle4_r,
    std::shared_ptr<SpLeg> spLeg5,
    float angle5_r,
    std::shared_ptr<SpLeg> spLeg6,
    float angle6_r,
    std::shared_ptr<SpLeg> spLeg7,
    float angle7_r
):  _head{spHead},
    _headElevation(headElevation)
{
    _head = spHead;
    _headElevation = headElevation;
    _legConnectionElevation = _headElevation + (_head.getHeight() * ratioedLegConnectionElevation);
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

std::vector<SpLegAngles> static getAcceptableAngles(float topConnectionElevation, SpLegAngles proposedAngles, SpLegAngles proposedMinExtensionAngles, SpLegAngles proposedMaxExtensionAngles);

float SpiderState::getTopLength(int legIndex) const
{
    return _legs[legIndex]->getTopLength();
}

float SpiderState::getMidLength(int legIndex) const
{
    return _legs[legIndex]->getMidLength();
}

float SpiderState::getBotLength(int legIndex) const
{
    return _legs[legIndex]->getBotLength();
}

    
float SpiderState::getTopAngle(int legIndex) const
{
    return _legs[legIndex]->getConnectionAngle();
}

float SpiderState::getMidAngle(int legIndex) const
{
    return _legs[legIndex]->getMid1Angle();
}

float SpiderState::getBotAngle(int legIndex) const
{
    return _legs[legIndex]->getMid2Angle();
}

float SpiderState::getHeadHeight() const
{
    return _head.getHeight();
}

float SpiderState::getHeadRadius() const
{
    return _head.getRadius();
}

float SpiderState::getTopOfHeadElevation() const
{
    return _headElevation + _head.getHeight();
}

float SpiderState::getMidOfHeadElevation() const
{
    return _headElevation + (_head.getHeight()/2.0f);
}

float SpiderState::getBotOfHeadElevation() const
{
    return _headElevation;
}

glm::vec3 SpiderState::getElevationBotOfHeadPos() const
{
    return glm::vec3{0.0f, _headElevation, 0.0f};
}

glm::vec3 SpiderState::getConnectionPoint(uint32_t legIndex) const
{
    return _topLegConnectionPoints[legIndex];
}

glm::vec3 SpiderState::getMid1Point(uint32_t legIndex) const
{
    return _topLegConnectionPoints[legIndex] +_legs[legIndex]->getM1Point();
}

glm::vec3 SpiderState::getMid2Point(uint32_t legIndex) const
{
    return _topLegConnectionPoints[legIndex] +_legs[legIndex]->getM2Point();
}

glm::vec3 SpiderState::getBotPoint(uint32_t legIndex) const
{
    return _topLegConnectionPoints[legIndex] +_legs[legIndex]->getBotPoint();
}

std::vector<glm::vec3> SpiderState::getBottomPointsPerLeg() const
{
    std::vector<glm::vec3> bottomPoints{};
    for(int ii=0; ii<8; ++ii)
    {
        bottomPoints.push_back(getBotPoint(ii));
    }
    return bottomPoints;
}

std::vector<glm::vec3> SpiderState::getConnectionPointPerLeg() const
{
    std::vector<glm::vec3> connectionPoints{};
    for(int ii=0; ii<8; ++ii)
    {
        connectionPoints.push_back(getConnectionPoint(ii));
    }
    return connectionPoints;
}

std::vector<float> SpiderState::getMinExtensionsPerLeg() const
{
    std::vector<float> minExtensions{};
    for(int ii=0; ii<8; ++ii)
    {
        minExtensions.push_back(_legs[ii]->getMinExtension(_legConnectionElevation));
    }
    return minExtensions;
}

std::vector<float> SpiderState::getMaxExtensionsPerLeg() const
{
    std::vector<float> maxExtensions{};
    for(int ii=0; ii<8; ++ii)
    {
        maxExtensions.push_back(_legs[ii]->getMaxExtension(_legConnectionElevation));
    }
    return maxExtensions;
}

/*
std::vector<SpLegAngles> getAcceptableAngles(float topConnectionElevation, SpLegAngles proposedAngles, SpLegAngles proposedMinExtensionAngles, SpLegAngles proposedMaxExtensionAngles)
{
    return std::vector<SpLegAngles>{SpLegAngles{0.0f, 0.0f, 0.0f}, SpLegAngles{0.0f, 0.0f, 0.0f}, SpLegAngles{0.0f, 0.0f, 0.0f}};
}
*/

SpLegAngles SpiderState::getAcceptableAngles(float topConnectionElevation, SpLegAnatomy legAnatomy, SpLegAngles proposedAngles)
{
    glm::vec3 connectionPoint(0.0f, topConnectionElevation, 0.0f);
    
    // proposed angles from horizontal. Horizontal is the positive x direction.
    float pConnectionAngleHoriz = (std::numbers::pi_v<float>/2.0f) - proposedAngles.getConnectionAngle();
    float pM1AngleHoriz = pConnectionAngleHoriz - proposedAngles.getMid1Angle();
    float pM2AngleHoriz = pM1AngleHoriz - proposedAngles.getMid2Angle();
    
    glm::vec3 m1Point(
        connectionPoint.x + cos(pConnectionAngleHoriz) * legAnatomy.getTopLength(),
        connectionPoint.y + sin(pConnectionAngleHoriz) * legAnatomy.getTopLength(),
        0.0f
    );

    glm::vec3 m2Point(
        m1Point.x + cos(pM1AngleHoriz) * legAnatomy.getMidLength(),
        m1Point.y + sin(pM1AngleHoriz) * legAnatomy.getMidLength(),
        0.0f
    );
    
    // Point where bottom of leg will hit zero elevation is x0. Difference between m2Point.x and x0 is xDist;
    float xDist = std::sqrt((legAnatomy.getBotLength() * legAnatomy.getBotLength()) - (m2Point.y * m2Point.y));
    
    float thetaFromVertical = asin(xDist/legAnatomy.getBotLength());
    float maxThetaFromHz = (3.0f/2.0f * std::numbers::pi_v<float>) + thetaFromVertical;
    float minThetaFromHz = (3.0f/2.0f * std::numbers::pi_v<float>) - thetaFromVertical;
    
    float acceptableBottomAngleFromHoriz =
        (std::abs(pM2AngleHoriz - maxThetaFromHz) < std::abs(pM2AngleHoriz - minThetaFromHz)) ?
        (maxThetaFromHz) :
        (minThetaFromHz);
        
    return SpLegAngles{
        proposedAngles.getConnectionAngle(),
        proposedAngles.getMid1Angle(),
        pM1AngleHoriz - acceptableBottomAngleFromHoriz
        };
}

