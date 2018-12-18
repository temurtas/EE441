#ifndef LINKEDLIST_CLASS
#define LINKEDLIST_CLASS

#ifndef NULL
const int NULL = 0;
#endif  // NULL

#include <iostream>
#include <cstdlib>

#include "Node.h" //node class as covered in the lecture notes

using namespace std;

template <class T>
class LinkedList {
  private:
    // pointers maintain access to front and rear of list
    Node<T> *front, *rear;

    // Used for data retrieval, insertion and deletion.
    // These pointers are used in a pair where prevPtr precedes the currPtr.
    // currPtr always points at the node whose data is processed.
    Node<T> *prevPtr, *currPtr;
    Node<T> *tempPtr;
    Node<T> *copyPtr;
    int positionSaved;

    // number of elements in the list
    int size;

    // position of the element pointed by currPtr in list. Used by Reset method
    int position;

    // private methods to allocate and deallocate nodes
    Node<T> *GetNode(const T& item,Node<T> *ptrNext=NULL); // PROVIDED BELOW. AS IMPLEMENTED IN CLASS, MAKE IT A MEMBER FUNCTION
    void FreeNode(Node<T> *p); // PROVIDED BELOW

  public:
    // constructors
    LinkedList(void); // PROVIDED BELOW
    LinkedList(const LinkedList<T>& L); // PROVIDED BELOW

    // destructor
    ~LinkedList(void); // PROVIDED BELOW

    // assignment operator.
    LinkedList<T>& operator= (const LinkedList<T>& L){
        CopyList(L);
    } // PROVIDED IN-LINE

    // copies list L to current list
    void CopyList(const LinkedList<T>& L); // PROVIDED BELOW

    void ClearList(void); // PROVIDED BELOW

    // methods to check list status
    int ListSize(void) const; // PROVIDED BELOW
    int ListEmpty(void) const; // PROVIDED BELOW
    void ListContent(void); // PROVIDED BELOW

    // Traversal methods
    void Reset(int pos = 0); // PROVIDED BELOW
    void Next(void); // PROVIDED BELOW
    int EndOfList(void) const; // PROVIDED BELOW
    int CurrentPosition(void) const; // PROVIDED BELOW

    // Insertion methods
    void InsertFront(const T& item); // PROVIDED BELOW
    void InsertRear(const T& item); // PROVIDED BELOW
    void InsertAt(const T& item); // PROVIDED BELOW
    void InsertAfter(const T& item); // PROVIDED BELOW

    // Deletion methods
    T DeleteFront(void); // PROVIDED BELOW
    void DeleteAt(void); // PROVIDED BELOW

    // Data retrieval/modification
    T& Data(void); // PROVIDED BELOW

};

template <class T>
Node<T> *LinkedList<T>::GetNode(const T& item, Node<T>* ptrNext) {
    Node<T> *p;

    p = new Node<T>(item, ptrNext);
    if (p == NULL) {
        cout << "Memory allocation failure!\n";
        exit(1); //exits with error code
    }
    return p;
}

template <class T>
void LinkedList<T>::FreeNode(Node<T> *p) {
    delete p;
}

// create empty list by setting pointers to NULL, size to 0
// and list position to -1
template <class T>
LinkedList<T>::LinkedList(void): front(NULL), rear(NULL), prevPtr(NULL),currPtr(NULL), size(0), position(-1)
{}

template <class T>
int LinkedList<T>::ListSize(void) const {
    return size;
}

template <class T>
int LinkedList<T>::ListEmpty(void) const {
    return size == 0;
}

// reset the list position to pos
template <class T>
void LinkedList<T>::Reset(int pos) {
    int startPos;

    // if the list is empty, return
    if (front == NULL)
        return;

    // if the position is invalid, terminate the program
    if (pos < 0 || pos > size-1) {
        cerr << "Reset: Invalid list position: " << pos << endl;
        return;
    }

    // move list traversal mechanism to node pos
    if(pos == 0) {
        // reset to front of the list
        prevPtr = NULL;
        currPtr = front;
        position = 0;
    }
    else {
        // reset currPtr, prevPtr, and position
        currPtr = front->NextNode();
        prevPtr = front;
        startPos = 1;
        // move right until position == pos
        for(position=startPos; position < pos; position++) {
            // move both traversal pointers forward
            prevPtr = currPtr;
            currPtr = currPtr->NextNode();
        }
    }
}

// move prevPtr and currPtr forward one node
template <class T>
void LinkedList<T>::Next(void) {
    // if traversal has reached the end of the list or the list is empty, just return
    if (currPtr != NULL) {
        // advance the two pointers one node forward
        prevPtr = currPtr;
        currPtr = currPtr->NextNode();
        position++;
    }
}

// True if the client has traversed the list
template <class T>
int LinkedList<T>::EndOfList(void) const {
    return currPtr == NULL;
}

// return the position of the current node
template <class T>
int LinkedList<T>::CurrentPosition(void) const {
    return position;
}

// Insert item at rear of list
template <class T>
void LinkedList<T>::InsertRear(const T& item) {
    Node<T> *newNode;

    prevPtr = rear;
    newNode = GetNode(item);	// create the new node
    if (rear == NULL) // if list empty, insert at front
        front = rear = newNode;
    else {
        rear->InsertAfter(newNode);
        rear = newNode;
    }
    currPtr = rear;
    position = size;
    size++;
}

// Delete the node at the front of list
template <class T>
T LinkedList<T>::DeleteFront(void) {
    T item;

    Reset();
    if (front == NULL) {
        cerr << "Invalid deletion!" << endl;
        exit(1);
    }
    item = currPtr->data;
    DeleteAt();
    return item;
}

// return a reference to the data value in the current node
template <class T>
T& LinkedList<T>::Data(void) {
    // error if list is empty or traversal completed
    if (size == 0 || currPtr == NULL) {
        cerr << "Data: invalid reference!" << endl;
        exit(1);
    }
    return currPtr->data;
}



/***********************************/
/***********************************/

// Copy Constructor.  HINT: Can use another member function.
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L){
    CopyList(L);
}

// HINT: Can use another member function.
// assignment operator.
//template <class T>
//LinkedList<T>& operator= (const LinkedList<T>& L)

// copies list L to current list
template <class T>
void LinkedList<T>::CopyList(const LinkedList<T>& L) {

    // variables can be shallow copied
    // shallow copying is done here
    cout << "-----------------------------------------------------" << endl;
    cout << "---DEEP COPYING THE REFERENCE LIST TO THE NEW LIST---" << endl;
    cout << "-----------------------------------------------------" << endl;
    front = NULL;
    rear = NULL;
    prevPtr = NULL;
    currPtr = NULL;

    copyPtr = L.front;

    while(copyPtr != NULL) {
        tempPtr = copyPtr;
        this->InsertAfter(tempPtr->data);
        copyPtr = tempPtr->NextNode();
    }
    size = L.size;
    position = L.position;
    this->Reset(position);
}

// print out the content of the list with the links
template <class T>
void LinkedList<T>::ListContent(void) {
    positionSaved = position;
    if(this->ListEmpty()) {
        cerr << "List is already empty!! Does not contain any nodes." << endl;
        exit(1);
    }
    else {
        cout << "currPtr = " << this->currPtr->data << " ";
        cout << "position = " << this->position << " ";
        cout << "size = " << this->size << endl;
        for(this->Reset();!this->EndOfList();this->Next()) {
            if((this->position) + 1 == this->size)
                cout << this->Data() << endl;
            else
            cout << this->Data() << "->";
        }
        cout << "--------------" << endl;
    }
    this->Reset(positionSaved);
}

// method to clear the list.
// The memory allocated for all nodes is returned.
// The list is reset to the initial state.
// start from the position 1 and delete the previous node
// if in the last node, delete the current node
template <class T>
void LinkedList<T>::ClearList(void) {
    // free up the memory
    for(this->Reset(1);!this->EndOfList();this->Next()){
        if(this->position + 1 == this->size){
            delete currPtr;
        }

        else{
            delete prevPtr;
        }

    }
    front = NULL;
    rear = NULL;
    prevPtr = NULL;
    currPtr = NULL;
    size = 0;
    position = -1;
    cout << "Memory is freed. Back to initial state. Destructor." << endl;
}

// Inserts a node with data of item
// at the position of the currPtr.
template <class T>
void LinkedList<T>::InsertAt(const T& item) {
    if(prevPtr == NULL)
        InsertFront(item);
    else {
        Node<T> *newNode;
        newNode = GetNode(item, currPtr);
        prevPtr->InsertAfter(newNode);
        currPtr = newNode;
        size++;
    }

}

// Inserts a node with data of item
// after the node pointed by the currPtr.
template <class T>
void LinkedList<T>::InsertAfter(const T& item) {
    // currPtr shows null but the list is not null, there is a problem
    if (currPtr == NULL && front != NULL) {
        cerr << "InsertAfter: Current Pointer is already NULL!!" << endl;
        exit(1);
    }
    // if the currPtr is the rear, then insert the new to th rear
    else if(currPtr == rear) {
        InsertRear(item);
    }
    // if front is not defined, than it must be front
    else if (front == NULL) {
        InsertFront(item);
    }
    // the inserted node is somewhere in between the front and the rear
    else {
        Node<T> *newNode;
        newNode = GetNode(item, currPtr->NextNode()); // create new node
        currPtr->InsertAfter(newNode); // currPtr's next is the newNode
        currPtr = newNode;
        size++; // size of the list is increased
    }

}

// Inserts a node with data of item
// at the front of the list.
template <class T>
void LinkedList<T>::InsertFront(const T& item) {
    Node<T> *newNode;
    newNode = GetNode(item, front);	// create the new node

    prevPtr = front; // previous pointer is to be the current front

    if (front == NULL) // if list empty, insert at front
        front = rear = newNode;
    else {
        newNode->InsertAfter(front); // insert current front after the new
        front = newNode; // the new is the new front
    }
    currPtr = front; // currPtr points to front
    position = 1; // size is increased
    size++;
}

// destructor
template <class T>
LinkedList<T>::~LinkedList(void) {
    ClearList();
}

// deletes the node where currPtr points to
template <class T>
void LinkedList<T>::DeleteAt(void) {

    if(currPtr == front) {
        front = currPtr->NextNode(); // front's next is the new front
        delete currPtr; // currPtr is deleted
        currPtr = front; // currPtr is points to the new front
        prevPtr = NULL;
    }
    else if (currPtr == rear) {
        rear = prevPtr->DeleteAfter();
        //delete rear; // delete the rear
        rear = prevPtr; // the rear is deleted. then the previous is the rear
        currPtr = NULL;
        //position--;
    }
    else {
        tempPtr = currPtr->NextNode(); // tempPtr is the next of the currPtr
        prevPtr->DeleteAfter(); // prevPtr is disconnected from the currPtr
        currPtr->InsertAfter(prevPtr); // insert prevPtr after the currPtr
        delete currPtr; // delete the memory allocated for the currPtr
        currPtr = tempPtr; // the new currPtr is the tempPtr
        //position--;
    }
    size--;
    //position++;
}
/***********************************/
/***********************************/

#endif  // LINKEDLIST_CLASS
