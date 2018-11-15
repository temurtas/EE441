#include "BFT_Search.h"
#include "Queue.h"
#include "Stack.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

BFT_Search::BFT_Search() {
}

BFT_Search::BFT_Search(char* s_vertex, string in_graph) {
    s_vertex_number = (int(*s_vertex) - 65); // starting vertex as the ASCII to number
    d_vertex_number = -1;
    //cout << s_vertex_number;
    BFT_Search::ParseMatrix(in_graph); //parse the input file to a matrix
}

BFT_Search::BFT_Search(char* s_vertex, char* d_vertex, string in_graph) {
    s_vertex_number = (int(*s_vertex) - 65); // starting vertex as the ASCII to number
    d_vertex_number = (int(*d_vertex) - 65); // destination vertex as the ASCII to number
    //cout << s_vertex_number;
    BFT_Search::ParseMatrix(in_graph); //parse the input file to a matrix
}

void BFT_Search::Start(void) {
    Queue <int> Q;
    if(d_vertex_number == -1)
        cout << "BFT Search: ";
    else
        cout << "Modified BFT Search: ";
    int i, j; // loop variables
    Q.QInsert(s_vertex_number); // push the starting vertex to the queue
    for(i=0; i<adj_matrix_size; i++) {
        adj_matrix[i][s_vertex_number] = 0; // zero all the elements in the same column
        // not to visit it again
    }
    while(!Q.QEmpty()) {
        int visiting_number = Q.QDelete(); // get the last stack item
        char visiting_char = char(visiting_number + 65); // convert the current item to char
        cout << visiting_char << " ";

        for(j=0; j<adj_matrix_size; j++) { // find the columns with 1 for starting vertex
            if(adj_matrix[visiting_number][j]) {
                Q.QInsert(j); // found 1, then insert related index to queue

                for(i=0; i<adj_matrix_size; i++) {
                    adj_matrix[i][j] = 0; // zero all the elements in the same column
                    // not to visit it again
                }
            }
        }
        if(d_vertex_number == visiting_number)
            Q.ClearQueue();

    }
    cout << endl; // go to next line
}

void BFT_Search::ParseMatrix(string file_name) {

    string matrix_entry; // store char variable
    uint8_t i = 0; // indice iterator

    fstream file_input(file_name.c_str(), fstream::in); // read input file

    // parse input text to aj_matrix
    while (file_input >> skipws >> matrix_entry) {
        for(uint8_t j=0; j<adj_matrix_size; j++)
            adj_matrix[i][j] = matrix_entry[j]-48; // character to integer
        i++;
    }
}
BFT_Search::~BFT_Search() {
    //dtor
}
