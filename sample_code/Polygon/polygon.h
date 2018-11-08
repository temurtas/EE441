#include "stdio.h"
#include "iostream"
#include "stdlib.h"

//PLEASE CHECK:
//http://www.learncpp.com/cpp-tutorial/114-constructors-and-initialization-of-derived-classes/
//for further information

using namespace std;
enum Color {red, blue, green};

class Polygon
{
protected:
int width, height;
public:
Polygon(int w=0, int h=0);
void set_values(int w, int h)
{
    width=w;
    height=h;
}
virtual int Area()
{return (0);}
};


Polygon::Polygon (int w, int h)
{
    width=w;
    height=h;
}

class Rectangle:public Polygon
{
protected:
    Color renk;
public:
//inherits the constructor
Rectangle(int w=0, int h=0, Color r=red):Polygon(w, h), renk(r)
{}

int Area()
{
    return width*height;
}

Color TellColor()
{
    return renk;
}
};





class Triangle:public Polygon
{
public:

//inherits the constructor
Triangle(int w=0, int h=0):Polygon(w, h)
{}
int Area()
{return width*height/2;}
};



