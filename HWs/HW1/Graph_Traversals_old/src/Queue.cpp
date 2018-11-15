using namespace std;
# include "Queue.h"

template <class T>

Queue<T>::Queue(void): front(0), rear (0), count(0) // constructor initializes empty queue
{ }
void Queue<T>::Qinsert(const T& item) // Qinsert: insert item into the queue
{
    if (count==MaxQSize) // terminate if queue is full
    {
        cerr<<"Queue overflow!" <<endl ;
        exit(1);
    }
    count++; //increment count, assign item to qlist and update rear
    qlist[rear] =item;
    rear=(rear+1)% MaxQSize;
}
T Queue<T>::QDelete(void) // delete element from the front and return its value
{
    T temp;
    if (count==0) // if qlist is empty, terminate the program
    {
        cerr<<"Deleting from an empty queue!"<<endl;
    }
    temp=qlist[front] ; count--; //record value at the front of the queue decrease count
    front=(front+1) % MaxQsize; return temp; // advance front and return former front
}
