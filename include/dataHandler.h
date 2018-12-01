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
 *  @file    dataHandler.h
 *  @author  Venkatraman Narayanan (vijay4313)
 *  @date    10/14/2018
 *
 *  @brief	DataHandler class definition
 *
 *  @section DESCRIPTION
 *	Generates the class definition for
 *	DataHandler class necessary for importing
 *	LiDAR scans
 *
 */


#include <vector>
#include <string>

#ifndef INCLUDE_DATAHANDLER_H_
#define INCLUDE_DATAHANDLER_H_

using std::vector;
/*
 * @brief Class to handle importing
 * LiDar scan data to the environment
 */
class dataHandler {
	private:
		vector<double> scans;  // Placeholder for LiDAR scans

	public:
		/*
		 * @brief Default constructor for dataHandler
		 * @param None
		 * @return None
		 */
		dataHandler();

		/*
		 * @brief Default destructor for dataHandler
		 * @param None
		 * @return None
		 */
		virtual ~dataHandler();

		/*
		 * @brief Routine to import data
		 * 		  from given file
		 * @param fileName - The .bin file to
		 * 					 load data from
		 * @return None
		 */
		void importData(const std::string &fileName);

		/*
		 * @brief Routine to extract X-axis pos values
		 * @param None
		 * @return vector of X-axis positions
		 */
		vector<double> genXMat();

		/*
		 * @brief Routine to extract Y-axis pos values
		 * @param None
		 * @return vector of Y-axis positions
		 */
		vector<double> genYMat();

		/*
		 * @brief Routine to extract
		 * 		  reflectance values of LiDAR
	     * @param None
		 * @return vector of reflectance values
		 */
		vector<double> genRMat();
};

#endif // INCLUDE_DATAHANDLER_H_
