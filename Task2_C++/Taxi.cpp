#include "Taxi.h"
Taxi::Taxi(int capacity, Station* currentlocation) {
	_capacity = capacity;
	_currentlocation = currentlocation;
}

void Taxi::SetRoute(Station* startpoint, Station* endpoint) {
	this->route.clear();
	bool straightPath = true;
	if (startpoint->getId() > endpoint->getId()) {
		straightPath = false;
	}
	if (straightPath) {
		for (int i = startpoint->getId(); i <= endpoint->getId(); i++)
		{
			Station* currentStation = this->stations.at(i);
			this->route.push_back(currentStation);
		}
	}
	else {
		for (int i = startpoint->getId(); i >= endpoint->getId(); i--)
		{
			Station* currentStation = this->stations.at(i);
			this->route.push_back(currentStation);
		}
	}
}

int Taxi::getCapacity() {
	return _capacity;
}

void Taxi::setCapacity(int capacity) {
	_capacity = capacity;
}

void Taxi::followRoute() {
	for (size_t i = 0; i < route.size(); i++)
	{
		Station* currentStation = route.at(i);
		for (size_t j = 0; j < passengers.size(); j++) {
			Passenger* currentPassenger = passengers.at(j);
			if (currentStation->getId() == currentPassenger->getEndPoint()->getId()) {
				currentPassenger->GetOutTaxi(this);
			}
		}
	}
}