#ifndef PRIORITYQ_CLASS
#define PRIORITYQ_CLASS

#include "LinkedList.h"

template <class T>
class PriorityQueue
{
private:
    // assume T is a data type where > (greater than), < (less than) and == (equal to)
    // operators that allow comparison are defined and overloaded.
    LinkedList<T> Q;

public:
    // constructors
    PriorityQueue(void); // PROVIDED BELOW
    PriorityQueue(const PriorityQueue<T>& PQ); // Copy Constructor

    // destructor
    ~ PriorityQueue(void);

    int QSize(void) const;   // Returns the number of items stored in the Priority Queue
    int QEmpty(void) const; // PROVIDED BELOW

    void ShowQ(); // PROVIDED BELOW

    void QInsert(const T& item); // Inserts the item at the correct location in the Q List

    // Deletion methods
    T QDelete(void); // Deletes and returns the item with the highest priority

};

template <class T>
PriorityQueue<T>::PriorityQueue(void)
{}

template <class T>
int  PriorityQueue<T>::QEmpty(void) const
{
    return Q.ListEmpty();
}


template <class T>
void PriorityQueue<T>::ShowQ()
{
    for(Q.Reset(); !Q.EndOfList(); Q.Next())
        cout<<Q.Data()<<" ";
    cout<<"\n";
}



/***********************************/
/***********************************/



// Copy Constructor
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& PQ){
        this->Q = PQ.Q;
}


template <class T>
PriorityQueue<T>::~PriorityQueue(void){}

template <class T>
int PriorityQueue<T>::QSize(void) const {
    return Q.ListSize();
}

template <class T>
void PriorityQueue<T>::QInsert(const T& item) {

    if (Q.ListSize()==0)
        Q.InsertFront(item);
    else{
        for(Q.Reset();!Q.EndOfList();Q.Next()) {
            if(Q.CurrentPosition() == (Q.ListSize()-1))
                Q.InsertRear(item);
            else if (item < Q.Data()) {
                Q.InsertAt(item);
                break;
            }
        }
    }
}


// Deletes and returns the item with the highest priority
//template <class T>
//T PriorityQueue<T>::QDelete(void) {
//    return Q.DeleteFront();
//}






/***********************************/
/***********************************/



#endif  // PRIORITYQ_CLASS
