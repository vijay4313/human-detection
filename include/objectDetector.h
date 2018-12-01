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

#ifndef INCLUDE_OBJECTDETECTOR_H_
#define INCLUDE_OBJECTDETECTOR_H_

#include <vector>
#include <map>
#include <string>
#include "dataHandler.h"

/*
 * @brief ObjectDetector class
 * to identify human/objects in LiDar Scans
 */
class objectDetector {
 private:
  std::vector<int> centroidPos;  // Placeholder for cluster centroid positions
  std::vector<double> centroids;  // Placeholder for cluster centroids
  int maxDetects = 5;  // Placeholder for max number of human detections
  dataHandler &helper;  // Data Helper Routine

 public:
  /*
   * @brief Default constructor for objectDetector
   * @param - dataHandler object
   * @return - None
   */
  explicit objectDetector(dataHandler &_dataIn);
  /*
   * @brief Default destructor for objectDetector
   * @param - None
   * @return - None
   */
  virtual ~objectDetector();

  /*
   * @brief Routine to find clusters
   * 		  in given data
   * @param - None
   * @return - None
   */
  void findCluster();

  /*
   * @brief Routine to find Loss (error)
   * 		  in current centroids
   * @param v1 - a particular value
   *             to be checked with all centroids
   * @return vector of squared distance
   * 		   from each centroid
   */
  std::vector<double> getLoss(const double &v1);

  /*
   * @brief Routine to find the location
   * 		  of the specified cluster
   * @param data - vector of X positions
   * @return location of cluster centroids (X/Y axis)
   */
  std::vector<double> findClusterLocX();

  /*
   * @brief Routine to find the location
   * 		  of the specified cluster
   * @param data - vector of Y positions
   * @return location of cluster centroids (X/Y axis)
   */
  std::vector<double> findClusterLocY();

};

#endif // INCLUDE_OBJECTDETECTOR_H_
