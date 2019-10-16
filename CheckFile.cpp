#include "CheckFile.h"
#include "FileIO.h"

using namespace std;

//constructor for checkfile
//gets the content from the given file
CheckFile::CheckFile(std::string fname)
{
    FileIO *file = new FileIO(fname);
    if(file->success)
    {
        content = file->content;
        lineNum = file->lines;
        lineCount = 1;
    }
    else
    {
        cout << "File not found or opened successfully, Exiting" << endl;
        exit(EXIT_FAILURE);
    }

    Delim = new GenStack<char>(lineNum);
}

//checks to see if the delimiter at the top of the stack is closed by the given delimiter
//if it is not it returns false
bool CheckFile::CheckPair(char c1, char c2)
{
    if( c1 == '{' && c2 == '}' )
    {
        return true;
    }
    else if( c1 == '[' && c2 == ']' )
    {
        return true;
    }
    else if(c1 == '(' && c2 == ')')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//checks to see if the given char is an opening delimiter
bool CheckFile::CheckDiff(char c)
{
    if( c =='{' || c == '[' || c == '(')
    {
        return true;
    }
    return false;
}

//return a character based on a char delimiter given as a parameter
char CheckFile::GetExpected(char c)
{
    if(c == '{')
    {
        return '}';
    }
    else if( c == '[')
    {
        return ']';
    }
    else
    {
        return ')';
    }
}

//Iterates through a string of delimiters in order of their appearance in the program
//checks to see if the delimiters do not match up or if there is any left behind after running
//If there is an error it outputs the location at which it discovered the error as well as what it expected to find and what it did find
bool CheckFile::ErrorCheck()
{
    for(char c: content)
    {
        if(c == '\n')
        {
            ++lineCount;
            continue;
        }
        if(Delim->isEmpty())
        {
            Delim->push(c);
        }
        else if(CheckPair(Delim->peek(), c))
        {
            try
            {
                Delim->pop();
            }
            catch(int e)
            {
                cout << "Trying to remove a value from an empty Stack";
            }
            
        }
        else if(CheckDiff(c))
        {
            Delim->push(c);
        }
        else{
        //if this section of the code is reached the deliminating character is not something that was expected and is an error
            cout << "Error on Line: " << lineCount << endl;
            cout << "Expected: " << GetExpected(Delim->peek()) << " found: " << c << endl;
            return false;
        }
    }
    //check above to make sure that the stack is empty
    //if it is empty that means that there is some deliminating character in the file that does not get closed off
    if(!Delim->isEmpty())
    {
        cout << "Reached File End: " << lineCount << endl;
        cout << "Unclosed Delimitor: " << Delim->peek();
        cout << " Expected: " << GetExpected(Delim->pop()) << endl;
        return false;
    }
    return true;
}

