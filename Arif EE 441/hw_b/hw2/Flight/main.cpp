#include <iostream>
#include <ee.h>
#include <string>
using namespace std;

EECapsule* getCapsule(string name_,int cid_,float latitude_,float longitude_) {
    EECapsule* newCapsule;
    newCapsule= new EECapsule(name_,cid_,latitude_,longitude_);
    return newCapsule;
}



int main()
{
    // Program Description

    cout<<"\t\tEE Tech Easy Everywhere Simulator"<<endl;
    cout<<"\t\tAhmet EROL - 1814094 \n\n\n"<<endl;

    // User Interface
    bool exit=true;
    int selection=0;
    if(selection==0) {
            // Options screen
            cout<<"\n\n Choose option below\n 1 > New Flight \n 0 > Exit Program \n"<<endl;
            // Get selection
            cin>>selection;
    }
    if(selection==1) {
                // New Flight
                int direction_;
                float latitude_;
                float longitude_;
                cout<<"Input Departure Latitude, Longitude and Flight Direction:"<<endl;
                cin>>latitude_>>longitude_>>direction_;
                EEAircraft flight(direction_,latitude_,longitude_);

                // flight points no new created flight


        while(exit){
                cout<<"\n\n Choose option below\n 1 > New Passenger \n 2 > Close Registration and Simulate Flight \n"<<endl;
                int selection2;
                cin>>selection2;
                    switch(selection2) {
                        case 1 :{
                            // Add new passenger
                            int cid_;
                            string name_;
                            float latitude_;
                            float longitude_;
                            cout<<"Name of Passenger:";
                            cin>>name_;
                            cout<<"CID of Passenger:";
                            cin>>cid_;
                            cout<<"Destination (Lat. & Long)::";
                            cin>>latitude_>>longitude_;
                            EECapsule* capsule;
                            capsule=getCapsule(name_,cid_,latitude_,longitude_);
                            flight.integrate(capsule);
                            cout<<"New capsule added."<<endl;
                            break;
                        }
                        case 2:
                                if(flight.hasCapsule()) {
                                    cout<<"The registration has been closed and the aircraft to take off is:"<<endl;
                                    flight.setStarting();
                                    flight.showInfo();
                                    while(flight.hasCapsule()) {
                                        EECapsule* dropped;
                                        dropped = flight.drop();
                                        dropped->showInfo(flight.max_string);
                                    }
                                }
                            break;
                        default:
                            // Exit
                            exit=false;
                            break;
                        continue;

                    }

        }

    }
    return 0;
}
