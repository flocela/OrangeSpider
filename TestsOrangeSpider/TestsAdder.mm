//
//  TestsAdder.m
//  TestsOrangeSpider
//
//  Created by Flo Maldonado on 4/10/25.
//

#import <XCTest/XCTest.h>
#import "../OrangeSpider/Adder.hpp"
@interface TestsAdder : XCTestCase

@end

@implementation TestsAdder

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {

    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testExample {
    Adder adder;
    
    XCTAssertEqual(5, adder.addNumber(2, 2));
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
