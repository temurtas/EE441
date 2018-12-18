
#include <iostream>

#include "include/LinkedList.h"
#include "include/Node.h"
#include "include/PriorityQueue.h"
#include "pch.h"

using namespace std;

int main() {
	cout << "Hello world!" << endl;


	LinkedList<int> Halil;
	PriorityQueue<int> Halil2;

	Halil.InsertFront(2);
	Halil.InsertFront(0);
	Halil2.QInsert(2);
	Halil2.QInsert(2);
	Halil2.QInsert(3);
	Halil2.QInsert(5);
	Halil2.QInsert(2);
	Halil2.QInsert(1);
	Halil.InsertRear(1);
	Halil.InsertRear(3);
	Halil.InsertAt(4);
	Halil.PrintList();
	Halil2.ShowQ();
	cout << Halil2.QSize();
	return 0;
}

