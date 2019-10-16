#include <iostream>
#include "Genstack.h"


using namespace std;
class CheckFile
{
    public:
        GenStack<char> *Delim;
        int lineNum;
        int lineCount;
        std::string content;

        //constructor
        CheckFile(std::string fname);
        
        //methods
        bool ErrorCheck();
        bool CheckPair(char c1, char c2);
        bool CheckDiff(char c);
        char GetExpected(char c);
};