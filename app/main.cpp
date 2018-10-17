/**
 *  Copyright 2018 Venkatraman Narayanan
 *  @file    main.cpp
 *  @author  Venkatraman Narayanan (vijay4313)
 *  @date    10/14/2018
 *
 *  @brief main routine for human obstacle detection
 */


#include <iostream>
#include <memory>

#include "dataHandler.h"
#include "objectDetector.h"

int main()
{
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

    for (auto i = 0; i < detectX.size(); i++){
    	std::cout << "Obstacle " << i <<" X: "<<detectX[i]<<
    			" Y: "<< detectY[i]<<std::endl;
    }
    return 0;
}
