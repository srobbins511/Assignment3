#include "CheckFile.h"
#include "FileIO.h"

using namespace std;

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
        //put an exception here for file not found
    }

    Delim = new GenStack<char>(lineNum);
}

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

bool CheckFile::CheckDiff(char c)
{
    if( c =='{' || c == '[' || c == '(')
    {
        return true;
    }
    return false;
}

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
            cout << "Error on Line: " << lineCount << endl;
            cout << "Expected: " << GetExpected(Delim->peek()) << " found: " << c << endl;
            return false;
        }
    }
    if(!Delim->isEmpty())
    {
        cout << "Reached File End: " << lineCount << endl;
        cout << "Unclosed Delimitor: " << Delim->peek();
        cout << " Expected: " << GetExpected(Delim->pop()) << endl;
        return false;
    }
    return true;
}