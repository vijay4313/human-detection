/**
 *  Copyright 2018 Venkatraman Narayanan
 *  @file    objectDetector.cpp
 *  @author  Venkatraman Narayanan (vijay4313)
 *  @date    10/14/2018
 *
 *  @brief	objectDetector class definition
 *
 *  @section DESCRIPTION
 *	Generates the class definition for
 *	objectDetector class necessary for
 *	identifying Human obstacles
 *	from LiDAR scans
 *
 */

#ifndef APP_OBJECTDETECTOR_H_
#define APP_OBJECTDETECTOR_H_

#include <vector>
#include <map>

class objectDetector {
private:
	std::vector<int> centroidPos;  //Placeholder for cluster centroid positions
	std::vector<double> centroids;  //Placeholder for cluster centroids
	int maxDetects = 5;  //Placeholder for max number of human detections
public:
	/*
	 * @brief Default constructor for objectDetector
	 */
	objectDetector();

	/*
	 * @brief Default destructor for objectDetector
	 */
	virtual ~objectDetector();

	/*
	 * @brief Routine to find clusters
	 * 		  in given data
	 * @param data - The vector of LiDAR
	 * 		         reflectance data
	 */
	void findCluster(const std::vector<double> &data);

	/*
	 * @brief Routine to find Loss (error)
	 * 		  in current centroids
	 * @param v1 - a particular value
	 *             to be checked with all centroids
	 * @return vector of squared distance
	 * 		   from each centroid
	 */
	std::vector<double> getLoss(double &v1);

	/*
	 * @brief Routine to find the location
	 * 		  of the specified cluster
	 * @param data - vector of X/Y positions
	 * @return location of cluster centroids (X/Y axis)
	 */
	std::vector<double> findClusterLoc(const std::vector<double> &data);

};

#endif /* APP_OBJECTDETECTOR_H_ */
