using namespace std;
# include "Queue.h"

template <class T>

Queue<T>::Queue(void): front(0), rear (0), count(0) // constructor initializes empty queue
{ }
template <class T> // now implementation of methods

void Queue<T>::QInsert(const T& item)

//void Queue<T>::Qinsert(const T& item) // Qinsert: insert item into the queue
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
template <class T> // now implementation of methods
T Queue<T>::QDelete(void) // delete element from the front and return its value
{
    T temp;
    if (count==0) // if qlist is empty, terminate the program
    {
        cerr<<"Deleting from an empty queue!"<<endl;
    }
    temp=qlist[front] ; count--; //record value at the front of the queue decrease count
    //front=(front+1) % template <class T> ; //HERE PROBLEMMMMMMMMMMMM
    return temp; // advance front and return former front
}
