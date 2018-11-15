#include <iostream>
#include <stdlib.h>

const int MaxQSize=50;
template <class T>
class Queue
{
    private:
        int front, rear, count; // queue array and its parameters
        T qlist[MaxQSize] ;
    public:
        Queue(void); // constructor initialize data members
        void QInsert(const T& item); // queue modification operations
        T QDelete(void);
        void ClearQueue(void);
        T QFront(void) const; // queue access
        int QLength(void) const; // status check methods
        int QEmpty(void) const;
        int QFull(void) const;
};

