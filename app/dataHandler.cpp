/*
 * dataHandler.cpp
 *
 *  Created on: Oct 16, 2018
 *      Author: venkatraman
 */

#include <iostream>
#include <fstream>
#include <cstdint>
#include "dataHandler.h"

dataHandler::dataHandler() {
	// TODO Auto-generated constructor stub
	numFiles = 1;

}

dataHandler::~dataHandler() {
	// TODO Auto-generated destructor stub
}

vector<double> dataHandler::importData(std::string &fileName){

	std::ifstream file(fileName, std::ios::in|std::ios::binary|std::ios::ate);

	//file.unsetf(std::ios::skipws);

	auto size = file.tellg();

	// std::cout << "size=" << size << "\n";

	auto memblock = new char [size];
	file.seekg (0, std::ios::beg);
	file.read (memblock, size);
	file.close();

	std::cout << "the entire file content is in memory \n";
	double* double_values = (double*)memblock;//reinterpret as doubles
	vector<double> values(double_values, double_values + (size / sizeof(double)));
	return values;


}

/*
double dataHandler::genSubSamples(double &subRatio){
	return 1.0;
}

double dataHandler::genSubSamples(double &subRatio){
	return 1.0;
}
*/

