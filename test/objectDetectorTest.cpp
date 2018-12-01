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
 *  @Copyright MIT
 *  @file    objectDetectorTest.cpp
 *  @author  Venkatraman Narayanan (vijay4313)
 *  @date    11/30/2018
 *
 *  @brief Testing module for objectDetector class
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "dataHandler.h"
#include "objectDetector.h"
#include "dataHandlerMock.h"

using ::testing::_;
using ::testing::AtLeast;

TEST(ObjectDetector, InitiationTest) {
  std::string file = "../data/1418381817129923.bin";
  mockDataHandler mockDH;
  EXPECT_CALL(mockDH, importData(_)).Times(AtLeast(1));

  mockDH.importData(file);
  objectDetector myDetector(mockDH);
  myDetector.findCluster();
  std::vector<double> detectX = myDetector.findClusterLocX();
  std::vector<double> detectY = myDetector.findClusterLocY();

  EXPECT_EQ(5, detectX.size());
  EXPECT_EQ(5, detectY.size());
}

