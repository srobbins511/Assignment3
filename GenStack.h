#include <iostream>

using namespace std;

template<typename T>
class GenStack
{
    public:
    //constructor
        GenStack();
        GenStack(int maxSize);
        ~GenStack();

        //central methods
        void push(T data);
        T pop();
        T peek();

        //support methods
        bool isFull();
        bool isEmpty();

        //data fields
        int size;
        int top;

        T *myArray; 

};

//creates a stack with a defualt value
template<typename T>
GenStack<T>::GenStack()
{
    myArray = new T[128];
    size = 128;
    top = -1;
}

//creates the starting array size for the stack based on a value given
template<typename T>
GenStack<T>::GenStack(int maxSize)
{
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
}

//destructor for the stack class
template<typename T>
GenStack<T>::~GenStack()
{
    delete myArray;
}

//checks to see if the array is full
//if the array is full it creates a new array double the size
//it then sets the pointer of the original array to the new array and deletes the old array
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

//returns a value from the top of the stack
//top is decremented so the value cannot be recovered
//will throw -1 if the stack is empty
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

//returns the value at the top of the stack without decrementing the top
//will throw -1 if the stack is empty
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

//checks to see if the stack is full
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

//checks to see if the stack is empty
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



