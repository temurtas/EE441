//===================================================
//Program: EE-Tech Product Coparison
//File: hw1.cpp
//Function: main
//Description: make a product database parsing a txt file and add new products, make comparisons
//Author: Aykut DEMIREL - EE441: Section 3: Student number 1813948:
//===================================================




//Header Files
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

//class declaration
class ElectronicProduct
{
	public:
		int productID,deviceRam,deviceMemory;
		float deviceCpu,screenSize,batteryLife,price,deviceBenefit,priceOverPerformance;
		string productName,producType,opticalDevice;
		bool has4g,hasBluetooth,hasWifi,hasHdmi,hasUsb,hasFrontCamera;
	ElectronicProduct()//initialize the declared class object
	{
		productID=0;
		deviceRam=0;
		deviceMemory=0;
		deviceCpu=0;
		screenSize=0;
		batteryLife=0;
		price=0;
		deviceBenefit=0;
		priceOverPerformance=0;
		productName="";
		producType="";
		opticalDevice="";
		has4g=false;
		hasBluetooth=false;
		hasWifi=false;
		hasHdmi=false;
		hasUsb=false;
		hasFrontCamera=false;
	}
};


//Finds the relevant properties of the object according to its type
void findRelevantProperties(ElectronicProduct product,int *p)
{
	
	if(product.producType=="Smartphone"||product.producType=="LaptopComputer"||product.producType=="GameConsole")
	{	*p=1;
		*(p+1)=1;
		*(p+2)=1;
		*(p+6)=1;}
	if(product.producType=="Smartphone"||product.producType=="LaptopComputer"||product.producType=="TV")
	*(p+3)=1;
	if(product.producType=="Smartphone"||product.producType=="LaptopComputer")
	*(p+4)=1;
	if(product.producType=="Smartphone")
	{	*(p+5)=1;
		*(p+10)=1;}
	if(product.producType=="TV" || product.producType=="GameConsole")
	{	*(p+7)=1;
		*(p+9)=1;}
	if(product.producType=="LaptopComputer"||product.producType=="TV")
		*(p+8)=1;
	if(product.producType=="LaptopComputer"||product.producType=="GameConsole")
	*(p+11)=1;
}

//dislplays the new entered product info
void printProduct(ElectronicProduct product)
{
	cout<<"Product ID:	"<<product.productID<<endl;
	cout<<"Product Name:	"<<product.productName<<endl;
	cout<<"Product Type:	"<<product.producType<<endl;
	int props[12]={};
	int kl;
	findRelevantProperties(product, props);
	
	if (props[0]) cout<<"deviceCpu:	"<<product.deviceCpu<<" GHz"<<endl;
	if (props[1]) cout<<"deviceRam:	"<<product.deviceRam<<" GB"<<endl;
	if (props[2]) cout<<"deviceMemory:	"<<product.deviceMemory<<" GB"<<endl;
	if (props[3]) cout<<"screenSize:	"<<product.screenSize<<" Inch"<<endl;
	if (props[4]) cout<<"batteryLife:	"<<product.batteryLife<<" h"<<endl;
	if (props[5]) cout<<"has4g:	"<<product.has4g<<endl;
	if (props[6]) cout<<"hasBT:	"<<product.hasBluetooth<<endl;
	if (props[7]) cout<<"hasWifi:	"<<product.hasWifi<<endl;
	if (props[8]) cout<<"hasHdmi:	"<<product.hasHdmi<<endl;
	if (props[9]) cout<<"hasUsb:	"<<product.hasUsb<<endl;
	if (props[10]) cout<<"hasFrontCamera:	"<<product.hasFrontCamera<<endl;
	if (props[11]) cout<<"opticalDevice:	"<<product.opticalDevice<<endl;
	cout<<"Price:	"<<product.price<<" TL\n==================================\n"<<endl;
}

//used for dislaying all products, only outs PID, Name and Type
void displayProduct(ElectronicProduct product)
{
	cout.width(10);cout<<left<<product.productID;
	cout.width(17);cout<<left<<product.producType;
	cout.width(17);cout<<left<<product.productName<<endl;
}

//outputs the selected 3 products and compares and prints the result
void compareProduct(ElectronicProduct product1, ElectronicProduct product2, ElectronicProduct product3)
{
	int atts[12]={};
	findRelevantProperties(product1, atts);
	string best;

	if(product1.priceOverPerformance<=product2.priceOverPerformance)
	{
		if(product1.priceOverPerformance<=product3.priceOverPerformance)
			best=product1.productName;
		else best=product3.productName;
	}
	else
	{
		if(product2.priceOverPerformance<=product3.priceOverPerformance)
			best=product2.productName;
		else best=product3.productName;
	}

	if (atts[0])
	{
		cout.width(20);cout<<left<<"CPU (GHz):";
		cout.width(17);cout<<left<<product1.deviceCpu;
		cout.width(17);cout<<left<<product2.deviceCpu;
		cout.width(17);cout<<left<<product3.deviceCpu<<endl;
	}
	if (atts[1])
	{
		cout.width(20);cout<<left<<"RAM (GB):";
		cout.width(17);cout<<left<<product1.deviceRam;
		cout.width(17);cout<<left<<product2.deviceRam;
		cout.width(17);cout<<left<<product3.deviceRam<<endl;
	}
	if (atts[2])
	{
		cout.width(20);cout<<left<<"Memory (GB):";
		cout.width(17);cout<<left<<product1.deviceMemory;
		cout.width(17);cout<<left<<product2.deviceMemory;
		cout.width(17);cout<<left<<product3.deviceMemory<<endl;
	}
	if (atts[3])
	{
		cout.width(20);cout<<left<<"Screen (Inch):";
		cout.width(17);cout<<left<<product1.screenSize;
		cout.width(17);cout<<left<<product2.screenSize;
		cout.width(17);cout<<left<<product3.screenSize<<endl;
	}
	if (atts[4])
	{
		cout.width(20);cout<<left<<"Bat.Life (Hours):";
		cout.width(17);cout<<left<<product1.batteryLife;
		cout.width(17);cout<<left<<product2.batteryLife;
		cout.width(17);cout<<left<<product3.batteryLife<<endl;
	}
	if (atts[5])
	{
		cout.width(20);cout<<left<<"Has 4g?";
		cout.width(17);cout<<left<<product1.has4g;
		cout.width(17);cout<<left<<product2.has4g;
		cout.width(17);cout<<left<<product3.has4g<<endl;
	}
	if (atts[6])
	{
		cout.width(20);cout<<left<<"Has BT?";
		cout.width(17);cout<<left<<product1.hasBluetooth;
		cout.width(17);cout<<left<<product2.hasBluetooth;
		cout.width(17);cout<<left<<product3.hasBluetooth<<endl;
	}
	if (atts[7])
	{
		cout.width(20);cout<<left<<"Has WIFI?";
		cout.width(17);cout<<left<<product1.hasWifi;
		cout.width(17);cout<<left<<product2.hasWifi;
		cout.width(17);cout<<left<<product3.hasWifi<<endl;
	}
	if (atts[8])
	{
		cout.width(20);cout<<left<<"Has HDMI?";
		cout.width(17);cout<<left<<product1.hasHdmi;
		cout.width(17);cout<<left<<product2.hasHdmi;
		cout.width(17);cout<<left<<product3.hasHdmi<<endl;
	}
	if (atts[9])
	{
		cout.width(20);cout<<left<<"Has USB?";
		cout.width(17);cout<<left<<product1.hasUsb;
		cout.width(17);cout<<left<<product2.hasUsb;
		cout.width(17);cout<<left<<product3.hasUsb<<endl;
	}
	if (atts[10])
	{
		cout.width(20);cout<<left<<"Has FCam?";
		cout.width(17);cout<<left<<product1.hasFrontCamera;
		cout.width(17);cout<<left<<product2.hasFrontCamera;
		cout.width(17);cout<<left<<product3.hasFrontCamera<<endl;
	}
	if (atts[11])
	{
		cout.width(20);cout<<left<<"Opt.Dev:";
		cout.width(17);cout<<left<<product1.opticalDevice;
		cout.width(17);cout<<left<<product2.opticalDevice;
		cout.width(17);cout<<left<<product3.opticalDevice<<endl;
	}
	cout.width(20);cout<<left<<"Price (TL):";
	cout.width(17);cout<<left<<product1.price;
	cout.width(17);cout<<left<<product2.price;
	cout.width(17);cout<<left<<product3.price<<endl;
	cout<<"-----------------------------------------------------------------------"<<endl;
	cout.width(20);cout<<left<<"Benefit:";
	cout.width(17);cout<<left<<product1.deviceBenefit;
	cout.width(17);cout<<left<<product2.deviceBenefit;
	cout.width(17);cout<<left<<product3.deviceBenefit<<endl;
	cout.width(20);cout<<left<<"Pri/Perf:";
	cout.width(17);cout<<left<<product1.priceOverPerformance;
	cout.width(17);cout<<left<<product2.priceOverPerformance;
	cout.width(17);cout<<left<<product3.priceOverPerformance<<endl;
	cout<<"-----------------------------------------------------------------------"<<endl;
	cout<<"Best choice is: "<<best<<endl;
	cout<<"-----------------------------------------------------------------------"<<endl;
}

//prints the top menu, first one
void printMenu1()
{
	cout<<"\nEnter your choice:"<<endl;
	cout<<"1- Enter new product\n2- Import all product data from .txt\n   create database for all products\n   and proceed to next menu"<<endl;
	cout<<"   (Note that once you create database, you cannot add new products anymore)"<<endl;
	cout<<"0- Exit program"<<endl;
}

//prints the sub menu, second one
void printMenu2()
{
	cout<<"\nEnter your choice:"<<endl;
	cout<<"1- Display all products\n2- Enter three product ID's from the list for comparison"<<endl;
	cout<<"0- Exit program"<<endl;
}

//caluclates the benefit of optical device
int benefitOfOpDev(ElectronicProduct product)
{
	int ben=0;
		if(product.opticalDevice=="CD")
			ben=1;
		else if (product.opticalDevice=="DVD")
			ben=2;
		else
			ben=3;
	return ben;
}

//calculates device benefit
float findDeviceBenefit(ElectronicProduct product)
{
	float benefit=0;
	if(product.producType=="Smartphone")
		benefit = (product.has4g+product.hasBluetooth+product.hasFrontCamera) * product.deviceCpu
				* product.deviceRam * product.deviceMemory * product.screenSize * product.batteryLife;
	else if (product.producType=="LaptopComputer")
		benefit = (product.hasHdmi+product.hasBluetooth+benefitOfOpDev(product)) * product.deviceCpu
				* product.deviceRam * product.deviceMemory * product.screenSize * product.batteryLife;
	else if (product.producType=="TV")
		benefit = (product.hasHdmi+product.hasWifi+product.hasUsb) * product.screenSize;
	else
		benefit = (product.hasWifi+product.hasBluetooth+product.hasUsb+benefitOfOpDev(product)) * product.deviceCpu
				* product.deviceRam * product.deviceMemory;
	return benefit;
}

//Guide for entering a new product to database
ElectronicProduct enterNewProductMenu(int &index)
{
	ElectronicProduct product;
	product=ElectronicProduct();
	product.productID=++index;
	int temp=0;
	int props[12]={};

	cout<<"Enter Product Name:"<<endl;
	cin>>product.productName;
	cout<<"Enter Product Type:"<<endl;
	cin>>product.producType;
	findRelevantProperties(product, props);
	
	if(props[0])
	{
		cout<<"Enter CPU(in GHz):"<<endl;
		cin>>product.deviceCpu;
	}
	if(props[1])
	{
		cout<<"Enter RAM(in GB):"<<endl;
		cin>>product.deviceRam;
	}
	if(props[2])
	{
		cout<<"Enter Memory(in GB):"<<endl;
		cin>>product.deviceMemory;
	}
	if(props[3])
	{
		cout<<"Enter Screen Size(in Inch):"<<endl;
		cin>>product.screenSize;
	}
	if(props[4])
	{
		cout<<"Enter Battery Life(in Hours):"<<endl;
		cin>>product.batteryLife;
	}
	if(props[5])
	{
		cout<<"Has 4g (1 or 0) ?"<<endl;
		cin>>temp;
		if(temp==0)
			product.has4g=false;
		else
			product.has4g=true;
	}
	if(props[6])
	{
		cout<<"Has Bluetooth (1 or 0) ?"<<endl;
		cin>>temp;
		if(temp==0)
			product.hasBluetooth=false;
		else
			product.hasBluetooth=true;
	}
	if(props[7])
	{
		cout<<"Has WIFI (1 or 0) ?"<<endl;
		cin>>temp;
		if(temp==0)
			product.hasWifi=false;
		else
			product.hasWifi=true;
	}
	if(props[8])
	{
		cout<<"Has HDMI (1 or 0) ?"<<endl;
		cin>>temp;
		if(temp==0)
			product.hasHdmi=false;
		else
			product.hasHdmi=true;
	}
	if(props[9])
	{
		cout<<"Has USB (1 or 0) ?"<<endl;
		cin>>temp;
		if(temp==0)
			product.hasUsb=false;
		else
			product.hasUsb=true;
	}
	if(props[10])
	{
		cout<<"Has Front Camera (1 or 0) ?"<<endl;
		cin>>temp;
		if(temp==0)
			product.hasFrontCamera=false;
		else
			product.hasFrontCamera=true;
	}
	if(props[11])
	{
		cout<<"Optical device (CD DVD or Bluray) ?"<<endl;
		cin>>product.opticalDevice;	
	}
		cout<<"Enter price (in TL):"<<endl;
		cin>>product.price;
		product.deviceBenefit=findDeviceBenefit(product);
		product.priceOverPerformance=product.price/product.deviceBenefit;
		return product;
}


//main function
int main()
{

	//used variables
	stack<ElectronicProduct> allProduct;
	int index=0, i, flag=0, stopp=0, newpro=0, memory=0;;
	int sec1, sec2, sec3;
	int choice=0;
	char buff[256];
	stringstream ss;
	ElectronicProduct product, dummy;

	//a pointer to dynamic memory allocation
	ElectronicProduct *aOfPro;

	//UI header
	cout<<"------\nEE Tech Product Comparison\n--Aykut Demirel--1813948--"<<endl;


	//Core of the main code
	while(!flag)
	{
			//prints the top menu and get choice
			printMenu1();
			cin>>choice;

			if(choice==1)//Go to enter new product menu and store it in the stack
			{
				ElectronicProduct addedProduct;
				addedProduct=enterNewProductMenu(index);
				allProduct.push(addedProduct);
				cout<<"------\nProduct is saved. Details are below:\n"<<endl;
				printProduct(addedProduct);
			}

			else if(choice==2)//import all data, Parsing occurs here
			{	
				flag=1;
				ifstream infile("allProductData.txt");
			 	while(!infile.eof())	
			 	{
					infile.getline( buff, 256 );
						ss << buff;
						ss.getline(buff,256,'\t');
						if(!strcmp(buff,"Name:"))
						{
							newpro=1;
							product = ElectronicProduct();
							product.productID=++index;
							ss.getline(buff,256,'\n');
							product.productName=buff;
						}
						else if(!strcmp(buff,"Type:"))
						{
							ss.getline(buff,256,'\n');
							product.producType = string(buff);
						}
						else if(!strcmp(buff,"CPU:"))
						{
							ss.getline(buff,256,'\n');
							product.deviceCpu = atof(buff);
						}
						else if(!strcmp(buff,"RAM:"))
						{
							ss.getline(buff,256,'\n');
							product.deviceRam= atoi(buff);
						}
						else if(!strcmp(buff,"Screen:"))
						{
							ss.getline(buff,256,'\n');
							product.screenSize = atof(buff);
						}
						else if(!strcmp(buff,"Mem:"))
						{
							ss.getline(buff,256,'\n');
							product.deviceMemory = atoi(buff);
						}
						else if(!strcmp(buff,"hasBT:"))
						{
							ss.getline(buff,256,'\n');
							if(buff[0]=='T')
								product.hasBluetooth=true;
							else
								product.hasBluetooth=false;
						}
						else if(!strcmp(buff,"has4g:"))
						{
							ss.getline(buff,256,'\n');
							if(buff[0]=='T')
								product.has4g=true;
							else
								product.has4g=false;
						}
						else if(!strcmp(buff,"battLife:"))
						{
							ss.getline(buff,256,'\n');
							product.batteryLife = atof(buff);	
						}
						else if(!strcmp(buff,"hasFrCam:"))
						{
							ss.getline(buff,256,'\n');
							if(buff[0]=='T')
								product.hasFrontCamera=true;
							else
								product.hasFrontCamera=false;
						}
						else if(!strcmp(buff,"Price:"))
						{
							ss.getline(buff,256,'\n');
							product.price= atof(buff);
							
						}
						else if(!strcmp(buff,"hasWifi:"))
						{
							ss.getline(buff,256,'\n');
							if(buff[0]=='T')
								product.hasWifi=true;
							else
								product.hasWifi=false;
						}
						else if(!strcmp(buff,"hasHdmi:"))
						{
							ss.getline(buff,256,'\n');
							if(buff[0]=='T')
								product.hasHdmi=true;
							else
								product.hasHdmi=false;

						}
						else if(!strcmp(buff,"hasUsb:"))
						{
							ss.getline(buff,256,'\n');
							if(buff[0]=='T')
								product.hasUsb=true;
							else
								product.hasUsb=false;
						}
						else if(!strcmp(buff,"opticDev:"))
						{
							ss.getline(buff,256,'\n');
							product.opticalDevice=buff;
						}
						else
						{
							if(newpro)
							{
								newpro=0;
								product.deviceBenefit=findDeviceBenefit(product);
								product.priceOverPerformance=product.price/product.deviceBenefit;
								allProduct.push(product);
							}
						}	
					ss<<"";
					ss.clear();
			 	}
			 	memory=1;
			  	aOfPro=new ElectronicProduct[index];

			  	for(i=0;i<index;i++)
			  	{
			  		aOfPro[index-1-i]=allProduct.top();
			  		allProduct.pop();
			  	}
			  	cout<<"------\nAll data is imported from .txt file and database is created successfuly.\n"<<endl; 
			  	infile.close(); 	
			}
			else if(choice==0)//exits the program
			{
				cout<<"------\nGood Byee !!\n"<<endl;
				break;
			}
			else cout<<"\nPlease make a valid choice!"<<endl;//if choice is not 0,1 or 2
			while(flag)	
			{		//enters the sub menu and gets a choice
					printMenu2();
					cin>>choice;
					if(choice==1)//displays all products
					{
							cout<<"--------------------------------------------------"<<endl;
							cout.width(10);cout<<left<<"PID";
							cout.width(17);cout<<left<<"Product Type";
							cout.width(17);cout<<left<<"Product Name"<<endl;
							cout<<"--------------------------------------------------"<<endl;
							for(i=0;i<index;i++)
					  		{
								displayProduct(aOfPro[i]);
					  		}
					  		cout<<"--------------------------------------------------"<<endl;
					}
					else if(choice==0)//exits the program
					{	
						cout<<"------\nGood Byee !!\n"<<endl;
						break;
					}
					else if(choice==2)//Product comparison menu, gets three PID's
					{
							cout<<"Enter three ProductID's for comparison:\n"<<endl;
							cin>>sec1;
							cin>>sec2;
							cin>>sec3;
							
							if(sec1>index||sec2>index||sec3>index)//If selection is out of index.
							{
								cout<<"\nInvalid selection. Product ID's are not found in the database."<<endl;
							}
							else //if selection is valid
							{
								sec1--;
								sec2--;
								sec3--;
								if((aOfPro[sec1].producType==aOfPro[sec2].producType)&&(aOfPro[sec2].producType==aOfPro[sec3].producType))
								{
									cout<<"You chose "<<sec1+1<<", "<<sec2+1<<" and "<<sec3+1<<". The comparison is below:"<<endl;
									cout<<"-----------------------------------------------------------------------"<<endl;
									cout.width(20);cout<<left<<" ";
									cout.width(17);cout<<left<<aOfPro[sec1].productName;
									cout.width(17);cout<<left<<aOfPro[sec2].productName;
									cout.width(17);cout<<left<<aOfPro[sec3].productName<<endl;
									cout<<"-----------------------------------------------------------------------"<<endl;
									compareProduct(aOfPro[sec1], aOfPro[sec2], aOfPro[sec3]);
								}
								else cout<<"\nInvalid selection. Selected products must be of same type for comparison."<<endl;
							}
							
						

					}
					else cout<<"\nPlease make a valid choice!"<<endl; // if choice made in the sub menu is not valid
			}
				
	}

if(memory)
	delete [] aOfPro;	//if dynamic memory allocation is made, deallocates the memory				
}
//end of the program