#include "Passenger.h"
Passenger::Passenger(string name, int age, Station* startpoint, Station* endpoint) {
	_name = name;
	_age = age;
	_startpoint = startpoint;
	_endpoint = endpoint;
}

void Passenger::GetInTaxi(Taxi* taxi) {
	taxi->passengers.push_back(this);
}

void Passenger::GetOutTaxi(Taxi * taxi) {
	taxi->passengers.foreach
}