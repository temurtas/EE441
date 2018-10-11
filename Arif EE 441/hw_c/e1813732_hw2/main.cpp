#include <iostream>
#include <eeAircraft.cpp>

using namespace std;

void Deleteobject(eeCapsule* p)
{
    delete p;
    return;
};
eeCapsule* Getobject(string &name, long int &ID, int &lat, int &lng)
{
    eeCapsule *p;
    p=new eeCapsule(name,ID,lat,lng);
    return p;
};
void simulateflight(eeAircraft* &plane)
{
    while(plane->head != NULL)
    {
        eeCapsule* capsul;
        capsul=plane->Drop();
        cout<<"Dropped Capsule:"<<endl;
        capsul->displaycapsule();
        Deleteobject(capsul);
        cout<<"Current Aircraft:"<<endl;
        plane->displayflight();
        cout<<"***"<<endl;

    }

};
void RegistrationInterface(eeAircraft* &plane)
{
    bool ahmed=1;
    while(ahmed)
    {   int a;
        cout<<"EE Tech Easy Everywhere"<<endl;
        cout<<"(1) New Passenger"<<endl;
        cout<<"(2) Close Registration and Simulate the Flight"<<endl;
        cin>>a;
        if(a==1)
        {   string name;
            long int ID;
            signed int lat,lng;
            cout<<"Name of the passenger:"<<endl;
            cin.ignore();
            getline(cin,name);
            cout<<"CID of the passenger:"<<endl;
            cin>>ID;
            cout<<"Destination (Lat. & Long):"<<endl;
            cin>>lat;
            cin>>lng;
            lat>0 ? lat=lat:lat=lat+180;
            lng>0 ? lng=lng:lng=lng+360;
            plane->Integrate(Getobject(name,ID,lat,lng));
            cout<<"New passenger has been successfully registered!"<<endl;
        }
        else if(a==2)
        {
            plane->Updatehead();
            plane->displayflight();
            cout<<"\nNow simulation Starts\n"<<endl;
            simulateflight(plane);
            cout<<"\nSimulation has ended\n"<<endl;
            ahmed=0;
        }
    }
    return;

};
int main()
{

    bool runforestrun=1;
    cout<<"Welcome!"<<endl;
    while (runforestrun)
    {   int a;
        cout<<"EE Tech Easy Everywhere Simulator\n(1)New Flight\n(2)Exit\n"<<endl;
        cin>>a;
        if(a==1)
        {
            signed int latitude,longitude,direction;
            cout<<"Input Latitude, Longitude and Flight Direction:"<<endl;
            cin>>latitude;
            cin>>longitude;
            cin>>direction;
            latitude<0 ? latitude=latitude+180:latitude=latitude;
            longitude<0 ? longitude=longitude+360:longitude=longitude;
            eeAircraft* aircraft=new eeAircraft(latitude,longitude,direction);
            RegistrationInterface(aircraft);
            delete aircraft;
        }
        else if(a==2)
        {
           runforestrun=0;
        }
    }
};
