#import <XCTest/XCTest.h>
#import "../OrangeSpider/SpHeadAnatomy.hpp"

@interface SpHeadAnatomyTest : XCTestCase

@end

@implementation SpHeadAnatomyTest

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {

    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testGetHeight {
    SpHeadAnatomy spiderHead{12, 33};
    XCTAssertEqual(12.0f, spiderHead.getHeight());
}

- (void)testGetRadius {
    SpHeadAnatomy spiderHead{12, 33};
    XCTAssertEqual(33.0f, spiderHead.getRadius());
}

- (void)testEqualityOperator_1 {
    SpHeadAnatomy spiderHeadA{12, 33};
    SpHeadAnatomy spiderHeadB{12, 33};
    XCTAssertTrue(spiderHeadA == spiderHeadB);
}

- (void)testEqualityOperator_2 {
    SpHeadAnatomy spiderHeadA{12, 33};
    XCTAssertTrue(spiderHeadA == spiderHeadA);
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
