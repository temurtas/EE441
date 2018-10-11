#include <iostream>
#include "Player.h"
#include "GameTree.h"
#include <time.h>



void ShowOptions();
using namespace std;
int main(){
	int num, rturns;
	int cturn = 0, cround = 1;
	cout << "Enter number of players: ";
	cin >> num;

	cout << "Required turns for win: ";
	cin >> rturns;

	srand(time(NULL));
	GameTree base(num, rturns);
	base.ShuffleSeq();

	int option = 0;
	int playerid;
	int opponentid;
	Player* currentPlayer;
	Player* opponent;

	while (cround > 0){
		cout << "\nRound 1 turn(move) sequence: ";
		for (int i = 0; i < num; i++){ cout << base.GetSeq()[i] << (i == num - 1 ? "\n" : ", "); }
		for (cturn = 0; cturn < num - 1; cturn++){
			currentPlayer = base.getPlayer(base.GetSeq()[cturn]);
			cout << "Player " << base.GetSeq()[cturn] << ", what will you do?";
			ShowOptions();
			cin >> option;
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
				}

				// If not a root. Fight against parent.
				else{
					base.Fight(currentPlayer, currentPlayer->parent, false);
				}

			}
			else if (option == 3){
				cout << "Choose a player (less than " << num + 1 << "): ";
				cin >> playerid;
				cout << "Player " << playerid << " is in layer " << base.getPlayer(playerid)->getLayer();
				cout << " with " << base.getPlayer(playerid)->getXP() << " experience point\n";
				cturn--;
			}








		}


	}
	return 0;
}

void ShowOptions(){
	cout << "\n\n1.Fight" << "\n2.Rest" << "\n3.See players' status\n";
}