
#include "ee.h"
#include <string>
#include <sstream>
#include <iostream>

EECapsule::EECapsule(std::string _Name = "", int _CID = 0, int Lat = 0, int Lon = 0){
	Name = _Name;
	CID = _CID;
	Latitude = Lat;
	Longitude = Lon;
}

int EECapsule::GetLongitude(){
	return Longitude;
}

void EECapsule::DisplayCapsuleInfo() {
	std::string line1, line2, line3;
	int llength;
	std::stringstream helper;

	helper << CID;
	line1 = "Name: " + Name;
	line2 = "CID: " + helper.str();
	line3 = "Destination: " + GetDestination();

	llength = line1.size();
	if (llength < line2.size())
		llength = line2.size();
	if (llength < line3.size())
		llength = line3.size();

	std::string line(llength, '=');

	std::cout << line << std::endl;
	std::cout << line1 << std::endl;
	std::cout << line2 << std::endl;
	std::cout << line3 << std::endl;
	std::cout << line << std::endl;
}

std::string EECapsule::GetDestination(){
	std::stringstream s;
	s << std::showpos << Latitude << ", " << Longitude;
	return s.str();
}



EEAircraft::EEAircraft(int Lat, int Lon, int Dir = -1){
	Latitude = Lat;
	Longitude = Lon;
	Direction = Dir;

}


void EEAircraft::Display(){
	std::stringstream line1, line2, line3;
	int llength;

	line1 << "EEAircraft" << std::endl;
	line2 << "Departure: " << std::showpos << Latitude + ", " << Longitude << std::endl;
	line3 << "Direction: " << Direction << std::endl;

	llength = line1.str().size();
	if (llength < line2.str().size())
		llength = line2.str().size();
	if (llength < line3.str().size())
		llength = line3.str().size();

	std::string line(llength, '=');

	std::cout << line << std::endl;
	std::cout << line1.str();
	std::cout << line2.str();
	std::cout << line3.str();
	std::cout << line << std::endl;

	if (Direction == 1)
	for (int j = 0; j < count; j++){
		capsules[j]->DisplayCapsuleInfo();
	}
	else
	for (int j = count - 1; j >= 0; j--){
		capsules[j]->DisplayCapsuleInfo();
	}

}

void EEAircraft::Integrate(EECapsule* e){
	capsules[count] = e;
	count++;
}

EECapsule* EEAircraft::Drop(){
	if (Direction == 1){
		EECapsule* temp = capsules[0];
		for (int j = 0; j <= count - 1; j++){
			capsules[j] = capsules[j + 1];
		}
		count--;
		return temp;
	}
	else{
		return capsules[--count];
	}

}
