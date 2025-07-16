#import <XCTest/XCTest.h>
#import "../OrangeSpider/SpLegAnatomy.hpp"

@interface SpLegAnatomyTest : XCTestCase

@end

@implementation SpLegAnatomyTest

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {

    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testGetTopLength {
    SpLegAnatomy spiderLeg{7.0f, 12.0f, 8.0f};
    
    XCTAssertEqual(7.0f, spiderLeg.getTopLength());
}

- (void)testGetMidLength {
    SpLegAnatomy spiderLeg{7.0f, 12.0f, 8.0f};
    
    XCTAssertEqual(12.0f, spiderLeg.getMidLength());
}

- (void)testGetBotLength {
    SpLegAnatomy spiderLeg{7.0f, 12.0f, 8.0f};
    
    XCTAssertEqual(8.0f, spiderLeg.getBotLength());
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
