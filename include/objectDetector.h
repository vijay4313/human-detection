/*
 * objectDetector.h
 *
 *  Created on: Oct 16, 2018
 *      Author: venkatraman
 */

#ifndef APP_OBJECTDETECTOR_H_
#define APP_OBJECTDETECTOR_H_

#include <vector>
#include <map>

class objectDetector {
private:
	std::vector<int> centroidPos;
	std::vector<double> centroids;
	int maxDetects = 5;
public:
	objectDetector();
	virtual ~objectDetector();
	void findCluster(const std::vector<double> &data);
	std::vector<double> getLoss(double &v1);
	std::vector<double> findClusterLoc(const std::vector<double> &data);

};

#endif /* APP_OBJECTDETECTOR_H_ */
