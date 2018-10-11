#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
/*
    THIS CLASS IS CONTRUCTED IN ORDER TO CREATE CHARACTERS
    A CHARACTER HAS EXPERIENCE POINTS LAYER REST INDICATOR AND PARENT NUMBER
    INITIALLY PARENT IS -1 (THERE EXIST NO PARENT)
    UNTIL CHARACTER LOSES A BATTLE IT WILL STAY -1

*/
using namespace std;

class character
{
private:
    int experience; //holds exp point
    int layer;  //holds layer information
    int parent; //holds parent (-1 initially)
    bool rest;
protected:
public:
        character(); //ctor
        int getexp();
        void setexp(int variable);
        int getlayer();
        void setlayer(int l);
        int getparent();
        void setparent(int p);
        bool getrest();
        void setrest(bool rst);
};

#endif // CHARACTER_H_INCLUDED
