#include <iostream>
#include <vector>
#include "Station.h"
#include "Passenger.h"
using namespace std;

int main() {
	vector <Station*> stations;
	stations.push_back(new Station("Ostanovka 1", stations.size());
	stations.push_back(new Station("Ostanovka 2", stations.size());
	stations.push_back(new Station("Ostanovka 3", stations.size());
	stations.push_back(new Station("Ostanovka 4", stations.size());
	stations.push_back(new Station("Ostanovka 5", stations.size());

	vector <Passenger*> passengers;
	passengers.push_back(new Passenger("Vladimir", stations.at(3)));
	passengers.push_back(new Passenger("Kirill", stations.at(4)));
	passengers.push_back(new Passenger("Yaroslav", stations.at(1)));
	passengers.push_back(new Passenger("Maria", stations.at(2)));
	passengers.push_back(new Passenger("Katya", stations.at(0)));

	Taxi* taxi = new Taxi(3, stations.at(0));

	for (int i = 0; i < passengers.size(); i++) {
		stations.at(i)->passengers.push_back(passengers.at(i));
	}

	for (int i = 0; i < )

	stations.at(0)->passengers.at(0)->GetInTaxi();

	char action;

	while (true) {
		cout << "change action\n";
		cin >> action;
		switch (action) {
		case (0):
			break;
		}
	}

	return 0;
}