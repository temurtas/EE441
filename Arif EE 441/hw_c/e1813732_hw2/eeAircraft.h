#ifndef EEAIRCRAFT_H_INCLUDED
#define EEAIRCRAFT_H_INCLUDED
#include "eeCapsule.cpp"

class eeAircraft
{
    public:
        void displayflight();
        void Updatehead();
        eeCapsule* Drop();
        void Integrate(eeCapsule* newobj);
        eeCapsule* head;
        eeAircraft(int Lattitude, int Longitude , int Direction);
        int Getlattitude() { return lattitude; }
        int Getlongitude() { return longitude; }
        int Getdirection() { return direction; }
    protected:
    private:
        int lattitude;
        int longitude;
        int direction;

};



#endif // EEAIRCRAFT_H_INCLUDED
