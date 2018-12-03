#include <iostream>

#include "./include/link.h"
#include "./include/node.h"
#include "./include/PQ.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;


    LinkedList<int> Halil;

    Halil.InsertRear(1);
    Halil.InsertFront(2);
    Halil.InsertAt(3);
    Halil.InsertAt(4);
    Halil.PrintList();


    return 0;


}


