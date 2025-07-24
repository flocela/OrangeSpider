#import <XCTest/XCTest.h>
#import "../OrangeSpider/SpLeftLeg.hpp"

#include <iostream>

@interface SpLeftLegTest : XCTestCase

@end

@implementation SpLeftLegTest

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {

    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testGetTopAngle {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f}; // {20, 30, 50 degrees}
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};

    XCTAssertEqual(spiderLeg.getTopAngle(), 0.34906f);
}

- (void)testGetMidAngle {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};

    XCTAssertEqual(spiderLeg.getMidAngle(), 0.52360f);
}

- (void)testGetBotAngle {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};

    XCTAssertEqual(spiderLeg.getBotAngle(), 0.87266f);
}

- (void)testGetTopLength {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};

    XCTAssertEqual(spiderLeg.getTopLength(), 7);
}

- (void)testGetMidLength {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};

    XCTAssertEqual(spiderLeg.getMidLength(), 12);
}

- (void)testGetBotLength {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};

    XCTAssertEqual(spiderLeg.getBotLength(), 8);
}

- (void)testGetTopAngleFromHoriz{
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};
    
    XCTAssertEqualWithAccuracy(1.22173, spiderLeg.getTopAngleFromHoriz(), 0.000001f);
}

- (void)testGetMidAngleFromHoriz{
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAnatomy spLegAnatomy{7.0f, 12.0f, 8.0f};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};
    
    XCTAssertEqualWithAccuracy(0.52360f - (1.57079f - 0.34906f), spiderLeg.getMidAngleFromHoriz(), 0.000001f);
}

- (void)testGetBotAngleFromHoriz{
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAnatomy spLegAnatomy{7.0f, 12.0f, 8.0f};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};
    
    XCTAssertEqualWithAccuracy(6.28319 - (0.87266f + (0.52360f - (1.57079f - 0.34906f))), spiderLeg.getBotAngleFromHoriz(), 0.000001f);
}

- (void)testGetTopLengthTopPoint{
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAnatomy spLegAnatomy{7.0f, 12.0f, 8.0f};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};
    
    XCTAssertEqual(glm::vec3(0.0f, 0.0f, 0.0f), spiderLeg.getTopLengthTopPoint());
}

- (void)testGetMidLengthTopPoint{
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAnatomy spLegAnatomy{7.0f, 12.0f, 8.0f};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};
    
    float topAngleFromHoriz = spiderLeg.getTopAngleFromHoriz();
    
    XCTAssertEqual(
        glm::vec3(
            std::cos(topAngleFromHoriz)*spiderLeg.getTopLength(),
            std::sin(topAngleFromHoriz)*spiderLeg.getTopLength(),
            0.0f),
        spiderLeg.getMidLengthTopPoint()
    );
}

- (void)testGetBotLengthTopPoint{
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAnatomy spLegAnatomy{7.0f, 12.0f, 8.0f};
    
    // spider leg
    SpLeftLeg sl{spLegAnatomy, spLegAngles};
    
    float midAngleFromHoriz = sl.getMidAngleFromHoriz();
    glm::vec3 midLengthTopPoint = sl.getMidLengthTopPoint();
    
    XCTAssertEqual(
        glm::vec3(
            midLengthTopPoint.x + std::cos(midAngleFromHoriz)*sl.getMidLength(),
            midLengthTopPoint.y + std::sin(midAngleFromHoriz)*sl.getMidLength(),
            0.0f),
        sl.getBotLengthTopPoint()
    );
}


- (void)testGetBotLengthBotPoint{
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAnatomy spLegAnatomy{7.0f, 12.0f, 8.0f};
    
    // spider leg
    SpLeftLeg sl{spLegAnatomy, spLegAngles};
    
    float botAngleFromHoriz = sl.getBotAngleFromHoriz();
    glm::vec3 botLengthTopPoint = sl.getBotLengthTopPoint();
    
    XCTAssertEqual(
        glm::vec3(
            botLengthTopPoint.x + std::cos(botAngleFromHoriz)*sl.getBotLength(),
            botLengthTopPoint.y + std::sin(botAngleFromHoriz)*sl.getBotLength(),
            0.0f),
        sl.getBotLengthBotPoint()
    );
}


- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
