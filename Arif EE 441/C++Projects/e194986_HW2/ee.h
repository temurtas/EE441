#pragma once
#ifndef ee_h
#define ee_h

#include "ee.h"
#include <string>
#include <sstream>
#include <iostream>

class EECapsule{
private:

	std::string Name;
	int CID;
	int Latitude;
	int Longitude;

public:

	EECapsule(std::string, int, int, int);
	int GetLongitude(void);
	void DisplayCapsuleInfo();
	std::string GetDestination();
};
class EEAircraft{
private:
	int Latitude, Longitude;
	int Direction;
	int count = 0;

public:
	EECapsule* capsules[100];
	EEAircraft(int, int, int);
	int GetLongitude(){ return Longitude; };
	int GetDirection(){ return Direction; };
	void Integrate(EECapsule*);
	EECapsule* Drop();
	void Display();
	void setCount(int i){ count = i; };
	int getCount(){ return count; };

};

#endif
