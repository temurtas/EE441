#include <iostream>
#include "Player.h"
#include <vector> // Linked list can be used instead of vector. However, it makes program complex and slow... 
const int E_MAX = 200;
const int E_MIN = 100;

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

void Player::SetID(int id){
	ID = id;
}