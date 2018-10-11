#include "ee.h"
#include <stdlib.h>
#include <math.h>
#include <climits>
#include <string.h>
#include <stdio.h>
using namespace std;

inline Capsule::Capsule(){
};
inline Capsule::Capsule(string name,int CID,int latitude,int longitude,int longitudeAirCraft,int directionOfAirCraft)
{
	this->name = name;
	this->CID = CID;
	this->latitude = latitude;
	this->longitude = longitude;
	this->child = NULL;
	this->father = NULL;
	this->distanceToAirCraft = (directionOfAirCraft*(this->longitude-longitudeAirCraft));
	if(this->distanceToAirCraft<0)
		this->distanceToAirCraft+=360;
};
inline string Capsule::getName()
{
	return this->name;
};
inline int Capsule::getCID()
{
	return this->CID;
};
inline int Capsule::getLatitude()
{
	return this->latitude;
};
inline int Capsule::getLongitude()
{
	return this->longitude;
};
inline int Capsule::getDistanceToAirCraft()
{
	return this->distanceToAirCraft;
};
inline void Capsule::setChild(Capsule* child)
{
	this->child = child;
};
inline Capsule* Capsule::getChild()
{
	return this->child;
};
inline void Capsule::setFather(Capsule* father)
{
	this->father = father;
};
inline Capsule* Capsule::getFather()
{
	return this->father;
};


inline AirCraft::AirCraft(int latitude,int longitude,int direction)
{
	this->name = "**AykutAir**";
	this->latitude = latitude;
	this->longitude = longitude;
	this->direction = direction;
	this->head = NULL;
};
inline string AirCraft::getName()
{
	return this->name;
};
inline int AirCraft::getLatitude()
{
	return this->latitude;
};
inline int AirCraft::getLongitude()
{
	return this->longitude;
};
inline int AirCraft::getDirection()
{
	return this->direction;
};
inline Capsule* AirCraft::getHead()
{
	return this->head;
};
inline void AirCraft::integrate(Capsule* newCapsule)
{
	if(head == NULL )
		head = newCapsule;
	else if (head->getDistanceToAirCraft()<newCapsule->getDistanceToAirCraft())
	{
		Capsule* tempChild;
		tempChild = head;
		newCapsule->setChild(tempChild);
		tempChild->setFather(newCapsule);
		head = newCapsule;
	}
	else
	{
		Capsule* tempChild;
		tempChild = head;
		while(tempChild->getChild()!=NULL && tempChild->getChild()->getDistanceToAirCraft()>newCapsule->getDistanceToAirCraft() )
			tempChild = tempChild->getChild();

		if(tempChild->getChild()!=NULL)
		{
			newCapsule->setChild(tempChild->getChild());	// set child of newCapsule
			newCapsule->getChild()->setFather(newCapsule);	// set newCapsule as father
		}
		tempChild->setChild(newCapsule);					// set newCapsule as child
		newCapsule->setFather(tempChild);				// set father of newCapsule
	}
};

inline void AirCraft::dropCapsule()
{
	Capsule* temp ;
	temp=this->head;
	if(temp->getChild()==NULL)
	{
		this->head = NULL;
		delete temp;
		return;
	}
	while(temp->getChild() !=NULL)
		temp = temp->getChild();
	temp->getFather()->setChild(NULL);
	delete temp;
};
