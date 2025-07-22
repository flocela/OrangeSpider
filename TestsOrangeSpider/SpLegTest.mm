#import <XCTest/XCTest.h>
#import "../OrangeSpider/SpLeg.hpp"
@interface SpLegTest : XCTestCase

@end

@implementation SpLegTest

- (void)setUp {

}

- (void)tearDown {

    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testGetTopAngle {
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeg spiderLeg{spLegAnatomy, spLegAngles};

    XCTAssertEqual(spiderLeg.getTopAngle(), 20);
}

- (void)testGetMidAngle {
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeg spiderLeg{spLegAnatomy, spLegAngles};

    XCTAssertEqual(spiderLeg.getMidAngle(), 30);
}

- (void)testGetBotAngle {
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeg spiderLeg{spLegAnatomy, spLegAngles};

    XCTAssertEqual(spiderLeg.getBotAngle(), 50);
}

- (void)testGetTopLength {
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeg spiderLeg{spLegAnatomy, spLegAngles};

    XCTAssertEqual(spiderLeg.getTopLength(), 7);
}

- (void)testGetMidLength {
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeg spiderLeg{spLegAnatomy, spLegAngles};

    XCTAssertEqual(spiderLeg.getMidLength(), 12);
}

- (void)testGetBotLength {
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    
    SpLeg spiderLeg{spLegAnatomy, spLegAngles};

    XCTAssertEqual(spiderLeg.getBotLength(), 8);
}


- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
