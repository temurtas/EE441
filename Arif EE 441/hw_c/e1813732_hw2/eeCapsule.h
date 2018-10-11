#ifndef EECAPSULE_H_INCLUDED
#define EECAPSULE_H_INCLUDED
#include <string>

class eeCapsule
{    private:
        std::string name;
        long int CID;
        signed int lattitude;
        signed int longitude;
    public:
        void displaycapsule();
        eeCapsule* prev;
        eeCapsule* next;
        eeCapsule(std::string Name,long int ID,int lat,int lng);
        std::string Getname() { return name; }
        int GetCID() {return CID;}
        int Getlattitude() { return lattitude; }
        int Getlongitude() { return longitude; }




};

#endif // EECAPSULE_H_INCLUDED
