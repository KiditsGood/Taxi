#pragma once
#include <string>
#include <vector>
#include "Passenger.h"
#include "Station.h"
using namespace std;

class Passenger;
class Station;

class Taxi {
public:
	vector <Passenger*> passengers;
	vector <Station*> route;
	void SetRoute(Station* startpoint, Station* endpoint);
	Taxi(int, Station* currentLocation);
	vector <Station*> stations;
	int getCapacity();
	void setCapacity(int);
	void followRoute();
	void releasePassengers(Station* currentStation);
	void letIn(Station* currentStation, bool straightPath);
	~Taxi();
private:
	int _capacity;
	Station* _currentlocation;
};