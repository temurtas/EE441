#include <iostream>
#include <stdlib.h>

const int MaxStacksize=50;
template <class T>
class Stack // class declaration
{
    private:
        T stacklist[MaxStacksize];
        int top;
    public:
        Stack(void); // constructor to initialize top
        // modification operations
        void Push(const T& item);
        T Pop(void);
        void ClearStack(void);
        T Peek(void) const; // just copy
        // stack state operations
        int StackEmpty(void) const;
        int StackFull(void) const;
};


