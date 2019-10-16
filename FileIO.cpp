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
        bool isString = false;
        //The loop iterates through the lines of the file and 
        //only stores the deliminating characters in the string to return
        while(myFile)
            {
                delimiters = "";
                getline(myFile, line);
                for(char c: line)
                {
                    if(!isString && (c == '"' || c == '\'') )
                    {
                        isString = true;
                        continue;
                    }

                    if(isString)
                    {
                        if( c == '"' || c == '\'' )
                        {
                            isString = false;
                        }
                        continue;
                    }
                    //check for deliminating characters
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