#pragma once
#include <string>
#include <vector>
using namespace std;

class Passenger;
class Station {
private:
	string _name;
	string _location;
public:
	void AddPassenger(Passenger*);
	void RemovePassenger(Passenger*);
	vector <Passenger*> passengers;
	Station(string, string);
};

