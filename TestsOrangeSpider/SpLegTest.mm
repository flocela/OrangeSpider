#import <XCTest/XCTest.h>
#import "../OrangeSpider/SpLeg.hpp"

#import "../OrangeSpider/SpLeftLeg.hpp"
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

    XCTAssertEqual(spiderLeg.getTopAngle(), 0.34906f);
}

- (void)testGetMidAngle {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f}; // {20, 30, 50 degrees}
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};

    XCTAssertEqual(spiderLeg.getMidAngle(), 0.52360f);
}

- (void)testGetBotAngle {
    SpLegAngles spLegAngles{0.34906f, 0.52360f, 0.87266f}; // {20, 30, 50 degrees}
    SpLegAngles minExtensionAngles{0.17453f, 2.00712f, 1.57080}; // 10, 115, 90
    SpLegAngles maxExtensionAngles{1.30900f, 0.17453f, 0.26180}; // 75, 10, 15
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles, minExtensionAngles, maxExtensionAngles};

    XCTAssertEqual(spiderLeg.getBotAngle(), 0.87266f);
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




/* * 2.0 End: Leg extension lengths. * */

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
