#ifndef _Player
#define _Player

#include <vector> // Linked list can be used instead of vector. However, it makes program complex and slow...
using namespace std;

class Player {
private:
	int ID;
	int Layer;
	int XP;
	bool IsRoot;

	Player* Parent;
	vector<Player*> Children;

public:
    // Constructors
	Player(char);
	Player();

	// Getters and setters
	int getID(){ return ID; }
	void setID(int id){ ID = id; }
	int getLayer(){ return Layer; }
	void setLayer(int i){ Layer = i; }
	int getXP(){ return XP; }
	void setXP(int xp){ XP = xp; }
	bool IsARoot(){ return IsRoot; }
	void setRoot(bool q){ IsRoot = q; }
	Player* getParent(){ return Parent; }
	void setParent(Player* p){ Parent = p; }
	vector<Player*>& getChildren(){ return Children; }
	void setChildren(vector<Player*>& v){ Children = v; }

};


#endif
