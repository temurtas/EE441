// ee441hw2.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "ee.h"


using namespace std;

// Some helper functions: Bubble sort, swap
void bsort(EECapsule **, int);
void PushPop(EECapsule **, int);
void SimulateFlight(EEAircraft*&);

int main()
{
	int level = 0;
	int key;
	int newflightarg[3];
	EEAircraft* newflight;

	// menu is set by "level" variable
	while (true)
	if (level == 0)
	{
		cout << "EE Tech Easy Everywhere Simulator" << endl;
		cout << "[1] New Flight" << endl;
		cout << "[2] Exit" << endl;
		cin >> key;

		if (key == 2)
			exit(0);
		else if (key == 1)
			level = 1;
	}
	else if (level == 1){
		cout << "Input departure latitude:" << endl;
		cin >> newflightarg[0];
		cout << "Input departure longitude:" << endl;
		cin >> newflightarg[1];
		cout << "Input flight direction:" << endl;
		cin >> newflightarg[2];

		newflight = new EEAircraft(newflightarg[0], newflightarg[1], newflightarg[2]);
		level = 2;
	}
	else if (level == 2){
		cout << "EE Tech Easy Everywhere" << endl;
		cout << "[1] New Passenger" << endl;
		cout << "[2] Close Registration and Simulate the Flight" << endl;
		cin >> key;
		if (key == 1) level = 3;
		else if (key == 2) level = 4;
	}
	else if (level == 3){
		int capsulearg[3];
		string name;
		cout << "Name of the Passenger:" << endl;
		cin >> name;
		cout << "CID of the Passenger:" << endl;
		cin >> capsulearg[0];
		cout << "Destination latitude:" << endl;
		cin >> capsulearg[1];
		cout << "Destination longitude:" << endl;
		cin >> capsulearg[2];

		// Insert a capsule
		newflight->Integrate(new EECapsule(name, capsulearg[0], capsulearg[1], capsulearg[2]));

		// Return to previous menu
		level = 2;
	}
	else if (level == 4){

		// Simulate Flight
		SimulateFlight(newflight);

		level = 0;
		system("PAUSE");
	}

	system("PAUSE");
	return 0;
}


void SimulateFlight(EEAircraft*& plane){

	// Sort array
	bsort(plane->capsules, plane->getCount());

	// Organize order in array
	while (plane->capsules[0]->GetLongitude() < plane->GetLongitude() && plane->capsules[plane->getCount() - 1]->GetLongitude()>plane->GetLongitude()){
		PushPop(plane->capsules, plane->getCount());
	}

	cout << endl << "Simulation starts..." << endl;
	// Display flight info
	plane->Display();

	// Drop capsules and printout
	int c = plane->getCount();
	for (int j = 0; j < c; j++){
		EECapsule* temp = plane->Drop();
		cout << endl << "***" << endl;
		cout << "Dropped Capsule:" << endl;
		temp->DisplayCapsuleInfo();
		cout << "***" << endl << endl;
		delete temp;
		plane->Display();
	}
	delete plane;
}

// Bubble sorting, space complexity: N
void bsort(EECapsule** start, int length)
{
	//EECapsule* end_ = end;
	EECapsule** curr = start;
	EECapsule* temp;
	bool IsFinished = false;

	while (!IsFinished){
		IsFinished = true;
		for (int i = 0; i<length - 1; i++){
			if (start[i]->GetLongitude() > start[i + 1]->GetLongitude()){
				temp = start[i];
				start[i] = start[i + 1];
				start[i + 1] = temp;
				IsFinished = false;
			}
		}
	}
}

// Swap first and last elements
void PushPop(EECapsule ** start, int length){
	EECapsule* temp;
	temp = start[0];
	for (int i = 0; i <= length - 2; i++){
		start[i] = start[i + 1];
	}
	start[length - 1] = temp;
}
