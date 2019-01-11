#include <iostream>

#include<Node.h>
#include<LinkedList.h>
#include<PQ.h>

using namespace std;

int main() {
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << "xx Showing Linked List functionalities xx" << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    LinkedList<int> MyList;
    for(int i=1;i<6;i++)
        MyList.InsertAfter(i);
    MyList.ListContent();

    MyList.Reset(3);
    MyList.ListContent();

    MyList.DeleteAt();
    MyList.ListContent();

    MyList.InsertAt(9);
    MyList.ListContent();

    MyList.InsertAfter(10);
    MyList.ListContent();

    LinkedList<int> AliasMyList;
    AliasMyList = MyList;

    AliasMyList.InsertAt(12);
    AliasMyList.ListContent();
    MyList.ListContent();

    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << "xx Showing Priority Queue functionalities xx" << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;

    PriorityQueue<int> Q;

    Q.QInsert(10);Q.QInsert(20);Q.QInsert(30);Q.QInsert(40);
    Q.ShowQ();

    Q.QInsert(25);
    Q.ShowQ();

    int most_important = Q.QDelete();
    cout << "most_important = " << most_important << endl;
    Q.ShowQ();

    PriorityQueue<int> aliasQ;
    aliasQ = Q;

    aliasQ.QInsert(50);
    aliasQ.ShowQ();
    Q.ShowQ();

    return 0;
}
