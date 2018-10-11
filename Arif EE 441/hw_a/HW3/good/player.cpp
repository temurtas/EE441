#ifndef ___PLAYERCPP___
#define ___PLAYERCPP___

#include "player.h"
#include <stdlib.h>
#include <math.h>
#include <climits>
#include <string.h>
#include <stdio.h>
using namespace std;

inline Player::Player(){};

inline Player::Player(int ID){
	this->ID=ID;
	this->layer=0;
	this->experience=100;
	this->father=NULL;
	this->restFlag=0;
};

inline int Player::getID(){
	return this->ID;
};

inline int Player::getLayer(){
	return this->layer;
};

inline int Player::getRest(){
	return this->restFlag;
};

inline double Player::getExp(){
	return this->experience;
};

inline Player* Player::getFather(){
	return this->father;
};

inline void Player::setFather(Player* father){
	this->father=father;
};

inline void Player::setExp(double experience){
	this->experience=experience;
};

inline void Player::setLayer(int layer){
	this->layer=layer;
};

inline void Player::setRest(int rest){
	this->restFlag=rest;
}

inline void Player::switchFatherChild(Player* parent, Player* array, int numberOfPlayers){
	int i;
	Player* temp;
	temp= new Player();	//we call this member function if a child wins against its father, the function switches them and organize layers

	this->father=parent->father;// switches child and father
	

	for(i=0;i<numberOfPlayers;i++)
	{								//set fathers of all players to the new father
		if((array+i)->father==parent)
			(array+i)->father=temp;
	}

	for(i=0;i<numberOfPlayers;i++)
	{								//set fathers of all players to the new father
		if((array+i)->father==this)
			(array+i)->father=parent;
	}

	for(i=0;i<numberOfPlayers;i++)
	{								//set fathers of all players to the new father
		if((array+i)->father==temp)
			(array+i)->father=this;
	}

	parent->father=this;
	this->layer=this->layer+1;
	parent->layer=parent->layer-1;

	delete temp; //deallocate the temporary dynamically created object
}

#endif