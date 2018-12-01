set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    dataHandlerTest.cpp
   # dataHandlerMock.cpp
    objectDetectorTest.cpp
    ../app/dataHandler.cpp
    ../app/objectDetector.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googlemock/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest gmock)
