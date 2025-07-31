#import <XCTest/XCTest.h>
#import "../OrangeSpider/SpLeg.hpp"

#import "../OrangeSpider/SpLeftLeg.hpp"

#import <iostream>
@interface SpLegTest : XCTestCase

@end

@implementation SpLegTest

- (void)setUp {

}

- (void)tearDown {

    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

/* * 1.0 Test basic setters and getters for leg lengths and angles. * */


- (void)testGetTopAngle {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f}; // {20, 30, 50 degrees}
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};

    XCTAssertEqual(spiderLeg.getConnectionAngle(), 0.34906f);
}

- (void)testGetMidAngle {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f}; // {20, 30, 50 degrees}
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};

    XCTAssertEqual(spiderLeg.getMid1Angle(), 0.52360f);
}

- (void)testGetBotAngle {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f}; // {20, 30, 50 degrees}
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};

    XCTAssertEqual(spiderLeg.getMid2Angle(), 0.87266f);
}

- (void)testGetTopLength {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f}; // {20, 30, 50 degrees}
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};

    XCTAssertEqual(spiderLeg.getTopLength(), 7);
}

- (void)testGetMidLength {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f}; // {20, 30, 50 degrees}
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};

    XCTAssertEqual(spiderLeg.getMidLength(), 12);
}

- (void)testGetBotLength {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f}; // {20, 30, 50 degrees}
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};
    
    XCTAssertEqual(spiderLeg.getBotLength(), 8);
}
/* * 1.0 End: testing basic getters and setters. * */



/* * 2.0 Leg extension lengths. * */
- (void)testGetMinExtensionLengths {
    SpLegAngles spLegAngles{0.0f, 0.0f, 0.0f}; // {dummy angles}
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    SpLegAnatomy spLegAnatomy{7.0f, 12.0f, 8.0f};
    
    float heightAtConnection = 7.0f;
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};
    
    // tempSpiderLeg uses minimum extension angles as its actual angles.
    SpLeftLeg tempSpiderLeg{spLegAnatomy, minExtensionAngles, minExtensionAngles, maxExtensionAngles};
    
    float theta = acos((heightAtConnection + tempSpiderLeg.getM2Point().y)/8.0f); // 8.0f is bottom length
    
    XCTAssertEqualWithAccuracy(
            tempSpiderLeg.getM2Point().x - (8.0f * sin(theta)),
            spiderLeg.getMinExtension(heightAtConnection),
            0.000001f);
}

- (void)testGetMaxExtensionLengths {
    SpLegAngles spLegAngles{10.0f, 0.0f, 0.0f}; // {dummy angles}
    SpLegAngles minExtensionAngles{-10.0f, 0.0f, 0.0f}; 
    SpLegAngles maxExtensionAngles{1.39626, 0.52360f, 0.26180}; // 80, 30, 15
    SpLegAnatomy spLegAnatomy{7.0f, 12.0f, 8.0f};
    
    float heightAtConnection = 7.0f;
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};
    
    // tempSpiderLeg uses maximum extension angles as its actual angles.
    SpLeftLeg tempSpiderLeg{spLegAnatomy, maxExtensionAngles, minExtensionAngles, maxExtensionAngles};
    
    float theta = acos((heightAtConnection + tempSpiderLeg.getM2Point().y)/8.0f); // 8.0f is bottom length
    
    XCTAssertEqualWithAccuracy(
            tempSpiderLeg.getM2Point().x + (8.0f * sin(theta)),
            spiderLeg.getMaxExtension(heightAtConnection),
            0.000001f);
}

/* * 2.0 End: Leg extension lengths. * */


/* * 3.0 Static methods. * */
- (void)testGetPointsGivenLengthsAndAngles {
    SpLegAngles angles = SpLegAngles::construct(20, 30, 50);
    SpLegAnatomy lengths{10.0f, 11.0f, 20.0f};
    
    std::vector<glm::vec3> actualPoints = SpLeg::getPoints(lengths, angles);
    
    glm::vec3 connPt = {0.0f, 0.0f, 0.0f};
    glm::vec3 m1Pt   = {cos(angles.getConnectionAngleFromHorizontal()) * lengths.getTopLength(),
                        sin(angles.getConnectionAngleFromHorizontal()) * lengths.getTopLength(),
                        0.0f};
    glm::vec3 m2Pt   = {m1Pt.x + cos(angles.getMid1AngleFromHorizontal()) * lengths.getMidLength(),
                        m1Pt.y + sin(angles.getMid1AngleFromHorizontal()) * lengths.getMidLength(),
                        0.0f};
    glm::vec3 botPt  = {m2Pt.x + cos(angles.getMid2AngleFromHorizontal()) * lengths.getBotLength(),
                        m2Pt.y + sin(angles.getMid2AngleFromHorizontal()) * lengths.getBotLength(),
                        0.0f};
                        
    XCTAssertEqual(connPt, actualPoints[0]);
    XCTAssertEqual(m1Pt,   actualPoints[1]);
    XCTAssertEqual(m2Pt,   actualPoints[2]);
    XCTAssertEqual(botPt,  actualPoints[3]);
    
}

- (void)testGetPointsGivenLengthsAnglesAndConnectionPoint{
    SpLegAngles angles   = SpLegAngles::construct(20, 30, 50);
    SpLegAnatomy lengths = SpLegAnatomy{10.0f, 11.0f, 20.0f};
    glm::vec3 connPt     = glm::vec3{1.0f, 2.0f, 3.0f};
    
    std::vector<glm::vec3> actualPoints = SpLeg::getPoints(lengths, angles, connPt);
    
    std::vector<glm::vec3> pointsWithOriginConnectionPt = SpLeg::getPoints(lengths, angles, connPt);
    
    glm::vec3 m1Pt   = {connPt.x + cos(angles.getConnectionAngleFromHorizontal()) * lengths.getTopLength(),
                        connPt.y + sin(angles.getConnectionAngleFromHorizontal()) * lengths.getTopLength(),
                        connPt.z + 0.0f};
    glm::vec3 m2Pt   = {m1Pt.x + cos(angles.getMid1AngleFromHorizontal()) * lengths.getMidLength(),
                        m1Pt.y + sin(angles.getMid1AngleFromHorizontal()) * lengths.getMidLength(),
                        m1Pt.z + 0.0f};
    glm::vec3 botPt  = {m2Pt.x + cos(angles.getMid2AngleFromHorizontal()) * lengths.getBotLength(),
                        m2Pt.y + sin(angles.getMid2AngleFromHorizontal()) * lengths.getBotLength(),
                        m2Pt.z + 0.0f};
                        
    XCTAssertEqual(connPt, actualPoints[0]);
    XCTAssertEqual(m1Pt,   actualPoints[1]);
    XCTAssertEqual(m2Pt,   actualPoints[2]);
    XCTAssertEqual(botPt,  actualPoints[3]);
    
}


/* * 3.0 End static methods. * */

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
