#ifndef _Player
#define _Player

#include "ChildrenNode.h"
#include <vector> // Linked list can be used instead of vector. However, it makes program complex and slow... 
using namespace std;

class Player {
private:
	int XP;
	int Layer;
	bool IsRoot;
	int ID;
	Player* Parent;
	vector<Player*> Children;


public:
	Player* parent = 0;
	Player(char);
	Player();
	int getID(){ return ID; }
	void SetID(int);
	int getLayer(){ return Layer; }
	void setLayer(int i){ Layer = i; }
	int getXP(){ return XP; }
	void setXP(int xp){ XP = xp; }
	bool IsARoot(){ return IsRoot; }
	Player* getParent(){ return parent; }
	ChildrenNode<Player>* getChildren(){ return Children; }
};


#endif