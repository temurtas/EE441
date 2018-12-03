#ifndef LINKEDLIST_CLASS
#define LINKEDLIST_CLASS

#ifndef NULL
const int NULL = 0;
#endif  // NULL

#include <iostream>
#include <cstdlib>

#include "node.h" //node class as covered in the lecture notes

using namespace std;

template <class T>
class LinkedList
{
private:
    // pointers maintain access to front and rear of list
    Node<T> *front, *rear;

    // Used for data retrieval, insertion and deletion.
    // These pointers are used in a pair where prevPtr precedes the currPtr.
    // currPtr always points at the node whose data is processed.
    Node<T> *prevPtr, *currPtr;

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
    LinkedList(const LinkedList<T>& L); // Copy Constructor.  HINT: Can use another member function.

    // destructor
    ~LinkedList(void); // HINT: Can use another member function.

    // assignment operator.
    LinkedList<T>& operator= (const LinkedList<T>& L); // HINT: Can use another member function.

    // copies list L to current list
    void CopyList(const LinkedList<T>& L);

    // method to clear the list. The memory allocated for all nodes is returned. The list is reset to the initial state.
    void ClearList(void);

    // methods to check list status
    int ListSize(void) const; // PROVIDED BELOW
    int ListEmpty(void) const; // PROVIDED BELOW

    // Traversal methods
    void Reset(int pos = 0); // PROVIDED BELOW
    void Next(void); // PROVIDED BELOW
    int EndOfList(void) const; // PROVIDED BELOW
    int CurrentPosition(void) const; // PROVIDED BELOW

    // Insertion methods
    void InsertFront(const T& item); // Inserts a node with data of item at the front of the list.
    void InsertRear(const T& item); // PROVIDED BELOW
    void InsertAt(const T& item); // Inserts a node with data of item at the position of the currPtr.
    void InsertAfter(const T& item); // Inserts a node with data of item after the node pointed by the currPtr.

    // Deletion methods
    T DeleteFront(void); // PROVIDED BELOW
    void DeleteAt(void);

    // Data retrieval/modification
    T& Data(void); // PROVIDED BELOW

};

template <class T>
Node<T> *LinkedList<T>::GetNode(const T& item, Node<T>* ptrNext)
{
    Node<T> *p;

    p = new Node<T>(item, ptrNext);
    if (p == NULL)
    {
        cout << "Memory allocation failure!\n";
        exit(1); //exits with error code
    }
    return p;
}

template <class T>
void LinkedList<T>::FreeNode(Node<T> *p)
{
    delete p;
}

// create empty list by setting pointers to NULL, size to 0
// and list position to -1
template <class T>
LinkedList<T>::LinkedList(void): front(NULL), rear(NULL), prevPtr(NULL),currPtr(NULL), size(0), position(-1)
{
    // not needed to write something
}

template <class T>
int LinkedList<T>::ListSize(void) const
{
    return size;
}

template <class T>
int LinkedList<T>::ListEmpty(void) const
{
    return size == 0;
}

// reset the list position to pos
template <class T>
void LinkedList<T>::Reset(int pos)
{
    int startPos;

    // if the list is empty, return
    if (front == NULL)
        return;

    // if the position is invalid, terminate the program
    if (pos < 0 || pos > size-1)
    {
        cerr << "Reset: Invalid list position: " << pos << endl;
        return;
    }

    // move list traversal mechanism to node pos
    if(pos == 0)
    {
        // reset to front of the list
        prevPtr = NULL;
        currPtr = front;
        position = 0;
    }
    else
    {
        // reset currPtr, prevPtr, and position
        currPtr = front->NextNode();
        prevPtr = front;
        startPos = 1;

        // move right until position == pos
        for(position=startPos; position != pos; position++)
        {
            // move both traversal pointers forward
            prevPtr = currPtr;
            currPtr = currPtr->NextNode();
        }
    }
}

// move prevPtr and currPtr forward one node
template <class T>
void LinkedList<T>::Next(void)
{
    // if traversal has reached the end of the list or the list is empty, just return
    if (currPtr != NULL)
    {
        // advance the two pointers one node forward
        prevPtr = currPtr;
        currPtr = currPtr->NextNode();
        position++;
    }
}

// True if the client has traversed the list
template <class T>
int LinkedList<T>::EndOfList(void) const
{
    return currPtr == NULL;
}

// return the position of the current node
template <class T>
int LinkedList<T>::CurrentPosition(void) const
{
    return position;
}

// Insert item at rear of list
template <class T>
void LinkedList<T>::InsertRear(const T& item)
{
    Node<T> *newNode;

    prevPtr = rear;
    newNode = GetNode(item);	// create the new node
    if (rear == NULL)				// if list empty, insert at front
        front = rear = newNode;
    else
    {
        rear->InsertAfter(newNode);
        rear = newNode;
    }
    currPtr = rear;
    position = size;
    size++;
}

// Delete the node at the front of list
template <class T>
T LinkedList<T>::DeleteFront(void)
{
    T item;

    Reset();
    if (front == NULL)
    {
        cerr << "Invalid deletion!" << endl;
        exit(1);
    }
    item = currPtr->data;
    DeleteAt();
    return item;
}

// return a reference to the data value in the current node
template <class T>
T& LinkedList<T>::Data(void)
{
    // error if list is empty or traversal completed
    if (size == 0 || currPtr == NULL)
    {
        cerr << "Data: invalid reference!" << endl;
        exit(1);
    }
    return currPtr->data;
}



/***********************************/
/***********************************/


// copy L to the current list, which is assumed to be empty
template <class T>
void LinkedList<T>::CopyList(const LinkedList<T>& L)
{
Node<T> *p = L.front; // use p to chain through L
int pos;
// insert each element in L at the rear of current object
while (p != NULL)
{
InsertRear(p->data);
p = p->NextNode();
}
if (L.CurrentPosition() == -1) // if list is empty return
return;
// reset prevPtr and currPtr in the new list
prevPtr = NULL;
currPtr = front;
for (pos = 0; pos != L.CurrentPosition(); pos++)
{
prevPtr = currPtr;
currPtr = currPtr->NextNode();
}
}


template <class T>
void LinkedList<T>::ClearList(void)
{
Node<T> *currPosition, *nextPosition;
currPosition = front;
while(currPosition != NULL)
{
// get address of next node and delete current
node
nextPosition = currPosition->NextNode();
FreeNode(currPosition);
currPosition = nextPosition; // Move to next node
}
front = rear = NULL;
prevPtr = currPtr = NULL;
size = 0;
position = -1;
}


template <class T>
LinkedList<T>::~LinkedList(void)
{
ClearList();
}


template <class T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& L)
{
if (this == &L) // Can't assign list to itself
return *this;
ClearList();
CopyList(L);
return *this;
}


// Insert item after the current list position
template <class T>
void LinkedList<T>::InsertAfter(const T& item)
{
    Node<T> *p;
    p = GetNode(item);
    if (front == NULL) // inserting into an empty list
{
front = currPtr = rear = p;
    position = 0;
}
else
{
    // inserting after last node of list
    if (currPtr == NULL)
    currPtr = prevPtr;
        currPtr->InsertAfter(p);
if (currPtr == rear)
{
    rear = p;
    position = size;
}
else
    position++;
    prevPtr = currPtr;
    currPtr = p;
}
size++; // increment list size
}


// Delete the node at the current list position
template <class T>
void LinkedList<T>::DeleteAt(void)
{
Node<T> *p;
// error if empty list or at end of list
if (currPtr == NULL)
{
cerr << "Invalid deletion!" << endl;
exit(1);
}
// deletion must occur at front node or inside the list
if (prevPtr == NULL)
{
// save address of front and unlink it. if this
// is the last node, front becomes NULL
p = front;
front = front->NextNode();
}
else
// unlink interior node after prevPtr. save address
p = prevPtr->DeleteAfter();
// if rear is deleted, new rear is prevPtr and
position
// is decremented; otherwise, position is the same
// if p was last node, rear = NULL and position = -
1
if (p == rear)
{
rear = prevPtr;
position--;
}
// move currPtr past deleted node. if p is last
node
// in the list, currPtr becomes NULL
currPtr = p->NextNode();
// free the node and decrement the list size
FreeNode(p);
size--;
}


/***********************************/
/***********************************/



#endif  // LINKEDLIST_CLASS
