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
 *  @file    dataHandlerMock.h
 *  @author  Venkatraman Narayanan (vijay4313)
 *  @date    11/30/2018
 *
 *  @brief Routine to mock DataHandler class
 */

#ifndef INCLUDE_DATAHANDLERMOCK_H_
#define INCLUDE_DATAHANDLERMOCK_H_

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "dataHandler.h"
#include "objectDetector.h"
#include <vector>
#include <string>

/*
 * @brief Mock class to test ObjectDetector
 */
class mockDataHandler: public dataHandler {
public:
	MOCK_METHOD1(importData, void(std::string &fileName));
	MOCK_METHOD0(genXMat, std::vector<double>());
	MOCK_METHOD0(genYMat, std::vector<double>());
	MOCK_METHOD0(genRMat, std::vector<double>());
};
#endif // INCLUDE_DATAHANDLERMOCK_H_

