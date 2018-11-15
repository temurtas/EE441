# include "Stack.h"
using namespace std;

template <class T> // now implementation of methods
    void  Stack<T>::Push(const T& item) // push
    {
        if (top==MaxStacksize-1) // cannot push if stack exceeded its limit
        {
            cerr<<"Stack overflow"<<endl;
            exit(1);
        }
        top++; // increment top ptr and copy item into list
        stacklist[top]=item;
    }
    template <class T> // now implementation of methods
    T Stack<T>::Pop(void) // pop
    {
        T temp;
        if (top==-1) // cannot pop anything if stack empty
        {
            cerr<<"Stack empty"<<endl;
            exit(1);
        }
        temp=stacklist[top]; // record the top element and decrement top
        top--;
        return temp;
    }
