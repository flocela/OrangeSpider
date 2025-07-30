#import <XCTest/XCTest.h>

#import "../OrangeSpider/SpLegAngles.hpp"

#include <numbers>

@interface SpLegAnglesTest : XCTestCase

@end

@implementation SpLegAnglesTest

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {

    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testConstruct {
    SpLegAngles angles = SpLegAngles::construct(20.0f, 30.0f, 50.0f);
    
    XCTAssertEqualWithAccuracy(20.0f * std::numbers::pi_v<float> / 180.0f, angles.getConnectionAngle(), 0.000001f);
    
    XCTAssertEqualWithAccuracy(30.0f * std::numbers::pi_v<float> / 180.0f, angles.getMid1Angle(), 0.000001f);
    
    XCTAssertEqualWithAccuracy(50.0f * std::numbers::pi_v<float> / 180.0f, angles.getMid2Angle(), 0.000001f);
}


- (void)testGetTopAngle {
    SpLegAngles spiderLeg{20.0f, 30.0f, 50.0f};
    
    XCTAssertEqual(20.0f, spiderLeg.getConnectionAngle());
}

- (void)testGetMidAngle {
    SpLegAngles spiderLeg{20.0f, 30.0f, 50.0f};
    
    XCTAssertEqual(30.0f, spiderLeg.getMid1Angle());
}

- (void)testGetBotAngle {
    SpLegAngles spiderLeg{20.0f, 30.0f, 50.0f};
    
    XCTAssertEqual(50.0f, spiderLeg.getMid2Angle());
}

- (void)testEquality {
    SpLegAngles spiderLegA{20.0f, 30.0f, 50.0f};
    SpLegAngles spiderLegB{20.0f, 30.0f, 50.0f};
    
    XCTAssertTrue(true);
}

- (void)testEqualityOperator_1 {
    SpLegAngles spiderLegA{12, 13, 14};
    SpLegAngles spiderLegB{12, 13, 14};
    XCTAssertTrue(spiderLegA == spiderLegB);
}

- (void)testEqualityOperator_2 {
    SpLegAngles spiderLegA{12, 13, 14};
    XCTAssertTrue(spiderLegA == spiderLegA);
}

- (void)testEqualityOperator_3 {
    SpLegAngles spiderLegA{12, 13, 14};
    SpLegAngles spiderLegB{8, 2, 14};
    
    XCTAssertFalse(spiderLegA == spiderLegB);
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
