/*
 * objectDetectorTest.cpp
 *
 *  Created on: Oct 16, 2018
 *      Author: venkatraman
 */

#include <gtest/gtest.h>
#include "../include/dataHandler.h"
#include "../include/objectDetector.h"



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

	EXPECT_EQ(5, xMat.size());
	EXPECT_EQ(5, yMat.size());
	EXPECT_EQ(5, rMat.size());
}



