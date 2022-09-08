#include "Passenger.h"
Passenger::Passenger(string name, Station* endpoint) {
	_name = name;
	_endpoint = endpoint;
}

void Passenger::GetInTaxi(Taxi* taxi) {
	if (taxi->passengers.size() < taxi->getCapacity()) {
		taxi->passengers.push_back(this);
	}
}

void Passenger::GetOutTaxi(Taxi* taxi) {
	for (int i = 0; i < taxi->passengers.size(); i++) {
		Passenger* currentPassenger = taxi->passengers.at(i);

		if (currentPassenger->_name == this->_name) {
			taxi->passengers.erase(taxi->passengers.begin() + i);
		}
	}

	delete this;
}