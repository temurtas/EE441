#ifndef PRIORITYQ_CLASS
#define PRIORITYQ_CLASS

#include "LinkedList.h"

template <class T>
class PriorityQueue {
  private:
    // assume T is a data type where > (greater than), < (less than) and == (equal to)
    // operators that allow comparison are defined and overloaded.
    LinkedList<T> Q;

    // if nItem is more prior than qItem, return true
    // PROVIDED IN-LINE
     bool operator< (const T& nItem){
        if(nItem < Q.Data()) return true;
        else return false;
    }

    // if nItem is less prior than qItem, return true
    // PROVIDED IN-LINE
    bool operator> (const T& nItem){
        if(nItem > Q.Data()) return true;
        else return false;
    }

    // if nItem is as prior as qItem, return true
    // PROVIDED IN-LINE
    bool operator== (const T& nItem){
        cout << nItem == Q.Data() << endl;
        if(nItem == Q.Data()) return true;
        else return false;
    }

  public:
    // constructors
    PriorityQueue(void); // PROVIDED BELOW
    PriorityQueue(const PriorityQueue<T>& PQ); // PROVIDED BELOW

    // destructor
    ~ PriorityQueue(void); // PROVIDED BELOW

    int QSize(void) const;   // PROVIDED BELOW
    int QEmpty(void) const; // PROVIDED BELOW

    void ShowQ(); // PROVIDED BELOW

    void QInsert(const T& item); // PROVIDED BELOW

    // Deletion methods
    T QDelete(void); // PROVIDED BELOW

};

template <class T>
PriorityQueue<T>::PriorityQueue(void)
{}

template <class T>
int  PriorityQueue<T>::QEmpty(void) const {
    return Q.ListEmpty();
}


template <class T>
void PriorityQueue<T>::ShowQ() {
    Q.Reset();
    Q.ListContent();
}



/***********************************/
/***********************************/
// Copy Constructor
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& PQ){
    this->Q = PQ.Q;
}

template <class T>
int PriorityQueue<T>::QSize(void) const {
    return Q.ListSize();
}

template <class T>
void PriorityQueue<T>::QInsert(const T& item) {
    // for the first item
    if(Q.ListEmpty())
        Q.InsertFront(item);
    else {
        // iterate through the Q to find the right location
        for(Q.Reset();!Q.EndOfList();Q.Next()) {
            if (item < Q.Data()) {
            Q.InsertAt(item);
            break;
            }
            else if(Q.CurrentPosition() == (Q.ListSize()-1))
                Q.InsertRear(item);

        }
    }

}

template <class T>
PriorityQueue<T>::~PriorityQueue(void){
    // No need to initiate a destructor.
    // LinkedList already has a destructor and
    // it is get called properly.
}

// Deletes and returns the item with the highest priority
template <class T>
T PriorityQueue<T>::QDelete(void) {
    return Q.DeleteFront();
}
/***********************************/
/***********************************/



#endif  // PRIORITYQ_CLASS
