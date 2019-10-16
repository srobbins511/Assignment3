#include <iostream>
#include <fstream>
#include <math.h>
#include "CheckFile.h"

using namespace std;

//main method
int main(int argc, char** argv)
{
    std::string fname = argv[1];
    std::string input = "";
    CheckFile *prgm = new CheckFile(fname);
    while(prgm->ErrorCheck())
    {
        cout << "No Errors found, to submit another file enter: F" << endl;
        cout << "Else to quit enter anything else" << endl;
        cin >> input;
        if(input == "F")
        {
            cout << "Enter the name of the file: " << endl;
            cin >> input;
            CheckFile *temp = prgm;
            prgm = new CheckFile(input);
            delete temp;
        }
        else{
            break;
        }
    }
    delete prgm;
};