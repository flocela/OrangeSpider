#import <XCTest/XCTest.h>
#import "../OrangeSpider/SpiderState.hpp"
#import "../OrangeSpider/SpLeftLeg.hpp"

#include <vector>
#include <numbers>
#include <iostream>
#include <memory>

@interface SpiderStateTest : XCTestCase

@end

@implementation SpiderStateTest

float halfPi = std::numbers::pi_v<float> / 2.0f;

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {

    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

// TEST METHOD: static SpiderState::getAcceptableAngles(float topConnectionElevation, SpLegAnatomy legAnatomy, SpLegAngles proposedAngles)
// CASE: Where proposed angles result in a bottom point that is too low.
- (void)testGetAcceptableAnglesGivenNonAcceptableAnglesCaseWhereBotTooLow {

    // INPUTS // 
    // Proposed angles are the prAngles.
    SpLegAngles prAngles    = SpLegAngles::construct(10, 140, 60);
    float elevation         = 9.0f;
    SpLegAnatomy legLengths = SpLegAnatomy{7, 12, 8};
    glm::vec3 connectionPoint = glm::vec3{0.0f, elevation, 0.0f};
    
    // TEST METHOD CALL // 
    SpLegAngles acceptableAngles =
        SpiderState::getAcceptableAngles(elevation, legLengths, prAngles);
    
    // Points given leg lengths and acceptable angles.
    std::vector<glm::vec3> acceptablePoints = SpLeg::getPoints(legLengths, acceptableAngles, connectionPoint);
    
    // CALCULATE BOTTOM POINT TO COMPARE TO BOTTOM POINT FROM ACCEPTABLE ANGLES OUTPUT // 
    std::vector<glm::vec3> prPoints = SpLeg::getPoints(legLengths, prAngles, glm::vec3{0.0f, elevation, 0.0f});
    
    // theta is angle from vertical (y axis going down)
    // Determine if theta lies to the left of right of m2 point.
    float theta = acos(prPoints[2].y / legLengths.getBotLength());
    
    // theta lies to the right of m2, then use thetaFromHzMax.
    float thetaFromHzMax = std::numbers::pi_v<float> * 3.0f/2.0f + theta;
    
    // theta lies to the right of m2, then use thetaFromHzMax.
    float thetaFromHzMin = std::numbers::pi_v<float> * 3.0f/2.0f - theta;
    
    float thetaFromHz = 
        ( std::abs(thetaFromHzMax - prAngles.getMid2AngleFromHorizontal()) < std::abs(thetaFromHzMin - prAngles.getMid2AngleFromHorizontal())) ?
        (thetaFromHzMax) :
        (thetaFromHzMin);
    
    std::cout << "T1 thetaFromHz: " << theta << ", " << thetaFromHz << ": " << thetaFromHzMin << ", " << thetaFromHzMax << ", " << (prAngles.getMid1AngleFromHorizontal() - thetaFromHz) << std::endl;
     
    // COMPARE ACCEPTABLE ANGLE AT EACH POINT TO EXPECTED //
    XCTAssertEqualWithAccuracy(
        prAngles.getConnectionAngle(),
        acceptableAngles.getConnectionAngle(),
        0.000001f);
    
    XCTAssertEqualWithAccuracy(
        prAngles.getMid1Angle(),
        acceptableAngles.getMid1Angle(),
        0.000001f);
    
    XCTAssertEqualWithAccuracy(
        prAngles.getMid1AngleFromHorizontal() - thetaFromHz,
        acceptableAngles.getMid2Angle(),
        0.000001f);
    
    // BOTTOM POINT ELEVATION SHOULD BE ZERO //
    XCTAssertEqualWithAccuracy(0.0f, acceptablePoints[3].y, 0.000001f);
    
}

// TEST METHOD: static SpiderState::getAcceptableAngles(float topConnectionElevation, SpLegAnatomy legAnatomy, SpLegAngles proposedAngles)
// CASE: Where proposed angles result in a bottom point that is too high.
- (void)testGetAcceptableAnglesGivenNonAcceptableAnglesCaseWhereBotTooHigh {
    
    // INPUTS // 
    // Proposed angles are the prAngles.
    SpLegAngles prAngles      = SpLegAngles::construct(25, 110, 90);
    SpLegAnatomy lengths      = SpLegAnatomy{7, 12, 8};
    float topConnElevation    = 9.0f;
    glm::vec3 connectionPoint = glm::vec3{0.0f, topConnElevation, 0.0f};
    
    // TEST METHOD CALL //
    SpLegAngles acceptableAngles = SpiderState::getAcceptableAngles(topConnElevation, lengths, prAngles);
    
    // Points given leg lengths and acceptable angles.
    std::vector<glm::vec3> acceptablePoints = SpLeg::getPoints(lengths, acceptableAngles, connectionPoint);
    
    // CALCULATE BOTTOM POINT TO COMPARE TO BOTTOM POINT FROM ACCEPTABLE ANGLES OUTPUT // 
    std::vector<glm::vec3> prPoints = SpLeg::getPoints(lengths, prAngles, connectionPoint);
    
    // theta is angle from vertical (y axis going down)
    // Determine if theta lies to the left of right of m2 point.
    float theta = acos(prPoints[2].y / lengths.getBotLength());
    
    // theta lies to the right of m2, then use thetaFromHzMax.
    float thetaFromHzMax = std::numbers::pi_v<float> * 3.0f/2.0f + theta;
    
    // theta lies to the right of m2, then use thetaFromHzMax.
    float thetaFromHzMin = std::numbers::pi_v<float> * 3.0f/2.0f - theta;

    float thetaFromHz = 
        ( std::abs(thetaFromHzMax - prAngles.getMid2AngleFromHorizontal()) < std::abs(thetaFromHzMin - prAngles.getMid2AngleFromHorizontal())) ?
        (thetaFromHzMax) :
        (thetaFromHzMin);
        
    std::cout << "T2 thetaFromHz: " << theta << ", " << thetaFromHz << ": " << thetaFromHzMin << ", " << thetaFromHzMax << ", " << (prAngles.getMid1AngleFromHorizontal() - thetaFromHz) << std::endl;
     
    // COMPARE ACCEPTABLE ANGLE AT EACH POINT TO EXPECTED //
    XCTAssertEqualWithAccuracy(
        prAngles.getConnectionAngle(),
        acceptableAngles.getConnectionAngle(),
        0.000001f);
    
    XCTAssertEqualWithAccuracy(
        prAngles.getMid1Angle(),
        acceptableAngles.getMid1Angle(),
        0.000001f);
    
    XCTAssertEqualWithAccuracy(
        prAngles.getMid1AngleFromHorizontal() - thetaFromHz,
        acceptableAngles.getMid2Angle(),
        0.000001f);
    
    // BOTTOM POINT ELEVATION SHOULD BE ZERO //
    XCTAssertEqualWithAccuracy(0.0f, acceptablePoints[3].y, 0.000001f);
    
}

- (void)testGetLengthsAndAngles {
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};
    
    float topLength = 10;
    float midLength = 11;
    float botLength = 12;
    
    float topAngle = 0.0f;
    float midAngle = 0.1f;
    float botAngle = 0.2f;
    
    std::vector<std::shared_ptr<SpLeg>> legs{};
    for(int ii=0; ii<8; ++ii)
    {
        SpLegAnatomy lengths(topLength + (ii* 3), midLength + (ii*3), botLength + (ii*3));
        SpLegAngles angles(topAngle + (ii * .3f), midAngle + (ii *.3f), botAngle + (ii * .3f));
        
        if (ii < 4)
        {
            legs.push_back(std::make_shared<SpLeftLeg>(lengths, angles, minExtensionAngles, maxExtensionAngles));
        }
        else
        {
            legs.push_back(std::make_shared<SpRightLeg>(lengths, angles,  minExtensionAngles, maxExtensionAngles));
        }
    }
    
    SpiderState spiderState{
        SpHeadAnatomy{20, 10},
        50, // head elevation
        0.25f,
        legs[0],
        0.87266, //50 deg
        legs[1],
        1.57080, //90
        legs[2],
        1.91986, //110
        legs[3],
        2.44346, //140
        legs[4],
        3.83972, //220
        legs[5],
        4.36332, //250
        legs[6],
        4.71238, //270
        legs[7],
        5.41052  //310
    };
    
    float topTestLength = 10;
    float midTestLength = 11;
    float botTestLength = 12;
    
    float topTestAngle = 0.0f;
    float midTestAngle = 0.1f;
    float botTestAngle = 0.2f;
    
    for(int ii=0; ii<8; ++ii)
    {
        
        XCTAssertEqual(spiderState.getTopLength(ii), topTestLength + (ii * 3));
        XCTAssertEqual(spiderState.getMidLength(ii), midTestLength + (ii * 3));
        XCTAssertEqual(spiderState.getBotLength(ii), botTestLength + (ii * 3));
        XCTAssertEqual(spiderState.getTopAngle(ii), topTestAngle + (ii * .3f));
        XCTAssertEqual(spiderState.getMidAngle(ii), midTestAngle + (ii * .3f));
        XCTAssertEqual(spiderState.getBotAngle(ii), botTestAngle + (ii * .3f));
    }
}

- (void)testHeadValues {
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};
    
    float topLength = 10;
    float midLength = 11;
    float botLength = 12;
    
    float topAngle = 0.0f;
    float midAngle = 0.1f;
    float botAngle = 0.2f;
    
    std::vector<std::shared_ptr<SpLeg>> legs{};
    for(int ii=0; ii<8; ++ii)
    {
        SpLegAnatomy lengths(topLength + (ii* 3), midLength + (ii*3), botLength + (ii*3));
        SpLegAngles angles(topAngle + (ii * .3f), midAngle + (ii *.3f), botAngle + (ii * .3f));
        
        if (ii < 4)
        {
            legs.push_back(std::make_shared<SpLeftLeg>(lengths, angles, minExtensionAngles, maxExtensionAngles));
        }
        else
        {
            legs.push_back(std::make_shared<SpRightLeg>(lengths, angles, minExtensionAngles, maxExtensionAngles));
        }
    }
    
    SpiderState spiderState{
        SpHeadAnatomy{20, 10},
        50, // head elevation
        0.25f,
        legs[0],
        0.87266, //50 deg
        legs[1],
        1.57080, //90
        legs[2],
        1.91986, //110
        legs[3],
        2.44346, //140
        legs[4],
        3.83972, //220
        legs[5],
        4.36332, //250
        legs[6],
        4.71238, //270
        legs[7],
        5.41052  //310
    };
    
   XCTAssertEqual(spiderState.getHeadHeight(), 20.0f);
   XCTAssertEqual(spiderState.getHeadRadius(), 10.0f);
   XCTAssertEqual(spiderState.getTopOfHeadElevation(), 50.0f + 20.0f);
   XCTAssertEqual(spiderState.getMidOfHeadElevation(), 50.0f + 10.0f);
   XCTAssertEqual(spiderState.getBotOfHeadElevation(), 50.0f);
   
}


- (void)testSpiderPoints {
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};
    
    float topLength = 10;
    float midLength = 11;
    float botLength = 12;
    
    float topAngle = 10.0f;
    float midAngle = 20.1f;
    float botAngle = 30.2f;
    
    float headHeight = 20.0f;
    float headRadius = 10.0f;
    float headElevation = 50.0f;
    float ratioedLegConnectionElevation = 0.25f;
    
    std::vector<std::shared_ptr<SpLeg>> legs{};
    for(int ii=0; ii<8; ++ii)
    {
        SpLegAnatomy lengths(topLength + (ii* 3), midLength + (ii*3), botLength + (ii*3));
        SpLegAngles angles(topAngle + (ii * .3f), midAngle + (ii *.3f), botAngle + (ii * .3f));
        
        if (ii == 0 || ii == 1 || ii == 6 || ii == 7)
        {
            legs.push_back(std::make_shared<SpLeftLeg>(lengths, angles, minExtensionAngles, maxExtensionAngles));
        }
        else
        {
            legs.push_back(std::make_shared<SpRightLeg>(lengths, angles, minExtensionAngles, maxExtensionAngles));
        }
    }
    
    std::vector<float> legAnglesAboutHead = {
        0.0f,     //0 deg
        0.69813f, //40
        2.44346f, //140
        3.14159f, //180
        3.49065f, //200
        4.01425f, //230
        5.41052f, //310
        5.93411f  //340
    };
    
    SpiderState spiderState{
        SpHeadAnatomy{headHeight, headRadius},
        headElevation,
        ratioedLegConnectionElevation,
        legs[0],
        legAnglesAboutHead[0], //0 deg
        legs[1],
        legAnglesAboutHead[1], //40
        legs[2],
        legAnglesAboutHead[2], //140
        legs[3],
        legAnglesAboutHead[3], //180
        legs[4],
        legAnglesAboutHead[4], //200
        legs[5],
        legAnglesAboutHead[5], //230
        legs[6],
        legAnglesAboutHead[6], //310
        legs[7],
        legAnglesAboutHead[7]  //340
    };
    
    for(int ii=0; ii<legs.size(); ++ii)
    {
        glm::vec3 topLengthTopPoint(
                    std::sin(legAnglesAboutHead[ii]) * headRadius, 
                    headElevation + (headHeight * ratioedLegConnectionElevation),
                    std::cos(legAnglesAboutHead[ii]) * headRadius);
                    
        glm::vec3 midLengthTopPoint = topLengthTopPoint + legs[ii]->getM1Point();
        
        glm::vec3 botLengthTopPoint = topLengthTopPoint + legs[ii]->getM2Point();
                    
        glm::vec3 botLengthBotPoint = topLengthTopPoint + legs[ii]->getBotPoint();
        
        XCTAssertEqual(spiderState.getElevationBotOfHeadPos(),
                       glm::vec3(0.0f, headElevation, 0.0f));
        
        XCTAssertEqual(spiderState.getConnectionPoint(ii), topLengthTopPoint);
        
        XCTAssertEqual(spiderState.getMid1Point(ii), midLengthTopPoint);
        
        XCTAssertEqual(spiderState.getMid2Point(ii), botLengthTopPoint);
        
        XCTAssertEqual(spiderState.getBotPoint(ii), botLengthBotPoint);
    }
}

- (void)testGetBottomPointsPerLeg {
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    SpLegAngles spLegAngles{0.69813f, 1.74532f, 0.38888f}; //40, 100, 70
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 140, 60
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 50, 10
    
    float headHeight = 3.0f;
    float headRadius = 5.0f;
    float headElevation = 9.227f;
    float ratioedLegConnectionElevation = 0.0f;
    
    std::vector<std::shared_ptr<SpLeg>> legs{};
    for(int ii=0; ii<8; ++ii)
    {
        
        if (ii < 4)
        {
            legs.push_back(std::make_shared<SpLeftLeg>(spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles));
        }
        else
        {
            legs.push_back(std::make_shared<SpRightLeg>(spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles));
        }
    }
    
    std::vector<float> legAnglesAboutHead = {
        0.17453f, //10 deg
        1.04719f, //60
        2.09439f, //120
        2.44346f, //140
        3.83972f, //220
        4.18879f, //240
        5.23598f, //300
        6.10865f  //350
    };
    
    SpiderState spiderState{
        SpHeadAnatomy{headHeight, headRadius},
        headElevation,
        ratioedLegConnectionElevation,
        legs[0],
        legAnglesAboutHead[0], 
        legs[1],
        legAnglesAboutHead[1],
        legs[2],
        legAnglesAboutHead[2],
        legs[3],
        legAnglesAboutHead[3],
        legs[4],
        legAnglesAboutHead[4],
        legs[5],
        legAnglesAboutHead[5],
        legs[6],
        legAnglesAboutHead[6],
        legs[7],
        legAnglesAboutHead[7]
    };
    
    std::vector<glm::vec3> bottomPointsPerLeg = spiderState.getBottomPointsPerLeg();
    
    for(int ii=0; ii<legs.size(); ++ii)
    {
        glm::vec3 connectionPoint(
                    std::sin(legAnglesAboutHead[ii]) * headRadius, 
                    headElevation + (headHeight * ratioedLegConnectionElevation),
                    std::cos(legAnglesAboutHead[ii]) * headRadius);
                    
        glm::vec3 botPoint = connectionPoint + legs[ii]->getBotPoint();
        
        XCTAssertEqual(botPoint, bottomPointsPerLeg[ii]);
        
    }
}


- (void)testGetConnectionPointPerLeg {
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    SpLegAngles spLegAngles{0.69813f, 1.74532f, 0.38888f}; //40, 100, 70
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 140, 60
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 50, 10
    
    float headHeight = 3.0f;
    float headRadius = 5.0f;
    float headElevation = 9.227f;
    float ratioedLegConnectionElevation = 0.0f;
    
    std::vector<std::shared_ptr<SpLeg>> legs{};
    for(int ii=0; ii<8; ++ii)
    {
        
        if (ii < 4)
        {
            legs.push_back(std::make_shared<SpLeftLeg>(spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles));
        }
        else
        {
            legs.push_back(std::make_shared<SpRightLeg>(spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles));
        }
    }
    
    std::vector<float> legAnglesAboutHead = {
        0.17453f, //10 deg
        1.04719f, //60
        2.09439f, //120
        2.44346f, //140
        3.83972f, //220
        4.18879f, //240
        5.23598f, //300
        6.10865f  //350
    };
    
    SpiderState spiderState{
        SpHeadAnatomy{headHeight, headRadius},
        headElevation,
        ratioedLegConnectionElevation,
        legs[0],
        legAnglesAboutHead[0], 
        legs[1],
        legAnglesAboutHead[1],
        legs[2],
        legAnglesAboutHead[2],
        legs[3],
        legAnglesAboutHead[3],
        legs[4],
        legAnglesAboutHead[4],
        legs[5],
        legAnglesAboutHead[5],
        legs[6],
        legAnglesAboutHead[6],
        legs[7],
        legAnglesAboutHead[7]
    };
    
    std::vector<glm::vec3> connectionPointPerLeg = spiderState.getConnectionPointPerLeg();
    
    for(int ii=0; ii<legs.size(); ++ii)
    {
        glm::vec3 connectionPoint(
                    std::sin(legAnglesAboutHead[ii]) * headRadius, 
                    headElevation + (headHeight * ratioedLegConnectionElevation),
                    std::cos(legAnglesAboutHead[ii]) * headRadius);
        
        XCTAssertEqual(connectionPoint, connectionPointPerLeg[ii]);
        
    }
}

- (void)testExtensionLengthsPerLeg {
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    SpLegAngles spLegAngles{0.69813f, 1.74532f, 0.38888f}; //40, 100, 70
    SpLegAngles minExtensionAngles{0.17453f, 2.44346f, 1.04719}; // 10, 140, 60
    SpLegAngles maxExtensionAngles{1.22173f, 0.87266f, 0.17453}; // 70, 50, 10
    
    float headHeight = 3.0f;
    float headRadius = 5.0f;
    float headElevation = 9.227f;
    float ratioedLegConnectionElevation = 0.0f;
    
    std::vector<std::shared_ptr<SpLeg>> legs{};
    for(int ii=0; ii<8; ++ii)
    {
        
        if (ii < 4)
        {
            legs.push_back(std::make_shared<SpLeftLeg>(spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles));
        }
        else
        {
            legs.push_back(std::make_shared<SpRightLeg>(spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles));
        }
    }
    
    std::vector<float> legAnglesAboutHead = {
        0.17453f, //10 deg
        1.04719f, //60
        2.09439f, //120
        2.44346f, //140
        3.83972f, //220
        4.18879f, //240
        5.23598f, //300
        6.10865f  //350
    };
    
    SpiderState spiderState{
        SpHeadAnatomy{headHeight, headRadius},
        headElevation,
        ratioedLegConnectionElevation,
        legs[0],
        legAnglesAboutHead[0], 
        legs[1],
        legAnglesAboutHead[1],
        legs[2],
        legAnglesAboutHead[2],
        legs[3],
        legAnglesAboutHead[3],
        legs[4],
        legAnglesAboutHead[4],
        legs[5],
        legAnglesAboutHead[5],
        legs[6],
        legAnglesAboutHead[6],
        legs[7],
        legAnglesAboutHead[7]
    };
    
    std::vector<float> minExtensions = spiderState.getMinExtensionsPerLeg();
    std::vector<float> maxExtensions = spiderState.getMaxExtensionsPerLeg();
    
    for(int ii=0; ii<legs.size(); ++ii)
    {
        SpLeftLeg genericLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};
        
        XCTAssertEqualWithAccuracy(
            genericLeg.getMinExtension(headElevation),
            minExtensions[ii],
            0.000001f);
    }
    
    for(int ii=0; ii<legs.size(); ++ii)
    {
        SpLeftLeg genericLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};
        
        XCTAssertEqualWithAccuracy(
            genericLeg.getMaxExtension(headElevation),
            maxExtensions[ii],
            0.000001f);
    }
    
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
