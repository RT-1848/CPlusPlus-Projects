/* 
 Program Description:    
  This program sorts through all requests of flights and determines whether the flight is available or not. If it is available then it will give out the list of flights that will get you to your destination.
*/ 

#include <iostream>
#include <fstream>
#include "flightMap.h"

using namespace std;

int main() {
	//Files for reading
	ifstream myCities;
	ifstream flightlist;
	ifstream request;

	//Opens all the files
	myCities.open("cities.dat");
	flightlist.open("flights.dat");
	request.open("requests.dat");

	//FlightMap Object
	FlightMapClass flights;
	flights.ReadCities(myCities);
	flights.BuildMap(flightlist);

	//flights.DisplayAllCities();
	//flights.DisplayMap();

	//While loop to handle all given requests
	string origin, destination;
	while (request >> origin >> destination){
		cout << "Request is to fly from " << origin << " to " << destination << "." << endl;
		
		if (flights.CheckCity(origin) == false){
			cout << "Sorry, BlueSky airline does not serve " << origin << "." << "\n\n";
		}
		else if (flights.CheckCity(destination) == false){
			cout << "Sorry, BlueSky airline does not serve " << destination << "." << "\n\n";
		}
		else {
			flights.FindPath(origin, destination);
			cout << "\n";
		}
	}

	//Closes all the files
	request.close();
	myCities.close();
	flightlist.close();
	
  return 0;
}
