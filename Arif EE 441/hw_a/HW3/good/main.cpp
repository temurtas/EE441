#include "player.cpp"
#include "functions.cpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int numberOfPlayers=0, finishCondition=0, topPlayer=0, turn=1, i, leader=-2, counter=0, checker; //declarations of variables to be used
	int mover, opponent, choice, choice1, result, result1, look, lookplayer=-1, fightback;
	double E_player, E_opp;
	int *sequence;	//a pointer to integer to create an array dynamically accordin to number of players to indicate the turn sequence
	Player* Players; //a pointer to Player object to create a dynamic array containing all the players in order 

	cout<<"--------------------------------------------------------------------------"<<endl; 
	cout<<"Welcome to our game!"<<endl;
	while(numberOfPlayers<2){
		cout<<"Enter number of players (at least 2):"<<endl; //repeat while the user input is less than 2
		cin>>numberOfPlayers;
		if(numberOfPlayers<2)
			cout<<"Error: Invalid number of players!"<<endl;
		
	}
	while(topPlayer<1){ //repeat while the user input is less than 1
		cout<<"How many turns does a player stay in the top layer to win a game (at least 1)?"<<endl;
		cin>>topPlayer;
		if(topPlayer<1)
			cout<<"Error: Invalid number of turns to win!"<<endl;
	}
	Players= new Player[numberOfPlayers];	//dynamically allocate memory for players
	sequence= new int[numberOfPlayers];	//dynamically allocate memory for turn sequence

	for(i=0;i<numberOfPlayers;i++)
		Players[i]=Player(i);	//initialize the players

	while(finishCondition!=1){	//continue if the game is on (non of the players stayed in the top layer for given number of turns)
		randomSequence(sequence, numberOfPlayers);	//randomize the sequence for each turn and print it.
		cout<<"--------------------------------------------------------------------------"<<endl;
		cout<<"Round "<<turn<<" turn sequence: ";
		printSequence(sequence, numberOfPlayers);
		cout<<endl;
		mover=0; //initialize the first player to make a move

		while(mover<numberOfPlayers){ //continue by increasing mover until a turn is completed
			cout<<"--------------------------------------------------------------------------"<<endl;
			cout<<"Player "<<sequence[mover]<<", what's your choice?"<<endl;
			if((Players+sequence[mover])->getRest()==0)
				choice=printMenuRest(); //returns only 1 or 2 or 3 depending on the player's selection
			else
				choice=printMenuNoRest(); //returns only 1 or 3 depending on the player's selection

			if(choice==1){ //fight is chosen
				look=1; //set the look flag
				(Players+sequence[mover])->setRest(0); //clear player's restFlag
				choice1=findtoFight(sequence[mover], Players, numberOfPlayers); //returns a valid selection of player to be fought
				if(choice1!=-1){//player is not the only root so a fight is available
					result=Fight((Players+sequence[mover]), (Players+choice1), numberOfPlayers);
				}
				else result=0; //if the player is the only root set the result to -1, in this case nothing will happen
				if(result==1)//mover wins!!
				{
					hostWinner((Players+sequence[mover]), (Players+choice1), Players, numberOfPlayers); //organize the structures of trees,layers
				}
				else if(result==2)//mover lost!!
				{
					hostLoser((Players+sequence[mover]), (Players+choice1), Players, numberOfPlayers); //organize the structures of trees,layers
				}
				else if(result==3)//draw!!
				{
					cout<<"--------------------------------------------------------------------------"<<endl;
					cout<<"Player "<<choice1<<", what's your choice?"<<endl; //opponent will take the stage and selects to fight back or escape
					fightback=printMenuFightBack(); //it returns only 1 or 2 depending on th eoppnnets selection
					if(fightback==1){ //fightback is chosen
						E_player=(Players+sequence[mover])->getExp();
						E_opp=(Players+choice1)->getExp();

						(Players+sequence[mover])->setExp(E_player-(E_player/E_opp)*((E_player-expMin)/4));
								//experience point is updated for the player who has the turn in the first place
						if((Players+sequence[mover])->getFather()==(Players+choice1)) //if there is father child relation
							(Players+sequence[mover])->switchFatherChild((Players+choice1), Players, numberOfPlayers); //pre-switch father&child

						result1=Fight((Players+choice1), (Players+sequence[mover]), numberOfPlayers); //fight the players, opponent is the host

						if(result1==1) //opponent wins as host, note the order of the players in the function, it is placed accordingly
							hostWinner((Players+choice1), (Players+sequence[mover]), Players, numberOfPlayers);
							//if there is father-child relation and child wins it automatically switches them properly

						else if (result1==2) //opponent losts as host, note the order of the players in the function, it is placed accordingly
							hostLoser((Players+choice1), (Players+sequence[mover]), Players, numberOfPlayers);

						else if (result1==3){  //draw again
							if((Players+sequence[mover])==(Players+choice1)->getFather()) //draw again, nothing will happen
								(Players+choice1)->switchFatherChild((Players+sequence[mover]), Players, numberOfPlayers);
							//but we have to take back the pre-switch which we make to get things easier

							cout<<"--------------------------------------------------------------------------"<<endl; //prints the new status
							cout<<"Player "<<sequence[mover]<<" new experience point: "<<(Players+sequence[mover])->getExp();
							cout<<" new layer: "<<(Players+sequence[mover])->getLayer()<<endl;
							cout<<"Player "<<choice1<<" new experience point: "<<(Players+choice1)->getExp();
							cout<<" new layer: "<<(Players+choice1)->getLayer()<<endl;
						}

					}
					else if(fightback==2){ //player has escaped, prints the status and continues
						cout<<"--------------------------------------------------------------------------"<<endl;
						cout<<"Player "<<sequence[mover]<<" new experience point: "<<(Players+sequence[mover])->getExp();
						cout<<" new layer: "<<(Players+sequence[mover])->getLayer()<<endl;
						cout<<"Player "<<choice1<<" new experience point: "<<(Players+choice1)->getExp();
						cout<<" new layer: "<<(Players+choice1)->getLayer()<<endl;
					}
					
				}
			}

			else if(choice==2){//rest is chosen
				look=1; //set look flag
				(Players+sequence[mover])->setRest(1); //set restFlag
				(Players+sequence[mover])->setExp((Players+sequence[mover])->getExp()+(expMax-(Players+sequence[mover])->getExp())/2);

				//updates the experience points and prints new data
				cout<<"--------------------------------------------------------------------------"<<endl;
				cout<<"Player "<<sequence[mover]<<" new experience point: "<<(Players+sequence[mover])->getExp();
				cout<<" new layer: "<<(Players+sequence[mover])->getLayer()<<endl;

			}

			else if(choice==3){//look status is chosen
				look=0; //clear look flag

				cout<<"--------------------------------------------------------------------------"<<endl;
				while((lookplayer<0)||(lookplayer>=numberOfPlayers)){//takes a proper player ID and shows its data
					cout<<"Choose a player (less than "<<numberOfPlayers<<")"<<endl;
					cin>>lookplayer;
					if((lookplayer<0)||(lookplayer>=numberOfPlayers))
						cout<<"Error: Invalid player ID!"<<endl;
				}
				cout<<"Player "<<lookplayer<<" is in layer "<<(Players+lookplayer)->getLayer();
				cout<<" and Player "<<lookplayer<<" has "<<(Players+lookplayer)->getExp()<<" experience points"<<endl;

			}

			if(look){ //if the action was not look player status, increase the mover and give the turn to the next player in the sequence
				mover++;
			}
		}
		//at the end of the turn we check for the leader
		checker=findLeader(Players, numberOfPlayers);
		if(checker!=-1) //there is leader
		{
			if(checker==leader) //if it is the old one, increase the counter
				counter++;
			else{
				leader=checker; //if it is new one, update leader and reset counter
				counter=1;
			}
		}
		else if(checker==-1) //no leader, counter is reset
		{
			counter=0;
		}
		if(counter==topPlayer) // if counter reaches the predefined valuei set finishcondition and end the game
			finishCondition=1;
		turn++;
	}

	cout<<"--------------------------------------------------------------------------"<<endl;
	cout<<"The game is over. Winner is Player "<<leader<<endl; //prints the winner
	delete []Players;
	delete []sequence; //deallocate dynamically created objects and end the program
}