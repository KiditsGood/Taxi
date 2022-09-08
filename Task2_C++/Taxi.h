#pragma once
#include <string>
#include <vector>
#include "Passenger.h"
#include "Station.h"
using namespace std;

class Taxi {
public:
	vector <Passenger*> passengers;
	vector <Station*> route;
	void SetRoute(Station* startpoint, Station* endpoint);
	Taxi(int, Station* currentLocation);
	vector <Station*> stations;
	int getCapacity();
	void setCapacity(int);

private:
	int _capacity;
	Station* _currentlocation;
};