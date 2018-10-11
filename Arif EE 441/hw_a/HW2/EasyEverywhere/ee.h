#ifndef ___EE_H___
#define ___EE_H___

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Capsule
{
	private:
		string name;
		int CID;
		int latitude;
		int longitude;
		int distanceToAirCraft;
		Capsule* child;
		Capsule* father;
	public:
		Capsule();
		Capsule(string name,int CID,int latitude,int longitude,int longitudeAirCraft,int directionOfAirCraft);
		string getName();
		int getCID();
		int getLatitude();
		int getLongitude();
		int getDistanceToAirCraft();
		void setChild(Capsule* child);
		Capsule* getChild();
		void setFather(Capsule* father);
		Capsule* getFather();
};


class AirCraft
{
	private:
		string name;
		int latitude;
		int longitude;
		int direction;
		Capsule* head;
	public:
		AirCraft(int latitude,int longitude,int direction);
		string getName();
		int getLatitude();
		int getLongitude();
		int getDirection();
		void integrate(Capsule* newCapsule);
		void dropCapsule();
		Capsule* getHead();
};

#endif
