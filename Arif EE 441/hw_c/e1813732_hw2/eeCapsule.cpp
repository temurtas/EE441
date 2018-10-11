#include "eeCapsule.h"
#include "iostream"

using namespace std;

eeCapsule::eeCapsule(std::string Name,long int ID,int lat,int lng)
{
    name=Name;
    CID=ID;
    lattitude=lat;
    longitude=lng;
    prev=this;
    next=this;
    //ctor
};

void eeCapsule::displaycapsule()
{   if(this != NULL)
    {
        std::string s;
        int szname,szcid,k;
        long int i;
        s=name;
        szname=s.length();
        szcid=1;
        i=CID;
 // and for numbers greater than 0:
        if (i > 0)
        {
    // we count how many times it can be divided by 10:
    // (how many times we can cut off the last digit until we end up with 0)
            for (szcid = 0; i > 0; szcid++)
            {
                i = i / 10;
            }
        }
        if((szname)<=(szcid)) k=szcid+14;
        else k=szname+14;
        for(i=1;i<k;i++)
        {
            cout<<"=";
        }
        cout<<"\n";
        cout<<"Name:"<<"        "<<name<<endl;
        cout<<"CID: "<<"        "<<CID<<endl;
        cout<<"Lattitude:"<<"    "<<(lattitude>90 ? lattitude-180:lattitude)<<endl;
        cout<<"Longitude:"<<"    "<<(longitude>180 ? longitude-360:longitude)<<endl;
        for(i=1;i<k;i++)
        {
            cout<<"=";
        }
        cout<<endl;
    }
    else
    {
        return;
    }
};

