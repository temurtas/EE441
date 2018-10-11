#include "GameBase.h"
#include "Player.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

const int E_MAX = 200;
const int E_MIN = 100;

void swap(int*, int*);


GameBase::GameBase(int _NumberOfPlayers, int NumberOfRoundsForWin){
	const int TurnsForWin = NumberOfRoundsForWin;
	NumberOfPlayers = _NumberOfPlayers;
	int round = 0;	// current round
	int turn = 0;	// current turn in current round

	randomSeq = new int[NumberOfPlayers];
	// random sequence for each turn
	Players = new Player*[NumberOfPlayers];

	// Set IDs of players and create an ordered sequence.
	for (int i = 0; i < NumberOfPlayers; i++){
		Players[i] = new Player();
		Players[i]->setID(i);
		randomSeq[i] = i;
	}




}

// Shuffling the sequence uniform randomly...
void GameBase::ShuffleSeq() {
	int src;
	for (int dest = NumberOfPlayers - 1; dest > 0; dest--)
	{
		// Choose numbers starting from the end and find a randomly chosen position for it.
		src = rand() % (dest + 1);  // Positions from [0] to [Dest]
		swap(&randomSeq[src], &randomSeq[dest]);
	}

}
// Helper function for "ShuffleSeq". Simple swap
void swap(int* i, int* j){
	int temp = *i;
	*i = *j;
	*j = temp;
}



void GameBase::Fight(Player* p, Player* o, bool rootFight){
	bool IsWin = false;
	bool IsDraw = false;
	int A, effA, B, C, random;
	int N = p->getLayer();
	int M = o->getLayer();

	A = p->getXP();
	effA = A*(1 + (M - N) / NumberOfPlayers); // effectiveA = A * (1 + (layer_opp – layer_player) / num_of_players)
	C = o->getXP();
	B = (E_MAX - E_MIN) - abs(A - C);

	cout << "Win, lose and draw intervals are: " << effA << ", " << B << ", " << C << ":\n";
	random = rand() % (effA + B + C);
	cout << "Random number is " << random << "\n";

	if (random > 0 && random <= effA - 1){
		cout << "Win!\n";
		//Player Wins
		p->setXP(A + (C / A)*((E_MAX - A) / 2));  // E_player = E_player + (E_opp/E_player)*((E_max – E_player)/2)
		//Opponent Loses
		o->setXP(C - (C / A)*((C - E_MIN) / 3));  //  E_player = E_player - (E_player / E_opp)*(( E_player – E_min)/3)
		IsWin = true;
	}
	else if (random > effA - 1 && random <= effA + B - 1){
		cout << "Lose!\n";
		//Player Loses
		p->setXP(A - (A / C)*((A - E_MIN) / 2)); // E_player = E_player - (E_player /E_opp)*(( E_player – E_min)/2)
		//Opponent Wins
		o->setXP(C + (A / C)*((E_MAX - C) / 3)); // E_player = E_player + (E_opp/E_player)*((E_max – E_player)/3)
	}
	else {
		int opt;
		IsDraw = true;
		cout << "Draw!\n";
		// Draw
		cout << "Player " << o->getID() << ", what will you do?";
		cout << "\n\n1.Fight Back" << "\n2.Escape\n";
		cin >> opt;
		if (opt == 1) {
			Fight(o, p, rootFight); p->setXP(A - (A / C)*((A - E_MIN) / 4)); // Recursively call function swapping p and o...
		}

	}
	if (!IsDraw)
	if (rootFight){
		if (IsWin){
			if (N == M + 1){
				p->getChildren().push_back(o);
				o->setParent(p);
				o->setRoot(false);

			}
			else if (N > M + 1){
				ShiftLayer(o, N - 1, 0);
				p->getChildren().push_back(o);
				o->setParent(p);
				o->setRoot(false);
			}
			else {
				ShiftLayer(p, M + 1, 0);
				p->getChildren().push_back(o);
				o->setParent(p);
				o->setRoot(false);
			}
		}
		else{ // lose
			if (M == N + 1){
				o->getChildren().push_back(p);
				p->setParent(o);
				p->setRoot(false);
			}
			else if (M > N + 1){
				ShiftLayer(p, M - 1, 0);
				o->getChildren().push_back(p);
				p->setParent(o);
				p->setRoot(false);
			}
			else {
				ShiftLayer(o, N + 1, 0);
				o->getChildren().push_back(p);
				p->setParent(o);
				p->setRoot(false);
			}

		}



	}
	else{ // not a root fight
		if (IsWin){
			if (p->getParent() == o){
				SwapPlayers(p, o);
			}
			else{ // do nothing
			}
		}
		else{ // lose
			if (p->getParent() == o){// do nothing
			}
			else{
				SwapPlayers(p, o);
			}

		}

	}
}


void GameBase::ShiftLayer(Player*& p, int layer, int delta = 0){
	if (p->IsARoot())
		delta = p->getLayer() - layer;
	if (delta != 0){
		p->setLayer(p->getLayer() - delta);
		if (!p->getChildren().empty()){
			vector<Player*>& current = p->getChildren();
			for (int i = 0; i < current.size(); i++){
				ShiftLayer(current[i], layer, delta);
			}
		}
	}
}

void GameBase::SwapPlayers(Player* p, Player * o){
	Player* temp = p;
	int i = p->getID();
	int j = o->getID();

	p->setID(o->getID());
	p->setXP(o->getXP());
	o->setID(temp->getID());
	o->setXP(temp->getXP());

	temp = p;
	this->Players[i] = o;
	this->Players[j] = temp;

	//Swap pointers
	Player* tempp = p;
	p = o;
	o = tempp;
}
