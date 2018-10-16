#include <iostream>
#include <memory>

#include "dataHandler.h"

int main()
{
    std::string file = "../Data/lms_front/1418381798086398.bin";
    dataHandler* mydata = new dataHandler();
    mydata->importData(file);
    return 0;
}
