/*
 * dataHandler.cpp
 *
 *  Created on: Oct 16, 2018
 *      Author: venkatraman
 */

#include <iostream>
#include <fstream>
#include <cstdint>
#include <list>
#include <numeric>
#include "dataHandler.h"

dataHandler::dataHandler() {
	// TODO Auto-generated constructor stub

}

dataHandler::~dataHandler() {
	// TODO Auto-generated destructor stub
}

void dataHandler::importData(std::string &fileName){

	std::ifstream file(fileName, std::ios::in|std::ios::binary|std::ios::ate);

	//file.unsetf(std::ios::skipws);

	auto size = file.tellg();

	// std::cout << "size=" << size << "\n";

	auto memblock = new char [size];
	file.seekg (0, std::ios::beg);
	file.read (memblock, size);
	file.close();

	double* double_values = (double*)memblock;//reinterpret as doubles
	vector<double> values(double_values, double_values + (size / sizeof(double)));
	std::copy(values.begin(), values.end(), std::back_inserter(scans));
}


vector<double> dataHandler::genXMat(){
	vector<double> xMat;

	for(int i = 0; i < scans.size(); i+=3){
		xMat.push_back(scans[i]);
	}

	return xMat;
}

vector<double> dataHandler::genYMat(){
	vector<double> yMat;

	for(int i = 1; i < scans.size(); i+=3){
		yMat.push_back(scans[i]);
	}

	return yMat;
}

vector<double> dataHandler::genRMat(){
	vector<double> rMat;

	for(int i = 2; i < scans.size(); i+=3){
		rMat.push_back(scans[i]);
	}

	return rMat;
}

/*
double dataHandler::genSubSamples(double &subRatio){
	return 1.0;
}

double dataHandler::genSubSamples(double &subRatio){
	return 1.0;
}
*/

