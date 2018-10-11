#ifndef _GameBase
#define _GameBase

#include "Player.h"
#include <vector>

using namespace std;

class GameBase{
private:
	Player** Players;   // Array to keep players
	int* randomSeq;     // Random sequence (uniformly random)
	int NumberOfPlayers;

public:
    // Member Functions
    //Constructor
	GameBase(int, int);

	//Shuffle and create a random sequence
	void ShuffleSeq();

	//Get the random sequence
	int* GetSeq(){ return randomSeq; }

	// Get player* by id
	Player* getPlayer(int ID){ return *(Players + ID); }

	// Fight between two Player*
	void Fight(Player*, Player*, bool);

	// Swap two player
	void SwapPlayers(Player*, Player *);

	// Shift up or down in layerwise
	void ShiftLayer(Player*&, int, int);

};




#endif
