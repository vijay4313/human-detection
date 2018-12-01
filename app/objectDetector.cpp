/*
 * MIT License
 *
 * Copyright (c) 2018 Venkatraman Narayanan
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall
 * be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */


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
 * @param - dataHandler object
 * @return - None
 */
objectDetector::objectDetector(dataHandler &_dataIn) : helper(_dataIn) {
	helper.importData("../data/1418381817129923.bin");
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
void objectDetector::findCluster() {
	// Routine to generate random clusters in data
	auto data = helper.genRMat();
	for(int i = 0; i < maxDetects; i++) {
		int val = rand()% data.size();
		centroids.push_back(data[val]);
		centroidPos.push_back(val);
	}

	// Routine to identify the right cluster
	std::map<double, int> assignments;
	for (int i = 0; i < 100; i++) {
		for (auto j : data) {
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
std::vector<double> objectDetector::getLoss(const double &v1) {
	std::vector<double> diffVec;  // Placeholder for loss value
	for (auto &i : centroids) {
		double diff = i - v1;
		diffVec.push_back(diff * diff);
	}
	return diffVec;
}

/*
 * @brief Routine to find the location
 * 		  of the specified cluster
 * @param data - vector of X positions
 * @return v - location of cluster centroids (X axis)
 */
std::vector<double> objectDetector::findClusterLocX() {
	std::vector<double> v;  // Placeholder for cluster location
	auto data = helper.genXMat();
	for(auto &j : centroidPos) {
		v.push_back(data[j]);
	}
	return v;
}

/*
 * @brief Routine to find the location
 * 		  of the specified cluster
 * @param data - vector of Y positions
 * @return v - location of cluster centroids (Y axis)
 */
std::vector<double> objectDetector::findClusterLocY() {
	std::vector<double> v;  // Placeholder for cluster location
	auto data = helper.genYMat();
	for(auto &j : centroidPos) {
		v.push_back(data[j]);
	}
	return v;
}
