#include <iostream>
using namespace std;

/* class declaration */
enum Gender{male, female};

class Person
{

protected://new access control level used for inheritance
Gender gender;
int age;
public:
	void Info();
	Person (int a=0, Gender g=male);

};


Person::Person (int a, Gender g):age(a), gender(g)
{}


void Person::Info()
{
	cout<<"Gender:"<<gender<<" Age:"<<age<<"\n";
}

class Parent:public Person//Derived Class
{

private:
int children;
public:
Parent(int c=0): children(c)
{}
//Parent(int c, int a, Gender g):Person(a,g), children(c)//TRY THIS to pass arguments in the derived constructor
//{}

void Info();
void update();
};


//CHECK THIS LINK FOR MORE INFO:
//https://www.learncpp.com/cpp-tutorial/114-constructors-and-initialization-of-derived-classes/




void Parent::Info()//OVERWRITE
{
	cout<<"Gender:"<<gender<<" Age:"<<age<<" Number of Children:"<<children<<"\n";
}
void Parent::update( )//BRAND NEW
{
	cout<<"age:";
	cin>>age;
	cout<<"children:";
	cin>>children;
}
