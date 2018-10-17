/*
 * objectDetector.cpp
 *
 *  Created on: Oct 16, 2018
 *      Author: venkatraman
 */

#include <cstdlib>
#include <algorithm>
#include "objectDetector.h"


objectDetector::objectDetector() {
	// TODO Auto-generated constructor stub

}

objectDetector::~objectDetector() {
	// TODO Auto-generated destructor stub
}

void objectDetector::findCluster(const std::vector<double> &data){
	for(int i = 0; i < maxDetects; i++){
		int val = rand()% data.size();
		centroids.push_back(data[val]);
		centroidPos.push_back(val);
	}
	std::map<double,int> assignments;
	for (int i = 0; i<100; i++){
		for (auto j : data){
			auto differences = getLoss(j);
			auto min = *std::min_element(differences.begin(), differences.end());
			assignments[j] = min;
		}
	}
}


std::vector<double> objectDetector::getLoss(double &v1){
	std::vector<double> diffVec;
	for (auto &i : centroids){
		double diff = i - v1;
		diffVec.push_back(diff * diff);
	}
	return diffVec;
}

std::vector<double> objectDetector::findClusterLoc(const std::vector<double> &data){
	std::vector<double> v;
	for(auto &j : centroidPos){
		v.push_back(data[j]);
	}
	return v;
}
