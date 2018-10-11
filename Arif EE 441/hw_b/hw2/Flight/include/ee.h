#ifndef EE_H
#define EE_H
#include <iostream>
#include <string.h>

using namespace std;

class EECapsule {
private:

    int cid;
    string name;
    float latitude;
    float longitude;
    EECapsule* pre=NULL;
    EECapsule* next=NULL;

public:
    EECapsule(string name_,int cid_,float latitude_,float longitude_);
    EECapsule();
    float getLongitude();
    void showInfo(int s);
    EECapsule* getNext();
    EECapsule* getPrev();
    string getName();
    void setNext(EECapsule* p);
    void setPrev(EECapsule* p);
};

class EEAircraft {
private:

    EECapsule* last;
    int direction;
    float latitude;
    float longitude;

public:
    int max_string=12;
    EECapsule* first;
    EECapsule* starting;
    EEAircraft();
    EEAircraft(int direction_,float latitude_,float longitude_);
    void integrate(EECapsule* capsule_ );
    EECapsule* drop();
    void setStarting();
    void showInfo();
    bool hasCapsule();

};


#endif // EE_H
