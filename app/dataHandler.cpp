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
 * @return None
 */
void dataHandler::importData(const std::string &fileName) {
  // std::cout << "Fetching File ";
  std::ifstream file(fileName, std::ios::in | std::ios::binary | std::ios::ate);

  auto size = file.tellg();

  auto memblock = new char[size];
  file.seekg(0, std::ios::beg);
  file.read(memblock, size);
  file.close();
  // reinterpret as doubles
  auto double_values = reinterpret_cast<double*>(memblock);
  vector<double> values(double_values, double_values + (size / sizeof(double)));
  std::copy(values.begin(), values.end(), std::back_inserter(scans));
}

/*
 * @brief Routine to extract X-axis pos values
 * @param None
 * @return xMat - vector of X-axis positions
 */
vector<double> dataHandler::genXMat() {
  vector<double> xMat;  // Placeholder for X-axis pos values

  for (unsigned int i = 0; i < scans.size(); i += 3) {
    xMat.push_back(scans[i]);
  }

  return xMat;
}

/*
 * @brief Routine to extract Y-axis pos values
 * @param None
 * @return yMat - vector of Y-axis positions
 */
vector<double> dataHandler::genYMat() {
  vector<double> yMat;  // Placeholder for Y-axis pos values

  for (unsigned int i = 1; i < scans.size(); i += 3) {
    yMat.push_back(scans[i]);
  }

  return yMat;
}

/*
 * @brief Routine to extract
 * 		  reflectance values of LiDAR
 * @param None
 * @return rMat - vector of reflectance values
 */
vector<double> dataHandler::genRMat() {
  vector<double> rMat;  // Placeholder for reflectance values

  for (unsigned int i = 2; i < scans.size(); i += 3) {
    rMat.push_back(scans[i]);
  }

  return rMat;
}

