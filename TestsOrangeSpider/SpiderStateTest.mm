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

/*
- (void)testGetLengthsAndAngles {
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};
    
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
        legs.push_back(SpLeftLeg{lengths, angles});
    }
    
    SpiderState spiderState{
        SpHeadAnatomy{20, 10},
        50,
        0.25f,
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


- (void)testHeadValues {
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    SpRightLeg spiderLeg{spLegAnatomy, spLegAngles};
    
    float topLength = 10;
    float midLength = 11;
    float botLength = 12;
    
    float topAngle = 0.0f;
    float midAngle = 0.1f;
    float botAngle = 0.2f;
    
    std::vector<std::shared_ptr<SpRightLeg>> legs{};
    for(int ii=0; ii<8; ++ii)
    {
        SpLegAnatomy lengths(topLength + (ii* 3), midLength + (ii*3), botLength + (ii*3));
        SpLegAngles angles(topAngle + (ii * .3f), midAngle + (ii *.3f), botAngle + (ii * .3f));
        //legs.push_back(std::shared_ptr<SpLeftLeg>());
        //SpLeftLeg sp{lengths, angles};
        legs.push_back(std::make_shared<SpRightLeg>(lengths, angles));
    }
    
    float headHeight = 20.0f;
    float headRadius = 10.0f;
    float headElevation = 50.0f;
    
    SpiderState spiderState{
        SpHeadAnatomy{headHeight, headRadius},
        headElevation,
        0.25f,
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
    
   XCTAssertEqual(spiderState.getHeadHeight(), 20.0f);
   XCTAssertEqual(spiderState.getHeadRadius(), 10.0f);
   XCTAssertEqual(spiderState.getTopOfHeadElevation(), 50.0f + 20.0f);
   XCTAssertEqual(spiderState.getMidOfHeadElevation(), 50.0f + 10.0f);
   XCTAssertEqual(spiderState.getBotOfHeadElevation(), 50.0f);
   
}
*/
/*
- (void)testSpiderPoints {
    SpLegAngles spLegAngles{20.0f, 30.0f, 50.0f};
    SpLegAnatomy spLegAnatomy{0.52360f, 1.65806f, 1.09956f}; //degrees: 30, 95, 63
    SpLeg spiderLeg{spLegAnatomy, spLegAngles};
    
    float topLength = 20.0f;
    float midLength = 30.0f;
    float botLength = 50.0f;
    
    float topAngle = 0.52360f;
    float midAngle = 1.65806f;
    float botAngle = 1.09956f;
    
    std::vector<SpLeg> legs{};
    for(int ii=0; ii<8; ++ii)
    {
        SpLegAnatomy lengths(topLength + (ii* 1), midLength + (ii*1), botLength + (ii*1));
        SpLegAngles angles(topAngle + (ii * .1f), midAngle + (ii *.1f), botAngle + (ii * .1f));
        legs.push_back(SpLeg{lengths, angles});
    }
    
    float headHeight = 20.0f;
    float ratioedLegConnectionElevation = 0.25f;
    float headRadius = 10.0f;
    float headElevation = 50.0f;
    
    SpiderState spiderState{
        SpHeadAnatomy{headHeight, headRadius},
        headElevation,
        ratioedLegConnectionElevation,
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
    
    glm::vec3 topLengthTopPoint(
                std::sin(0.87266) * headRadius, 
                headElevation + (headHeight * 0.25f),
                std::cos(0.87266) * headRadius);
                
    glm::vec3 midLengthTopPoint(
                topLengthTopPoint.x + (std::sin(topAngle) * topLength),
                topLengthTopPoint.y + (std::cos(topAngle) * topLength),
                topLengthTopPoint.z);
    
    XCTAssertEqual(spiderState.getElevationBotOfHeadPos(),
                   glm::vec3(0.0f, headElevation, 0.0f));
                   
    XCTAssertEqual(spiderState.getRatioedElevation(0.33333f),
                   glm::vec3(0.0f, (headElevation + (headHeight * 0.33333f)), 0.0f));
    
    XCTAssertEqual(spiderState.getTopLengthTopPoint(0), topLengthTopPoint);
    
    XCTAssertEqual(spiderState.getMidLengthTopPoint(0), midLengthTopPoint);
}
*/





- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
