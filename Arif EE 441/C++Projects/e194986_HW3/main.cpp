#include <iostream>
#include "Player.h"
#include "GameBase.h"
#include <time.h>
#include <cstdlib>

const int E_MAX = 200;
const int E_MIN = 100;

void ShowOptions();
using namespace std;
int main(){
	int num, rturns; // num: number of players, rturns: required turn
	int cturn = 0, cround = 1; // cturn: current turn, cround: current round
	cout << "Enter number of players: ";
	cin >> num;

	cout << "Required turns for win: ";
	cin >> rturns;

	srand(time(NULL));
	GameBase base(num, rturns);     // GameBase for new game
	base.ShuffleSeq(); // Shuffle and get a new uniformly random sequence

	int option = 0;         // Menu option
	int playerid;
	int opponentid;
	Player* currentPlayer;
	Player* opponent;

	while (cround > 0){
		cout << "\nRound "<< cround <<" turn(move) sequence: ";
		for (int i = 0; i < num; i++){ cout << base.GetSeq()[i] << (i == num - 1 ? "\n" : ", "); }
		for (cturn = 0; cturn < num; cturn++){

			//Ask current player what to do...
			currentPlayer = base.getPlayer(base.GetSeq()[cturn]);
			cout << "\n\n------------------------------\n";
			cout << "Player " << base.GetSeq()[cturn] << ", what will you do?";
			ShowOptions();
			cin >> option;

			// FIGHT
			if (option == 1){
				// If player is a root then opponents must be root. Search for root players...
				if (currentPlayer->IsARoot()){
					cout << "Available opponents:";
					for (int j = 0; j < num; j++){
						if (base.getPlayer(j)->IsARoot() && j != currentPlayer->getID()){ cout << j; cout << " "; }
					}
					cin >> opponentid;
					opponent = base.getPlayer(opponentid);
					base.Fight(currentPlayer, opponent, true);
					cout << "Experience point is " << currentPlayer->getXP() << ".\n";
				}

				// If not a root. Fight against parent.
				else{
					base.Fight(currentPlayer, currentPlayer->getParent(), false);
					cout << "Experience point is " << currentPlayer->getXP() << ".\n";
				}

			}

			// REST
			else if (option == 2){
				currentPlayer->setXP(currentPlayer->getXP() + (E_MAX - currentPlayer->getXP()) / 2);
				cout << "Experience point is " << currentPlayer->getXP() << ".\n";
			}

			// SEE STATUS
			else if (option == 3){
				cout << "Choose a player (less than " << num + 1 << "): ";
				cin >> playerid;
				cout << "Player " << playerid << " is in layer " << base.getPlayer(playerid)->getLayer();
				cout << " with " << base.getPlayer(playerid)->getXP() << " experience point\n";
				cturn--;
			}
		}

		base.ShuffleSeq(); // Shuffle and get a new uniformly random sequence for the new round
		cround++;           // Next round
	}
	return 0;
}

void ShowOptions(){
	cout << "\n\n1.Fight" << "\n2.Rest" << "\n3.See players' status\n";
}
