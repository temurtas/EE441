// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include "./include/Stack.h"
#include "./include/Queue.h"

using namespace std;
/*
* FILE INPUT AND STORE
*/

void print(char* i){
    cout << int(*i) << endl;
}

void foo(int *ptr) {
    cout << "in func is " << *ptr << endl;
    int dummy = 60;
    *ptr = dummy;
    cout << "after edit in func is " << *ptr << endl;
}

int main () {
    int cnt = 50;
    int *pointer = &cnt;
    cout << "init is " << *pointer << endl;
    foo(pointer);
    cout << "lastly in the main is " << *pointer << endl;
//    string matrix_entry; // store char variable
//    string file_name = "EE441HW1.txt"; // input file directory
//    uint8_t i = 0; // indice iterator
//
//    const uint8_t adj_matrix_size = 8; // matrix is 8x8
//    uint8_t adj_matrix[adj_matrix_size][adj_matrix_size]; // declare adjacency matrix
//
//    fstream file_input(file_name.c_str(), fstream::in); // read input file
//
//    while (file_input >> skipws >> matrix_entry) {
//            for(uint8_t j=0; j<adj_matrix_size; j++)
//                adj_matrix[i][j] = matrix_entry[j]-48;
//            i++;
//    }
//
//    Stack <int> S1;
//    Queue <int> Q1;
//    cout << Q1.QFull() << endl;
//    cout << Q1.QEmpty() << endl;
//    cout << endl;
//    Q1.QInsert(5);
//    cout << Q1.QFull() << endl;
//    cout << Q1.QEmpty() << endl;
//    cout << Q1.QFront() << endl;
//    cout << Q1.QLength() << endl;
//    cout << endl;
//    Q1.QInsert(6);
//    cout << Q1.QFull() << endl;
//    cout << Q1.QEmpty() << endl;
//    cout << Q1.QFront() << endl;
//    cout << Q1.QLength() << endl;
//    cout << endl;
//    Q1.QDelete();
//    cout << Q1.QFull() << endl;
//    cout << Q1.QEmpty() << endl;
//    cout << Q1.QFront() << endl;
//    cout << Q1.QLength() << endl;
//    cout << endl;
//    Q1.ClearQueue();
//    cout << Q1.QFull() << endl;
//    cout << Q1.QEmpty() << endl;
//    cout << Q1.QFront() << endl;
//    cout << Q1.QLength() << endl;
//    cout << endl;
//
//    print("A");

  return 0;
}
