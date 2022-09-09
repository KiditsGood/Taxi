#include <iostream>
#include <vector>
#include "Station.h"
#include "Passenger.h"
using namespace std;


template <typename T>
void printNames(vector<T*> items) {
	for (size_t i = 0; i < items.size(); i++)
	{
		cout << items.at(i)->getName() << " | ";
	}
}


int main()
{
	vector <Station*> stations;
	stations.push_back(new Station("Ostanovka 0", stations.size()));
	stations.push_back(new Station("Ostanovka 1", stations.size()));
	stations.push_back(new Station("Ostanovka 2", stations.size()));
	stations.push_back(new Station("Ostanovka 3", stations.size()));
	stations.push_back(new Station("Ostanovka 4", stations.size()));

	vector <Passenger*> passengers;
	passengers.push_back(new Passenger("Vladimir", stations.at(3)));
	passengers.push_back(new Passenger("Kirill", stations.at(4)));
	passengers.push_back(new Passenger("Yaroslav", stations.at(1)));
	passengers.push_back(new Passenger("Maria", stations.at(2)));
	passengers.push_back(new Passenger("Katya", stations.at(0)));

	Taxi* taxi = new Taxi(3, stations.at(0));
	taxi->stations = stations;

	for (int i = 0; i < passengers.size(); i++) {
		stations.at(i)->passengers.push_back(passengers.at(i));
	}

	stations.at(0)->passengers.at(0)->GetInTaxi(taxi);
	cout << "Stations :\n";
	printNames<Station>(stations);
	cout << "\nPassengers :\n";
	printNames<Passenger>(passengers);


	taxi->SetRoute(stations.at(1), stations.at(3));
	cout << "\nRoute 1->3 :\n";
	printNames<Station>(taxi->route);

	/*taxi->SetRoute(stations.at(3), stations.at(1));
	cout << "\nRoute 3->1 :\n";
	printNames<Station>(taxi->route);*/

	taxi->followRoute();
}

