#include "Taxi.h"
#include <iostream>
Taxi::Taxi(int capacity, Station* currentlocation) {
	_capacity = capacity;
	_currentlocation = currentlocation;
}

int Taxi::getCapacity() {
	return _capacity;
}

void Taxi::setCapacity(int capacity) {
	_capacity = capacity;
}

void Taxi::SetRoute(Station* startpoint, Station* endpoint) {
	this->route.clear();
	bool straightPath = startpoint->getId() < endpoint->getId();
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

void Taxi::followRoute() {
	bool straightPath = route.at(0)->getId() < route.at(route.size()-1)->getId();
		for (int i = 0; i < route.size(); i++)
		{
			Station* currentStation = route.at(i);
			releasePassengers(currentStation);
			letIn(currentStation,straightPath);
		}
}

void Taxi::releasePassengers(Station* currentStation) {
	for (int j = 0; j < passengers.size(); j++) {
		Passenger* currentPassenger = passengers.at(j);
		if (currentStation->getId() == currentPassenger->getEndPoint()->getId()) {
			currentPassenger->GetOutTaxi(this);
			cout << "Out " + currentStation->getName() + " " + currentPassenger->getName() + "\n";
		}
	}
}

void Taxi::letIn(Station* currentStation,bool straightPath) {
	for (int k = 0; k < currentStation->passengers.size(); k++)
	{
		Passenger* currentPassenger = currentStation->passengers.at(k);
		if (straightPath && currentPassenger->getEndPoint()->getId() <= route.at(route.size() - 1)->getId()) {
			cout << "In " + currentStation->getName() + " " + currentPassenger->getName() + "\n";
			currentPassenger->GetInTaxi(this);
		}
		else if (currentPassenger->getEndPoint()->getId() >= route.at(route.size() - 1)->getId()) {
			cout << "In " + currentStation->getName() + " " + currentPassenger->getName() + "\n";
			currentPassenger->GetInTaxi(this);
		}
	}
}

Taxi::~Taxi() {
	for (int i = 0; i < (int)passengers.size(); i++)
	{
		if (passengers.at(i) != NULL) {
			delete passengers.at(i);
		}
	}
	for (int i = 0; i < (int)route.size(); i++)
	{
		if (route.at(i) != NULL) {
			delete route.at(i);
		}
	}
	for (int i = 0; i < (int)stations.size(); i++)
	{
		if (stations.at(i) != NULL) {
			delete stations.at(i);
		}
	}
}