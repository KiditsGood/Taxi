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

		if (currentPassenger->_name == passenger->_name) {
			this->passengers.erase(this->passengers.begin() + i);
		}
	}
}

int Station::getId() {
	return _id;
}