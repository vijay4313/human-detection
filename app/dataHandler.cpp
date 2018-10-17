/**
 *  Copyright 2018 Venkatraman Narayanan
 *  @file    dataHandler.cpp
 *  @author  Venkatraman Narayanan (vijay4313)
 *  @date    10/14/2018
 *
 *  @brief	DataHandler class implementations
 *
 *  @section DESCRIPTION
 *	Generates the class modules for
 *	DataHandler class necessary for importing
 *	LiDAR scans
 *
 */

#include <iostream>
#include <fstream>
#include <cstdint>
#include <list>
#include <numeric>
#include "dataHandler.h"

/*
 * @brief Default constructor for dataHandler
 */
dataHandler::dataHandler() {
	// constructor stub
}

/*
 * @brief Default destructor for dataHandler
 */
dataHandler::~dataHandler() {
	// destructor stub
}

/*
 * @brief Routine to import data
 * 		  from given file
 * @param fileName - The .bin file to
 * 					 load data from
 */
void dataHandler::importData(std::string &fileName) {
	std::ifstream file(fileName, std::ios::in|std::ios::binary|std::ios::ate);

	auto size = file.tellg();

	auto memblock = new char[size];
	file.seekg(0, std::ios::beg);
	file.read(memblock, size);
	file.close();

	double double_values = reinterpret_cast<double*>(memblock);  // reinterpret as doubles
	vector<double> values(double_values, double_values + (size / sizeof(double)));
	std::copy(values.begin(), values.end(), std::back_inserter(scans));
}

/*
 * @brief Routine to extract X-axis pos values
 * @return xMat - vector of X-axis positions
 */
vector<double> dataHandler::genXMat() {
	vector<double> xMat;  // Placeholder for X-axis pos values

	for(int i = 0; i < scans.size(); i+=3) {
		xMat.push_back(scans[i]);
	}

	return xMat;
}

/*
 * @brief Routine to extract Y-axis pos values
 * @return yMat - vector of Y-axis positions
 */
vector<double> dataHandler::genYMat() {
	vector<double> yMat;  // Placeholder for Y-axis pos values

	for(int i = 1; i < scans.size(); i+=3) {
		yMat.push_back(scans[i]);
	}

	return yMat;
}

/*
 * @brief Routine to extract
 * 		  reflectance values of LiDAR
 * @return rMat - vector of reflectance values
 */
vector<double> dataHandler::genRMat() {
	vector<double> rMat;  // Placeholder for reflectance values

	for(int i = 2; i < scans.size(); i+=3) {
		rMat.push_back(scans[i]);
	}

	return rMat;
}


