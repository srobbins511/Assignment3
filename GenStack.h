#include <iostream>

using namespace std;

template<typename T>
class GenStack
{
    public:
        GenStack();
        GenStack(int maxSize);
        ~GenStack();

        void push(T data);
        char pop();
        char peek();

        bool isFull();
        bool isEmpty();

        int size;
        int top;

        T *myArray; 

};

template<typename T>
GenStack<T>::GenStack()
{
    myArray = new T[128];
    size = 128;
    top = -1;
}

template<typename T>
GenStack<T>::GenStack(int maxSize)
{
    myArray = new T[maxSize];
    size = mazSize;
    top = -1;
}

template<typename T>
GenStack<T>::~GenStack()
{
    delete myArray;
}

template<typename T>
void GenStack<T>::push(T data)
{
    if(isFull())
    {
        size = size*2;
        T *temp = new GenStack(size);
        int i = 0;
        foreach(T data: myArray)
        {
            temp[i] = data;
            ++i;
        }
        T *temp2 = myArray;
        myArray = temp;
        delete temp2;
    }
    myArray[++top] = data;
}

template<typename T>
T GenStack<T>::pop()
{
    //error chacking, make sure isEmpty
    if(isEmpty())
    {
        return NULL;
    }
    return myArray[top--];
}

template<typename T>
T GenStack<T>::peek()
{
    //error chacking, make sure isEmpty
    if(isEmpty())
    {
        return NULL;
    }
    return myArray[top];
}

template<typename T>
bool GenStack<T>::isFull()
{
    //error chacking, make sure full
    if(top<size)
    {
        return false;
    }
    return true;
}

template<typename T>
bool GenStack<T>::isEmpty()
{
    //error chacking, make sure full
    if(top<0)
    {
        return true;
    }
    return false;
}



