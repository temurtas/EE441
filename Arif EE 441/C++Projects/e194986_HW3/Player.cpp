#include <iostream>
#include "Player.h"

const int E_MAX = 200;
const int E_MIN = 100;

// Constructors

Player::Player(){
	Layer = 0;
	XP = E_MIN;
	IsRoot = true;
}

Player::Player(char id){
	Layer = 0;
	XP = E_MIN;
	IsRoot = true;
	ID = id;
}

