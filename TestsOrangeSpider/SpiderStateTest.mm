#import <XCTest/XCTest.h>
#import "../OrangeSpider/SpiderState.hpp"
#import "../OrangeSpider/SpLeftLeg.hpp"

#include <vector>
#include <iostream>
#include <memory>

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
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};
    
    float topLength = 10;
    float midLength = 11;
    float botLength = 12;
    
    float topAngle = 0.0f;
    float midAngle = 0.1f;
    float botAngle = 0.2f;
    
    std::vector<std::shared_ptr<SpLeg>> legs{};
    for(int ii=0; ii<8; ++ii)
    {
        SpLegAnatomy lengths(topLength + (ii* 3), midLength + (ii*3), botLength + (ii*3));
        SpLegAngles angles(topAngle + (ii * .3f), midAngle + (ii *.3f), botAngle + (ii * .3f));
        
        if (ii < 4)
        {
            legs.push_back(std::make_shared<SpLeftLeg>(lengths, angles));
        }
        else
        {
            legs.push_back(std::make_shared<SpRightLeg>(lengths, angles));
        }
    }
    
    SpiderState spiderState{
        SpHeadAnatomy{20, 10},
        50, // head elevation
        0.25f,
        legs[0],
        0.87266, //50 deg
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
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};
    
    float topLength = 10;
    float midLength = 11;
    float botLength = 12;
    
    float topAngle = 0.0f;
    float midAngle = 0.1f;
    float botAngle = 0.2f;
    
    std::vector<std::shared_ptr<SpLeg>> legs{};
    for(int ii=0; ii<8; ++ii)
    {
        SpLegAnatomy lengths(topLength + (ii* 3), midLength + (ii*3), botLength + (ii*3));
        SpLegAngles angles(topAngle + (ii * .3f), midAngle + (ii *.3f), botAngle + (ii * .3f));
        
        if (ii < 4)
        {
            legs.push_back(std::make_shared<SpLeftLeg>(lengths, angles));
        }
        else
        {
            legs.push_back(std::make_shared<SpRightLeg>(lengths, angles));
        }
    }
    
    SpiderState spiderState{
        SpHeadAnatomy{20, 10},
        50, // head elevation
        0.25f,
        legs[0],
        0.87266, //50 deg
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


- (void)testSpiderPoints {
    SpLegAngles spLegAngles{20, 30, 50};
    SpLegAnatomy spLegAnatomy{7, 12, 8};
    SpLeftLeg spiderLeg{spLegAnatomy, spLegAngles};
    
    float topLength = 10;
    float midLength = 11;
    float botLength = 12;
    
    float topAngle = 10.0f;
    float midAngle = 20.1f;
    float botAngle = 30.2f;
    
    float headHeight = 20.0f;
    float headRadius = 10.0f;
    float headElevation = 50.0f;
    float ratioedLegConnectionElevation = 0.25f;
    
    std::vector<std::shared_ptr<SpLeg>> legs{};
    for(int ii=0; ii<8; ++ii)
    {
        SpLegAnatomy lengths(topLength + (ii* 3), midLength + (ii*3), botLength + (ii*3));
        SpLegAngles angles(topAngle + (ii * .3f), midAngle + (ii *.3f), botAngle + (ii * .3f));
        
        if (ii == 0 || ii == 1 || ii == 6 || ii == 7)
        {
            legs.push_back(std::make_shared<SpLeftLeg>(lengths, angles));
        }
        else
        {
            legs.push_back(std::make_shared<SpRightLeg>(lengths, angles));
        }
    }
    
    std::vector<float> legAnglesAboutHead = {
        0.0f,     //0 deg
        0.69813f, //40
        2.44346f, //140
        3.14159f, //180
        3.49065f, //200
        4.01425f, //230
        5.41052f, //310
        5.93411f  //340
    };
    
    SpiderState spiderState{
        SpHeadAnatomy{headHeight, headRadius},
        headElevation,
        ratioedLegConnectionElevation,
        legs[0],
        legAnglesAboutHead[0], //0 deg
        legs[1],
        legAnglesAboutHead[1], //40
        legs[2],
        legAnglesAboutHead[2], //140
        legs[3],
        legAnglesAboutHead[3], //180
        legs[4],
        legAnglesAboutHead[4], //200
        legs[5],
        legAnglesAboutHead[5], //230
        legs[6],
        legAnglesAboutHead[6], //310
        legs[7],
        legAnglesAboutHead[7]  //340
    };
    
    for(int ii=0; ii<legs.size(); ++ii)
    {
        glm::vec3 topLengthTopPoint(
                    std::cos(legAnglesAboutHead[ii]) * headRadius, 
                    headElevation + (headHeight * ratioedLegConnectionElevation),
                    std::sin(legAnglesAboutHead[ii]) * headRadius);
                    
        glm::vec3 midLengthTopPoint(
                    topLengthTopPoint.x + legs[ii]->getMidLengthTopPoint().x,
                    topLengthTopPoint.y + legs[ii]->getMidLengthTopPoint().y,
                    topLengthTopPoint.z + legs[ii]->getMidLengthTopPoint().z);
        
        glm::vec3 botLengthTopPoint(
                    topLengthTopPoint.x + legs[ii]->getBotLengthTopPoint().x,
                    topLengthTopPoint.y + legs[ii]->getBotLengthTopPoint().y,
                    topLengthTopPoint.z + legs[ii]->getBotLengthTopPoint().z);
                    
        glm::vec3 botLengthBotPoint(
                    topLengthTopPoint.x + legs[ii]->getBotLengthBotPoint().x,
                    topLengthTopPoint.y + legs[ii]->getBotLengthBotPoint().y,
                    topLengthTopPoint.z + legs[ii]->getBotLengthBotPoint().z);
        
        XCTAssertEqual(spiderState.getElevationBotOfHeadPos(),
                       glm::vec3(0.0f, headElevation, 0.0f));
        
        XCTAssertEqual(spiderState.getTopLengthTopPoint(ii), topLengthTopPoint);
        
        XCTAssertEqual(spiderState.getMidLengthTopPoint(ii), midLengthTopPoint);
        
        XCTAssertEqual(spiderState.getBotLengthTopPoint(ii), botLengthTopPoint);
        
        XCTAssertEqual(spiderState.getBotLengthBotPoint(ii), botLengthBotPoint);
    }
    
}


- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
