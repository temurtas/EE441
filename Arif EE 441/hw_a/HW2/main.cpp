#include "ee.cpp"
#include <iostream>   // std::cout
#include <string>

#include <sstream>      // std::stringstream
#define COLUMN_WIDTH 20


string putPlus(int number1,int number2)
{
	stringstream numString1;
	stringstream numString2;
	string realString1 = "";
	string realString2 = "";
	numString1<<number1;
	numString2<<number2;
	if(number2 == 360)
		if(number1>0)
			return "+"+ numString1.str();
		else
			return numString1.str();
	if(number1>0)
		realString1 = "+" + numString1.str();
	else
		realString1 = numString1.str();
	if(number2>0)
		realString2 = "+" + numString2.str();
	else
		realString2 = numString2.str();
	
	return realString1 + ", " + realString2;
}

int findMax(AirCraft *myAirCraft)
{
	int max = 0;
	Capsule* temp = myAirCraft->getHead();
	stringstream ss1;
	stringstream ss2;
	stringstream ss3;
	ss1<<abs(myAirCraft->getLatitude());
	ss2<<abs(myAirCraft->getLongitude());
	max = (ss1.str()+ss2.str()+"+, +").size();
	while(temp!=NULL)
	{
		ss1.str("");
		ss1.clear();
		ss2.str("");
		ss2.clear();
		ss3.str("");
		ss3.clear();
		ss1<<(temp->getCID());
		ss2<<abs(temp->getLatitude());
		ss3<<abs(temp->getLongitude());
		if(temp->getName().size()>max)
			max = temp->getName().size();
		if(ss1.str().size()>max)
			max = ss1.str().size();
		if((ss2.str()+ss3.str()+"+, +").size()> max )
			max = (ss2.str()+ss3.str()+"+, +").size();
		temp = temp->getChild();
	}
	return max;
}

Capsule* printAirCraftInfo(AirCraft *myAirCraft,int max)
{
	Capsule* temp = myAirCraft->getHead();

	Capsule* temp2 = NULL;	
	string line = "";
	string line2= putPlus(myAirCraft->getLatitude(),myAirCraft->getLongitude());
	string line3 = putPlus(myAirCraft->getDirection(),360);
	for(int i=0;i<max+COLUMN_WIDTH;i++)
		line +="=";
	// print aircraft info
	cout<<line<<endl;
	cout.width(COLUMN_WIDTH);cout<<left<<myAirCraft->getName()<<endl;
	cout.width(COLUMN_WIDTH);cout<<left<<"Departure:"<<line2<<endl;
	cout.width(COLUMN_WIDTH);cout<<left<<"Direction:"<<line3<<endl;
	cout<<line<<endl;
	//print capsule info
	while(temp!=NULL)
	{
		string line2= putPlus(temp->getLatitude(),temp->getLongitude());

		cout<<line<<endl;
		cout.width(COLUMN_WIDTH);cout<<left<<"Name:"<<temp->getName()<<endl;
		cout.width(COLUMN_WIDTH);cout<<left<<"CID:"<<temp->getCID()<<endl;
		cout.width(COLUMN_WIDTH);cout<<left<<"Destination:"<<line2<<endl;
		cout<<line<<endl;
		temp2 = temp;
		temp = temp->getChild();
	}
	return temp2;
}

void SimulateFlight(AirCraft *myAirCraft)
{
	Capsule* temp;
	string line="",line2="";
	int max=0;
	max = findMax(myAirCraft);	
	temp=printAirCraftInfo(myAirCraft,max);
	cout<<"The simulation starts..."<<endl;
	while(temp!=NULL)
	{
		line2= putPlus(temp->getLatitude(),temp->getLongitude());
		line="";
		for(int i=0;i<max+COLUMN_WIDTH;i++)
			line +="=";
		cout<<line<<endl;
		cout<<"Dropped Capsule:"<<endl;
		cout.width(COLUMN_WIDTH);cout<<left<<"Name:"<<temp->getName()<<endl;
		cout.width(COLUMN_WIDTH);cout<<left<<"CID:"<<temp->getCID()<<endl;
		cout.width(COLUMN_WIDTH);cout<<left<<"Destination:"<<line2<<endl;
		cout<<line<<endl;
		myAirCraft->dropCapsule();
		cout<<"Current AirCraft"<<endl;
		max = findMax(myAirCraft);
		temp=printAirCraftInfo(myAirCraft,max);
		cout<<"***"<<endl;
	}
	cout<<"The simulation has been ended."<<endl;
}



int main()
{
	AirCraft* airCraft;
	int menuChoice = 0;
	int latitude,longitude,fDirection;
	while(1)
	{
		cout<<"EE Tech Easy Everywhere Simulator"<<endl;
		cout<<"(1) New Flight"<<endl<<"(2) Exit"<<endl;
		cin>>menuChoice;
		if(menuChoice==1)
		{
			cout<<"Input Departure Latitude, Longitude and Flight Direction: "<<endl;
			cin>>latitude>>longitude>>fDirection;
			airCraft = new AirCraft(latitude,longitude,fDirection);
			while(1)
			{
				cout<<"EE Tech Easy Everywhere Simulator"<<endl;
				cout<<"(1) New Passenger"<<endl<<"(2) Close Registration and Simulate the Flight"<<endl;
				cin>>menuChoice;
				if(menuChoice == 1)
				{
					string passName;
					int passCID;
					cout<<"Name of the passenger: "<<endl;
					cin.ignore();
					getline(cin,passName);
					cout<<"CID of the passenger: "<<endl;
					cin>>passCID;
					cout<<"Destination(Lat. & Long): "<<endl;
					cin>>latitude>>longitude;
					Capsule* newCapsule = new Capsule(passName,passCID,latitude,longitude,airCraft->getLongitude(),airCraft->getDirection());
					airCraft->integrate(newCapsule);
					cout<<"New passenger has been successfully registered."<<endl;

				}
				else if (menuChoice==2)
					break; 	
			}
			cout<<"The registration has been closed and the aircraft to take off is: "<<endl;
			SimulateFlight(airCraft);
			delete airCraft;
		}
		else if (menuChoice==2)
			return 0;
	}
	return 0;
}