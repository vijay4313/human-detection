/**
 *  Copyright 2018 Venkatraman Narayanan
 *  @file    dataHandler.h
 *  @author  Venkatraman Narayanan (vijay4313)
 *  @date    10/14/2018
 *
 *  @brief
 *
 *  @section DESCRIPTION
 *
 *
 *
 */


#include <vector>
#include <string>

#ifndef APP_DATAHANDLER_H_
#define APP_DATAHANDLER_H_

using std::vector;

class dataHandler {
private:
	vector<double> scans;
	int numFiles = 1;
public:
	dataHandler();
	virtual ~dataHandler();
	vector<double> importData(std::string &fileName);
//	/*vector<double>*/ double genSubSamples(double &subRatio);
//	/*vector<double>*/ double getiFrame(double &iFrame);
};

#endif /* APP_DATAHANDLER_H_ */
