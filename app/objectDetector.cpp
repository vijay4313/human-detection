/**
 *  Copyright 2018 Venkatraman Narayanan
 *  @file    objectDetector.cpp
 *  @author  Venkatraman Narayanan (vijay4313)
 *  @date    10/14/2018
 *
 *  @brief	objectDetector class implementation
 *
 *  @section DESCRIPTION
 *	Generates the class modules for
 *	objectDetector class for
 *	identifying Human obstacles
 *	from LiDAR scans
 *
 */

#include <cstdlib>
#include <algorithm>
#include "objectDetector.h"

/*
 * @brief Default constructor for objectDetector
 */
objectDetector::objectDetector() {
	// constructor stub

}

/*
 * @brief Default destructor for objectDetector
 */
objectDetector::~objectDetector() {
	// destructor stub
}

/*
 * @brief Routine to find clusters
 * 		  in given data
 * @param data - The vector of LiDAR
 * 		         reflectance data
 */
void objectDetector::findCluster(const std::vector<double> &data){
	// Routine to generate random clusters in data
	for(int i = 0; i < maxDetects; i++){
		int val = rand()% data.size();
		centroids.push_back(data[val]);
		centroidPos.push_back(val);
	}

	// Routine to identify the right cluster
	std::map<double,int> assignments;
	for (int i = 0; i<100; i++){
		for (auto j : data){
			auto differences = getLoss(j);
			auto min = *std::min_element(differences.begin(), differences.end());
			assignments[j] = min;
		}
	}
}

/*
 * @brief Routine to find Loss (error)
 * 		  in current centroids
 * @param v1 - a particular value
 *             to be checked with all centroids
 * @return diffVec - vector of squared
 * 				     distance from each centroid
 */
std::vector<double> objectDetector::getLoss(double &v1){
	std::vector<double> diffVec; // Placeholder for loss value
	for (auto &i : centroids){
		double diff = i - v1;
		diffVec.push_back(diff * diff);
	}
	return diffVec;
}

/*
 * @brief Routine to find the location
 * 		  of the specified cluster
 * @param data - vector of X/Y positions
 * @return v - location of cluster centroids (X/Y axis)
 */
std::vector<double> objectDetector::findClusterLoc(const std::vector<double> &data){
	std::vector<double> v;  // Placeholder for cluster location
	for(auto &j : centroidPos){
		v.push_back(data[j]);
	}
	return v;
}
