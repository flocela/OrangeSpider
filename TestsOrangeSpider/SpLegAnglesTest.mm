#import <XCTest/XCTest.h>
#import "../OrangeSpider/SpLegAngles.hpp"
@interface SpLegAnglesTest : XCTestCase

@end

@implementation SpLegAnglesTest

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {

    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testGetTopAngle {
    SpLegAngles spiderLeg{20.0f, 30.0f, 50.0f};
    
    XCTAssertEqual(20.0f, spiderLeg.getTopAngle());
}

- (void)testGetMidAngle {
    SpLegAngles spiderLeg{20.0f, 30.0f, 50.0f};
    
    XCTAssertEqual(30.0f, spiderLeg.getMidAngle());
}

- (void)testGetBotAngle {
    SpLegAngles spiderLeg{20.0f, 30.0f, 50.0f};
    
    XCTAssertEqual(50.0f, spiderLeg.getBotAngle());
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
