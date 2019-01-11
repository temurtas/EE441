#include "DFT_Search.h"
#include "Queue.h"
#include "Stack.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

DFT_Search::DFT_Search() {
}

DFT_Search::DFT_Search(char* s_vertex, string in_graph) {
    s_vertex_number = (int(*s_vertex) - 65); // starting vertex as the ASCII to number
    d_vertex_number = -1; // this variable won't be used in Part-1
    //cout << s_vertex_number;
    DFT_Search::ParseMatrix(in_graph); //parse the input file to a matrix
}

DFT_Search::DFT_Search(char* s_vertex, char* d_vertex, string in_graph) {
    s_vertex_number = (int(*s_vertex) - 65); // starting vertex as the ASCII to number
    d_vertex_number = (int(*d_vertex) - 65); // destination vertex as the ASCII to number
    DFT_Search::ParseMatrix(in_graph); //parse the input file to a matrix
}

void DFT_Search::Start(void) {
    Stack <int> S;
    if(d_vertex_number == -1)
        cout << "DFT Search: ";
    else
        cout << "Modified DFT Search: ";
    int i, j; // loop variables
    S.Push(s_vertex_number); // push the starting vertex to the queue
//    for(i=0; i<adj_matrix_size; i++) {
//        adj_matrix[i][s_vertex_number] = 0; // zero all the elements in the same column
//        // not to visit it again
//    }
    int visited[adj_matrix_size] = {0,0,0,0,0,0};
    while(!S.StackEmpty()) {
        int visiting_number = S.Peek(); // get the last stack item

        char visiting_char = char(visiting_number + 65); // convert the current item to char
        if(!visited[visiting_number])
            cout << visiting_char << " ";

        for(j=0; j<adj_matrix_size; j++) { // find the columns with 1 for starting vertex
            if(adj_matrix[visiting_number][j]) {
                S.Push(j); // found 1, then insert related index to queue

                for(i=0; i<adj_matrix_size; i++) {
                    adj_matrix[i][j] = 0; // zero all the elements in the same column
                    // not to visit it again
                }
                j = 99; // dummy assignment for breaking the loop
            }
        }
        if(j != 100)
            S.Pop();
        visited[visiting_number] = 1;
        if(d_vertex_number == visiting_number)
            S.ClearStack();

    }
    cout << endl; // go to next line
}

void DFT_Search::ParseMatrix(string file_name) {

    string matrix_entry; // store char variable
    uint8_t i = 0; // indice iterator

    fstream file_input(file_name.c_str(), fstream::in); // read input file

    // parse input text to adj_matrix
    while (file_input >> skipws >> matrix_entry) {
        for(uint8_t j=0; j<adj_matrix_size; j++)
            adj_matrix[i][j] = matrix_entry[j]-48; // character to integer
        i++;
    }
}
DFT_Search::~DFT_Search() {
    //dtor
}
