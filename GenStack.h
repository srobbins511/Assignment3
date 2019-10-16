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
        T pop();
        T peek();

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
    size = maxSize;
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
        T *temp = new T[size*2];
        for(int i = 0; i < size; ++i)
        {
            temp[i] = myArray[i];
        }
        size = size*2;
        T *temp2 = myArray;
        myArray = temp;
        temp = NULL;
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
        throw -1;
    }
    return myArray[top--];
}

template<typename T>
T GenStack<T>::peek()
{
    //error chacking, make sure isEmpty
    if(isEmpty())
    {
        throw -1;
    }
    return myArray[top];
}

template<typename T>
bool GenStack<T>::isFull()
{
    //error chacking, make sure full
    if(top==size-1)
    {
        return true;
    }
    return false;
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



