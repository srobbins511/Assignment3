#include "FileIO.h"


using namespace std;

//file to read from a user given file
FileIO::FileIO(std::string fname)
{
    lines = 0;
    ifstream myFile(fname);
    std::string line = "";
    std::string delimiters = "";
    if(myFile.is_open())
    {
        while(myFile)
            {
                delimiters = "";
                getline(myFile, line);
                for(char c: line)
                {
                    if(c == '[' || c == ']' || c == '{' || c == '}' || c=='(' || c==')')
                    {
                        delimiters += c;
                    }
                }
                content += delimiters + '\n';
                ++lines;
            }
        myFile.close();
    }
    else
    {
        //set the flag bool variable to false
        success = false;
    }
    success = true;
}