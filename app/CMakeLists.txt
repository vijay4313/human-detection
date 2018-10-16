add_executable(human-detection main.cpp dataHandler.cpp objectDetector.cpp)
PROJECT (human-detection)

find_package(openCV REQUIRED)

INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS} )

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

TARGET_LINK_LIBRARIES (human-detection ${OpenCV_LIBS})
