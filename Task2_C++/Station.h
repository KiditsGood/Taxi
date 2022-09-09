#pragma once
#include <string>
#include <vector>
#include "Passenger.h"
using namespace std;

class Passenger;

class Station {
private:
	string _name;
	int _id;
public:
	void AddPassenger(Passenger*);
	void RemovePassenger(Passenger*);
	vector <Passenger*> passengers;
	Station(string, int);
	int getId();
	string getName();
	~Station();
};

