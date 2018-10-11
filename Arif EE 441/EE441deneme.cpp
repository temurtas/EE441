#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <climits>
#include <string.h>
#include <stack>
using namespace std;

class Rectangle
{
private:
	float length;
	float width;
public:
	Rectangle(float l, float w)
	{
		length=l;
		width=w;

	};
	float Circumference(void) const
	{
		return 2*(length+width);
	};
	float Area(void) const
	{
		return (length*width);
	}
};

int main()
{
	float a,b,c;
	Rectangle *p;
	Rectangle R[3]={Rectangle(5.0,7.0), Rectangle(5.0,6.0),Rectangle(5.0,6.0)};
	p=R++;
	b=R[0].Circumference();
	a=(*p).Area();
	c=R[3].Area();
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;

}
