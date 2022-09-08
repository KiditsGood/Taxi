#include "Taxi.h" 
Taxi::Taxi(int capacity, Station* currentlocation) {
	_capacity = capacity;
	_currentlocation = currentlocation;
}

void Taxi::SetRoute(Station* startpoint, Station* endpoint) {
	for (int i = startpoint->getId(; i < stations.size(); i++) {
		
	}
}

int Taxi::getCapacity() {
	return _capacity;
}

void Taxi::setCapacity(int capacity) {
	_capacity = capacity;
}