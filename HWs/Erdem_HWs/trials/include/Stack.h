#include <iostream>
#include <stdlib.h>

using namespace std;

const int MaxStackSize=50;

template <class T>
class Stack {

    private:
        T stacklist[MaxStackSize];
        int top;

    public:
        // constructor to initialize top
        Stack(void) {
            top = -1;
        }

        //modification operations
        void Push(const T& item) {
            //can not push if stack has exceeded its limits
            if (top==MaxStackSize-1) {
                cerr<<"Stack overflow"<<endl;
                exit(1);
            }

            stacklist[++top] = item;
        }

        T Pop(void) {
            T temp;
            // is stack empty nothing to pop
            if (top==-1) {
                cerr<<"Stack empty"<<endl;
                exit(1);
            }
            return stacklist[top--];
        }

        void ClearStack(void) {
            for(int i=top; i>-1 ; i--)
                stacklist[i]= NULL ; // equates elements to NULL (not necessary)
            top = -1;
        }

        //just copy top item without modifying stack contents
        T Peek(void) const {
            return stacklist[top];
        }

        //returns true if the stack is empty
        int StackEmpty(void) const {
            if(top>-1)
                return 0; // NOT Empty
            else
                return 1; // Empty
        }

        //returns true if the stack is full
        int StackFull(void) const {
            if(top == MaxStackSize-1)
                return 1;
            else
                return 0;
        }
};

