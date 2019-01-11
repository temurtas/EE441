#include "Stack.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
Stack<T>::Stack(void):top(-1)
{}

template <class T>
//Push
void Stack<T>::Push(const T& item)//
{
//can not push if stack has exceeded its limits
if (top==MaxStackSize-1)
{
cerr<<"Stack overflow"<<endl;
exit(1);
}

stacklist[++top] =item;
}

template <class T>
T Stack<T>::Pop(void)
{
T temp;
// is stack empty nothing to pop
if (top==-1)
{ cerr<<"Stack empty"<<endl;
exit(1);
}

return stacklist[top--];
}

template <class T>
void Stack<T>::ClearStack(void)
{
    for(int i=top; i>-1 ; i--)
        stacklist[i]= NULL ;
    top = -1;
}
//
//
template <class T>
T Stack<T>::Peek(void) const
{
    return stacklist[top];
}
//
//T Stack<T>::Pop(void)
template <class T>
int Stack<T>::StackEmpty(void) const
{
    if(top>-1)
        return 1;
    else
        return 0;
}

template <class T>
int Stack<T>::StackFull(void) const
{
    if(top == MaxStackSize-1)
        return 1;
    else
        return 0;
}