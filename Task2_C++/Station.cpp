#include "Station.h"
Station::Station(string name, int id) {
	_name = name;
	_id = id;
}

void Station::AddPassenger(Passenger* passenger) {
	this->passengers.push_back(passenger);
}

void Station::RemovePassenger(Passenger* passenger) {
	for (int i = 0; i < this->passengers.size(); i++) {
		Passenger* currentPassenger = this->passengers.at(i);

		if (currentPassenger->getName() == passenger->getName()) {
			this->passengers.erase(this->passengers.begin() + i);
			delete currentPassenger;
			break;
		}
	}
}

int Station::getId() {
	return _id;
}

string Station::getName() {
	return _name;
}