#include <gtest/gtest.h>

#include "../include/dataHandler.h"



TEST(dataHandler, InitiationTest) {
	std::string file = "../data/1418381817129923.bin";
	dataHandler* mydata = new dataHandler();
	mydata->importData(file);
	vector<double> xMat = mydata->genXMat();
	vector<double> yMat = mydata->genYMat();
	vector<double> rMat = mydata->genRMat();

	EXPECT_NEAR(500, xMat.size(), 100);
	EXPECT_NEAR(500, yMat.size(), 100);
	EXPECT_NEAR(500, rMat.size(), 100);
}

