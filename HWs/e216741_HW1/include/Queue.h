#include <iostream>
#include <stdlib.h>

const int MaxQSize = 50;

using namespace std;

template <class T>
class Queue {

    private:
        // queue array and its parameters
        int front, rear, count;
        T qlist[MaxQSize] ;

    public:

    //constructor
    Queue(void) {
        front = 0;
        rear = 0;
        count = 0;
    }

    // QInsert: insert item into the queue
    void QInsert(const T& item) {
        // terminate if queue is full
        if (count==MaxQSize) {
            cerr<<"Queue overflow!" <<endl;
            exit(1);
        }
        //increment count, assign item to qlist and update rear
        count++;
        qlist[ rear] = item;
        rear=(rear+1)% MaxQSize;
    }

    // QDelete : delete element from the front of the queue
    // and return its value

    T QDelete(void){
        T temp;
        // if qlist is empty, terminate the program
        if (count==0) {
            cerr << "Deleting from an empty queue!" << endl;
        }
        //record value at the front of the queue
        temp = qlist[front] ;
        //decrement count, advance front and return former front
        count--;
        front = (front+1) % MaxQSize;
        return temp;
    }

    void ClearQueue(void) {
        /*
        for(int i = 0; i<=count; i++)
            qlist[front + i] = NULL;
        if (rear < front){
            for(int i = 0; i<=rear; i++)
                qlist[i] = NULL;
        }
        */
        count = 0; // reset count, front, rear
        front = 0;
        rear = 0;
    }


    T QFront(void) const {
        if(count != 0)
            return qlist[front];
        else
            return 0;
    }
    // queue test methods

    int QLength(void) const {
        return count;
    }

    int QEmpty(void) const {
        if (count == 0) // if count == 0
            return 1;
        else
            return 0;
    }

    int QFull(void) const {
        if (count == MaxQSize) // if count == 50
            return 1;
        else
            return 0;
    }
};

