# Testing Human Detection Algorithm with GMock
[![Build Status](https://travis-ci.org/vijay4313/human-detection.svg?branch=master)](https://travis-ci.org/vijay4313/human-detection)
[![Coverage Status](https://coveralls.io/repos/github/vijay4313/human-detection/badge.svg?branch=master)](https://coveralls.io/github/vijay4313/human-detection?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
---

## Overview

Obstacle/Human detection plays a vital role in field of robotics. Specifically, in the field of autonomous driving, the ability to accurately detect and track humans presents a major barrier to the large scale deployment of service robots in populated environments. This project aims to implement a robust human obstacle detection framework, utilizing 2D LiDAR data and sophisticated object detection algorithms on C++ platform. 
Additionally, this branch, aims at incorporating GMock library for robust testing of the implementation.

## Dependencies
* cmake
* gtest
* gmock

## Standard install via command-line
```
git clone -b GMock_Extra_Credit --single-branch https://github.com/vijay4313/human-detection
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```
## GMock Testing Framework

A virtual dataHandler class, used for import/manipulate LiDAR scan data, is created for the GMock testing. The virtual methods are utilized by the objectDetector class to run classfication algorithms on the LiDAR scans. The ```dataHandlerMock.h``` file consists all the necessary initiations for virtual class. the virtual class is used by the ```objectDetectorTest.cpp``` to verify function calls to the virtual dataHandler class from the objectDetector class.

For more details on GMock, [click here](https://github.com/abseil/googletest/blob/master/googlemock/docs/ForDummies.md).

## Building for code coverage 
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Working with Eclipse IDE

### Installation

In your Eclipse workspace directory (or create a new one), checkout the repo (and submodules)
```
mkdir -p ~/workspace
cd ~/workspace
git clone --recursive https://github.com/vijay4313/human-detection
```

In your work directory, use cmake to create an Eclipse project for an [out-of-source build] of cpp-boilerplate

```
cd ~/workspace
mkdir -p boilerplate-eclipse
cd boilerplate-eclipse
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CMAKE_ECLIPSE_VERSION=4.7.0 -D CMAKE_CXX_COMPILER_ARG1=-std=c++14 ../Project/
```

### Import

Open Eclipse, go to File -> Import -> General -> Existing Projects into Workspace -> 
Select "boilerplate-eclipse" directory created previously as root directory -> Finish

### Edit

Source files may be edited under the "[Source Directory]" label in the Project Explorer.


### Build

To build the project, in Eclipse, unfold boilerplate-eclipse project in Project Explorer,
unfold Build Targets, double click on "all" to build all projects.

### Run

1. In Eclipse, right click on the boilerplate-eclipse in Project Explorer,
select Run As -> Local C/C++ Application

2. Choose the binaries to run (e.g. shell-app, cpp-test for unit testing)



