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

#ifndef APP_DATAHANDLER_H_
#define APP_DATAHANDLER_H_

using std::vector;

class dataHandler {
private:
	vector<double> scans;  //Placeholder for LiDAR scans
public:
	/*
	 * @brief Default constructor for dataHandler
	 */
	dataHandler();

	/*
	 * @brief Default destructor for dataHandler
	 */
	virtual ~dataHandler();

	/*
	 * @brief Routine to import data
	 * 		  from given file
	 * @param fileName - The .bin file to
	 * 					 load data from
	 */
	void importData(std::string &fileName);

	/*
	 * @brief Routine to extract X-axis pos values
	 * @return vector of X-axis positions
	 */
	vector<double> genXMat();

	/*
	 * @brief Routine to extract Y-axis pos values
	 * @return vector of Y-axis positions
	 */
	vector<double> genYMat();

	/*
	 * @brief Routine to extract
	 * 		  reflectance values of LiDAR
	 * @return vector of reflectance values
	 */
	vector<double> genRMat();
};

#endif /* APP_DATAHANDLER_H_ */
