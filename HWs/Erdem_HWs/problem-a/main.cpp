/*
Erdem Tuna
erdemtuna@outlook.com
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const short int size = 2;
int in_matrix[size*size];

void matrix_input(int *matrix){
    for(uint8_t i=0; i<(size*size); i++){
        cin >> matrix[i];
    }
}

void swap(int &a,int &b){
    int temp;
    temp = a;
    a = b;             // a/b refer to the parameters that were passed
    b = temp;          // modifying a reference is the same as modifiying the original
}

void matrix_inverse(int *matrix){

    // calculate the proportionality constant for inversing operation
    int inverse_const = 1/(matrix[0]*matrix[3] - matrix[1]*matrix[2]);
    //cout << inverse_const << endl;
    swap(matrix[0], matrix[3]);
    matrix[1] *= -1;
    matrix[2] *= -1;

    for(uint8_t i=0; i<(size*size); i++){
        matrix[i] *= inverse_const;
    }
}

void print_result(int *matrix){
    for(uint8_t i=0; i<(size*size); i++){
        cout << matrix[i] << " ";
        if(i%2==1)
            cout << endl;
    }
}


int main()
{

    // create the main matrix


    // take the user input for the main matrix
    matrix_input(in_matrix);

    // calculate the inverse
    matrix_inverse(in_matrix);

    // print the result
    print_result(in_matrix);

    return 0;
}

