#include "player.cpp"
#include "player.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <tgmath.h>


#define expMax 200
#define expMin 100


inline void randomSequence(int* sequence, int numberOfPlayers){ //randomizes the turn sequence when it is called
	int i,j;
	srand(time(NULL));
	j=rand()%numberOfPlayers;
	for(i=0;i<numberOfPlayers;i++)
		*(sequence+i)=-1;	//initialize the sequence
	for(i=0;i<numberOfPlayers;i++){
		while(*(sequence+j)>=0)
			j=rand()%numberOfPlayers; //randomize all elements of the sequence
		*(sequence+j)=i;
	}
}

inline void printSequence(int* sequence, int numberOfPlayers){ //prints the randomized sequence in order
	int i=0;
		cout<<*(sequence);
	for(i=1;i<numberOfPlayers;i++)
		cout<<", "<<*(sequence+i);

}

inline int printMenuRest(){ //this is the menu provided to a player who has right to "rest" in that turn
	int choice=0;
	while(!(choice==1||choice==2||choice==3)){ //players are resitricted to choose one of the available options only
		cout<<"1. Fight!"<<endl;
		cout<<"2. Rest"<<endl;
		cout<<"3. Look players' status"<<endl;
		cin>>choice;
		if(!(choice==1||choice==2||choice==3))
			cout<<"Error: Invalid selection! Please select one of the available options:"<<endl; //if selection is invalid
	}
	return choice;
}

inline int printMenuNoRest(){ //this is the menu provided to a player who has NO right to "rest" in that turn
	int choice=0;
	while(!(choice==1||choice==3)){ //players are resitricted to choose one of the available options only
		cout<<"1. Fight!"<<endl;
		cout<<"2. Rest! (You are not allowed to rest!)"<<endl;
		cout<<"3. Look players' status"<<endl;
		cin>>choice;
		if(!(choice==1||choice==3)){
			if(choice==2)
				cout<<"Error: You are not allowed to rest in this turn!"<<endl; //if player who has no right selects to rest
			else
				cout<<"Error: Invalid selection! Please select one of the available options:"<<endl; //if selection is invalid
		}
	}
	return choice;
}

inline int printMenuFightBack(){// this is the menu provided to a player who has right to Fight Back in turn!!
	int choice=0;
	while(!(choice==1||choice==2)){ //players are resitricted to choose one of the available options only
		cout<<"1. Fight Back!"<<endl;
		cout<<"2. Escape"<<endl;
		cin>>choice;
		if(!(choice==1||choice==2))
			cout<<"Error: Invalid selection! Please select one of the available options:"<<endl; //if selection is invalid
	}
	return choice;
}

inline int findtoFight(int mover, Player* array, int numberOfPlayers){ //this is the menu provided to a player who wants to fight

	int choice=-1, i, checker; //players are only allowed to choose one the available players to fight;
	
	if((array+mover)->getFather()==NULL){
		cout<<"--------------------------------------------------------------------------"<<endl;
		label:
		cout<<"Please, choose an available player (";
		checker=0;
		for(i=0;i<numberOfPlayers;i++)
		{
			if(i!=mover){
				if((array+i)->getFather()==NULL){// list all roots to fight and set checker conditioner
					if(checker>0)
						cout<<",";
					cout<<i;
					checker++;
				}
			}

		}
		cout<<")"<<endl;

		if(checker){
			cin>>choice;
			if(choice>=numberOfPlayers||choice<0){
				cout<<"Error: Invalid player ID!"<<endl; //error if player doesnt exist
				goto label;
			}
			else if(((array+choice)->getFather()!=NULL)||choice==mover){
				cout<<"Error: You cannot fight this player!"<<endl; //error if player is not a root
				goto label;
			}
		}
		else{ // if the player is the only root and there is no one to fight! returns -1
			choice=-1;
			cout<<"Since you are the only root you cannot fight!! You lost your turn."<<endl;
		}
	}

	else{
		i=(array+mover)->getFather()->getID(); //if the player has father, the only player it can fight is its father
		cout<<"--------------------------------------------------------------------------"<<endl;
		while(choice!=i){ // player is forced to choose its father
			cout<<"Please, choose an available player ( "<<i<<" )"<<endl;
			cin>>choice;
			if(choice>=numberOfPlayers||choice<0)
				cout<<"Error: Invalid player ID!"<<endl; //error if player doesnt exist
			else if(choice!=i)
				cout<<"Error: You cannot fight this player!"<<endl;//error if the player selected is not available for fight
		}
	}

	return choice; //returns the ID of the player to fight properly
}

inline int Fight(Player* mover, Player* opponent, int numberOfPlayers){ //Takes two fighters first of which is host
	int A,B,C,die; //all probabilities are calculated accordingly including layer effect

	A=round(mover->getExp()*(1+(opponent->getLayer()-mover->getLayer())/numberOfPlayers));//intervals are calculated
	B=round((expMax-expMin)-abs(mover->getExp()-opponent->getExp()));
	C=round(opponent->getExp());

	cout<<"--------------------------------------------------------------------------"<<endl; //print intervals
	cout<<"Win, lose and draw intervals are: "<<A<<"-"<<B<<"-"<<C<<endl;

	die=rand()%(A+B+C); //get result

	cout<<"Random number is: "<<die; // switch result for win, lose or draw and return a result to be evaluated in the main code

	if(die<A){
		cout<<", Win!"<<endl;
		return 1;
	}
	else if(die<(A+B)){
		cout<<", Lose!"<<endl;
		return 2;
	}
	else{
		cout<<", Draw!"<<endl;
		return 3;
	}

}

inline void editLayers(Player* array, int numberOfPlayers){ //after a fight, this function is called and it organizes the layers properly
	int i,j;
	for(i=0;i<numberOfPlayers;i++)
	{
		for(j=0;j<numberOfPlayers;j++) //looks the players array number of players times and correct layers of players if they are not correct
		{
			if((array+j)->getFather()!=NULL)
				(array+j)->setLayer((array+j)->getFather()->getLayer()-1);
		}
	}
}

inline void hostWinner(Player* host, Player* guest, Player* Players, int numberOfPlayers){//if the player's turn and it wins

	host->setExp(host->getExp()+(guest->getExp()/host->getExp())*((expMax-host->getExp())/2)); //updates experience points
	guest->setExp(guest->getExp()-(guest->getExp()/host->getExp())*((guest->getExp()-expMin)/3));

	if(host->getFather()==NULL){ //it was the fight of two roots
		guest->setFather(host); //unites two trees
		if(host->getLayer()==(guest->getLayer()+1)){

		}
		else if(host->getLayer()>(guest->getLayer()+1)){ //organizes the layers
			guest->setLayer(host->getLayer()-1);
			editLayers(Players, numberOfPlayers);
		}
		else{
			host->setLayer(guest->getLayer()+1); //organizes the layers
			editLayers(Players, numberOfPlayers);
		}
	}

	else {
		host->switchFatherChild(guest, Players, numberOfPlayers); //switches the places of father and child if child has won


	}

	cout<<"--------------------------------------------------------------------------"<<endl; //prints the new status of the involved players
	cout<<"Player "<<host->getID()<<" new experience point: "<<host->getExp()<<" new layer: "<<host->getLayer()<<endl;
	cout<<"Player "<<guest->getID()<<" new experience point: "<<guest->getExp()<<" new layer: "<<guest->getLayer()<<endl;
}

inline void hostLoser(Player* host, Player* guest, Player* Players, int numberOfPlayers){//if the player's turn and it losts

	guest->setExp(guest->getExp()+(host->getExp()/guest->getExp())*((expMax-guest->getExp())/3)); //updates the experience points
	host->setExp(host->getExp()-(host->getExp()/guest->getExp())*((host->getExp()-expMin)/2));

	if(host->getFather()==NULL){ //if it was the fight of two roots
		host->setFather(guest); //unites trees
		if(guest->getLayer()==(host->getLayer()+1)){

		}
		else if(guest->getLayer()>(host->getLayer()+1)){ //edits layers
			host->setLayer(guest->getLayer()-1);
			editLayers(Players, numberOfPlayers);
		}
		else{
			guest->setLayer(host->getLayer()+1); //edits layers
			editLayers(Players, numberOfPlayers);
		}
	}

	else{ //if it was the fight of a child with father and father wins, nothing will change besides the experience points

	}

	cout<<"--------------------------------------------------------------------------"<<endl; //prints the new status of the players
	cout<<"Player "<<host->getID()<<" new experience point: "<<host->getExp()<<" new layer: "<<host->getLayer()<<endl;
	cout<<"Player "<<guest->getID()<<" new experience point: "<<guest->getExp()<<" new layer: "<<guest->getLayer()<<endl;
	
}

inline int findLeader(Player* array, int numberOfPlayers){ //returns the leader if exists
	int counter=0, i;
	for(i=0;i<numberOfPlayers;i++)
	{
		if((array+i)->getFather()==NULL) //look for all players and find the roots
			counter++;
	}
	if(counter>1) // if there exist multple roots, there is no leader, so returns -1
		return -1;
	else
	{
		for(i=0;i<numberOfPlayers;i++)
		{
			if((array+i)->getFather()==NULL) //if leader exists, finds its ID and returns it
				return i;
		}
	}

}