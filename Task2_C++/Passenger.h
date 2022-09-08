#pragma once
#include <string>
#include "Station.h"
#include "Taxi.h"
using namespace std;

class Passenger {
private: 
	string _name;
	Station* _endpoint;	
public:
	void GetInTaxi(Taxi*);
	void GetOutTaxi(Taxi*);
	Passenger(string, Station*);
};

