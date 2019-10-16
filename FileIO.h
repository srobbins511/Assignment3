#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
class FileIO
{
    public:
        //variables
        std::string content;
        int lines;
        bool success;

        //constructor
        FileIO(std::string fname);
};