/**
 *  Copyright 2018 Venkatraman Narayanan
 *  @file    objectDetectorTest.cpp
 *  @author  Venkatraman Narayanan (vijay4313)
 *  @date    10/14/2018
 *
 *  @brief Testing module for objectDetector class
 */


#include <gtest/gtest.h>
#include "dataHandler.h"
#include "objectDetector.h"



TEST(ObjectDetector, InitiationTest) {
    std::string file = "../data/1418381817129923.bin";
    dataHandler* mydata = new dataHandler();
    mydata->importData(file);
    vector<double> xMat = mydata->genXMat();
    vector<double> yMat = mydata->genYMat();
    vector<double> rMat = mydata->genRMat();
    objectDetector* mydetector = new objectDetector();
    mydetector->findCluster(rMat);
    std::vector<double> detectX = mydetector->findClusterLoc(xMat);
    std::vector<double> detectY = mydetector->findClusterLoc(yMat);

	EXPECT_EQ(5, detectX.size());
	EXPECT_EQ(5, detectY.size());
}




