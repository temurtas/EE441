#include "GameTree.h"
#include "Player.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>

const int E_MAX = 200;
const int E_MIN = 100;

void swap(int*, int*);
void ShiftLayer(Player*&, int, int);

GameTree::GameTree(int _NumberOfPlayers, int NumberOfRoundsForWin){
	const int TurnsForWin = NumberOfRoundsForWin;
	NumberOfPlayers = _NumberOfPlayers;
	int round = 0;	// current round
	int turn = 0;	// current turn in current round

	randomSeq = new int[NumberOfPlayers];
	// random sequence for each turn
	Players = new Player[NumberOfPlayers];

	// Set IDs of players and create an ordered sequence.
	for (int i = 0; i < NumberOfPlayers; i++){
		Players[i].SetID(i);
		randomSeq[i] = i;
	}




}

// Shuffling the sequence uniform randomly...
void GameTree::ShuffleSeq() {
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



void GameTree::Fight(Player* p, Player* o, bool rootFight){
	bool IsWin = false;
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
		cout << "Win!";
		//Player Wins
		p->setXP(A + (C / A)*((E_MAX - A) / 2));  // E_player = E_player + (E_opp/E_player)*((E_max – E_player)/2)
		//Opponent Loses
		o->setXP(C - (C / A)*((C - E_MIN) / 3));  //  E_player = E_player - (E_player / E_opp)*(( E_player – E_min)/3)
		IsWin = true;
	}
	else if (random > effA - 1 && random <= effA + B - 1){
		cout << "Lose!";
		//Player Loses
		p->setXP(A - (A / C)*((A - E_MIN) / 2)); // E_player = E_player - (E_player /E_opp)*(( E_player – E_min)/2)
		//Opponent Wins
		o->setXP(C + (A / C)*((E_MAX - C) / 3)); // E_player = E_player + (E_opp/E_player)*((E_max – E_player)/3)
	}
	else {
		int opt;
		cout << "Draw!";
		// Draw
		cout << "Player " << o->getID() << ", what will you do?";
		cout << "\n\n1.Fight Back" << "\n2.Escape\n";
		cin >> opt;
		if (opt == 1) {
			Fight(o, p, rootFight); p->setXP(A - (A / C)*((A - E_MIN) / 4)); // Recursively call function swapping p and o...
		}
	}



	if (rootFight){
		if (IsWin){
			if (N == M + 1){

			}
			else if (N > M + 1){

			}
			else {
				ShiftLayer(p, M + 1, 0);
				p->getChildren()->AddNode(new ChildrenNode<Player>(o));
			}
		}
		else{ // lose


		}



	}
	else{ // not root fight




	}


}

// Change player's and its children' layers...
void ShiftLayer(Player*& p, int layer, int delta = 0){
	if (p->IsARoot())
		delta = p->getLayer() - layer;
	if (delta != 0){
		p->setLayer(p->getLayer() - delta);
		if (p->getChildren() != NULL){	// Check if the player has any grandchildren.
			ChildrenNode<Player>* current = p->getChildren()->next;
			while (current != nullptr){
				ShiftLayer(current->data, layer, delta);
				current = current->next;
			}
		}
	}



}
