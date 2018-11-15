#include <iostream>
#include <fstream>
#include <string>
#include "./include/BFT_Search.h"
#include "./include/DFT_Search.h"
#include "./include/Stack.h"
#include "./include/Queue.h"

using namespace std;

int main()
{
    char dest_char[1] = {'X'} ; // Store the destination point;

    // control input range to be in [A,F]
    while(((int(*dest_char) - 65) > 5) &&((int(*dest_char) - 65) > 5)){ // starting vertex as the ASCII to number
    cout << "Enter the destination point (A to F)(for modified search): ";
    cin >> dest_char[0];
    }

    BFT_Search B("A", "EE441HW1.txt"); // BFT Search
    B.Start();

    BFT_Search B_mod("A", dest_char, "EE441HW1.txt"); // Modified BFT Search
    B_mod.Start();

    DFT_Search D("A", "EE441HW1.txt"); // DFT Search
    D.Start();

    DFT_Search D_mod("A", dest_char, "EE441HW1.txt"); // Modified DFT Search
    D_mod.Start();
    return 0;
}
