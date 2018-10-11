#ifndef _GameTree
#define _GameTree

#include "Player.h"
#include <vector>

using namespace std;

class GameTree{
private:
	Player* Players;
	int* randomSeq;
	int NumberOfPlayers;
public:
	GameTree(int, int);
	void ShuffleSeq();
	int* GetSeq(){ return randomSeq; }
	Player* getPlayer(int ID){ return &(Players[ID]); }
	void Fight(Player*, Player*, bool);

};




#endif