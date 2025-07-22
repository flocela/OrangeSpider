#import <XCTest/XCTest.h>
#import "../OrangeSpider/SpiderState.hpp"

#include <vector>
#include <iostream>

@interface SpiderStateTest : XCTestCase

@end

@implementation SpiderStateTest

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {

    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testGetLengthsAndAngles {
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    SpLeg spiderLeg{spLegAnatomy, spLegAngles};
    
    float topLength = 10;
    float midLength = 11;
    float botLength = 12;
    
    float topAngle = 0.0f;
    float midAngle = 0.1f;
    float botAngle = 0.2f;
    
    std::vector<SpLeg> legs{};
    for(int ii=0; ii<8; ++ii)
    {
        SpLegAnatomy lengths(topLength + (ii* 3), midLength + (ii*3), botLength + (ii*3));
        SpLegAngles angles(topAngle + (ii * .3f), midAngle + (ii *.3f), botAngle + (ii * .3f));
        legs.push_back(SpLeg{lengths, angles});
    }
    
    SpiderState spiderState{
        SpHeadAnatomy{20, 10},
        50,
        legs[0],
        0.87266, //50
        legs[1],
        1.57080, //90
        legs[2],
        1.91986, //110
        legs[3],
        2.44346, //140
        legs[4],
        3.83972, //220
        legs[5],
        4.36332, //250
        legs[6],
        4.71238, //270
        legs[7],
        5.41052  //310
    };
    
    float topTestLength = 10;
    float midTestLength = 11;
    float botTestLength = 12;
    
    float topTestAngle = 0.0f;
    float midTestAngle = 0.1f;
    float botTestAngle = 0.2f;
    
    for(int ii=0; ii<8; ++ii)
    {
        
        XCTAssertEqual(spiderState.getTopLength(ii), topTestLength + (ii * 3));
        XCTAssertEqual(spiderState.getMidLength(ii), midTestLength + (ii * 3));
        XCTAssertEqual(spiderState.getBotLength(ii), botTestLength + (ii * 3));
        XCTAssertEqual(spiderState.getTopAngle(ii), topTestAngle + (ii * .3f));
        XCTAssertEqual(spiderState.getMidAngle(ii), midTestAngle + (ii * .3f));
        XCTAssertEqual(spiderState.getBotAngle(ii), botTestAngle + (ii * .3f));
    }
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
