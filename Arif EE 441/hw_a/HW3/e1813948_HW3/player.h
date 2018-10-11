#ifndef ___PLAYER___
#define ___PLAYER___

//#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Player
{
	private:
		int ID;
		int layer;
		double experience;
		int restFlag;
		Player* father;
	public:
		Player();
		Player(int ID);
		int getID();
		int getLayer();
		int getRest();
		double getExp();
		Player* getFather();
		void setFather(Player* father);
		void setExp(double experience);
		void setLayer(int layer);
		void setRest(int rest);
		void switchFatherChild(Player* father, Player* array, int numberOfPlayers); //switches the places of a child and father, works on the child and

};

#endif
