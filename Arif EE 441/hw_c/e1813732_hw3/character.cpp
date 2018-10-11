#include "character.h"
#include "iostream"


using namespace std;

character::character()
{
    experience=100;
    layer=0;
    parent=-1;
    rest=0;
    //ctor
};

int character::getexp()
{
  return experience;
};
void character::setlayer(int l)
{
    layer=l;
};
int character::getlayer()
{
    return layer;
};
void character::setexp(int variable)
{
    if(variable>100 && variable < 200)
        experience=variable;
    else if (variable <= 100)
        experience=100;
    else
        experience=200;
};
int character::getparent()
{
    return parent;
};
void character::setparent(int p)
{
    parent=p;
};
bool character::getrest()
{
    return rest;
};
void character::setrest(bool rst)
{
    rest=rst;
};
