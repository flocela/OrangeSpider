#import <XCTest/XCTest.h>
#import "../OrangeSpider/SpLeftLeg.hpp"

#include <iostream>
#include <numbers>

@interface SpLeftLegTest : XCTestCase

@end

@implementation SpLeftLegTest

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {

    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

/* *
    Basic setters and getters are in SpLegTest, the base class
* */



/* * 1.0 Test getting points on leg. * */
- (void)testGetTopLengthTopPoint{
    SpLegAnatomy spLegAnatomy{7.0f, 12.0f, 8.0f};
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};
    
    XCTAssertEqual(glm::vec3(0.0f, 0.0f, 0.0f), spiderLeg.getTopLengthTopPoint());
}

- (void)testGetMidLengthTopPoint{
    SpLegAnatomy spLegAnatomy{7.0f, 12.0f, 8.0f};
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};
    
    float topAngleFromHoriz = (std::numbers::pi_v<float>/2.0f) - 0.34906f;
    
    XCTAssertEqual(
        glm::vec3(
            std::cos(topAngleFromHoriz)*spiderLeg.getTopLength(),
            std::sin(topAngleFromHoriz)*spiderLeg.getTopLength(),
            0.0f),
        spiderLeg.getMidLengthTopPoint()
    );
}

- (void)testGetBotLengthTopPoint{
    SpLegAnatomy spLegAnatomy{7.0f, 12.0f, 8.0f};
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    
    SpLeftLeg sl{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};
    
    float midAngleFromHoriz = 0.52360f - ((std::numbers::pi_v<float>/2.0f) - 0.34906f);
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
    SpLegAnatomy spLegAnatomy{7.0f, 12.0f, 8.0f};
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f};
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    
    SpLeftLeg sl{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};
    
    float botAngleFromHoriz = (std::numbers::pi_v<float> * 2.0f) - ( (0.52360f - ((std::numbers::pi_v<float>/2.0f) - 0.34906f)) + (0.87266f) );
    glm::vec3 botLengthTopPoint = sl.getBotLengthTopPoint();
    
    XCTAssertEqual(
        glm::vec3(
            botLengthTopPoint.x + std::cos(botAngleFromHoriz)*sl.getBotLength(),
            botLengthTopPoint.y + std::sin(botAngleFromHoriz)*sl.getBotLength(),
            0.0f),
        sl.getBotLengthBotPoint()
    );
}
/* *1.0 End test getting points on leg. * */


- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
