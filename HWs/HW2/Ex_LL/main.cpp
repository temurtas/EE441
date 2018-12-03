/*
 * File: main.cpp
 * Author: Ming
 * Source: Youtube - Paul Programming
 * Version 1: Dec 02, 2014
 * Run: g++ main.cpp -o List
 *      ./List
 */


#include <cstdlib>

#include "List.cpp"
#include "List.h"

using namespace std;

int main(int argc, char** argv){

	List Ming;

	// test AddNode function
	Ming.AddNode(3);
	Ming.AddNode(5);
	Ming.AddNode(7);
	Ming.AddNode(9);
	Ming.PrintList();

	// test delNode function
	Ming.DeleteNode(3);
	Ming.PrintList();
	
	return 0;
}