#include "flightMap.h"
#include <iomanip>
#include <stack>
#include "type.h"
#include <list>
#include <iomanip>

//Implement the flightMap class defined in flightMap.h

//Default Constructor for the FlightMapClass
FlightMapClass::FlightMapClass(){
	size = 0;
}

//Copy Constructor for the FlightMapClass
FlightMapClass::FlightMapClass(const FlightMapClass &f){
	size = f.size;
	cities = f.cities;
	visited = f.visited;
	map = new list<flightRec>[size];
	for (int i = 0; i < size; i++){
		map[i] = f.map[i];
	}
}

//Destructor for the FlightMapClass
FlightMapClass::~FlightMapClass(){
	delete[] map;
}


// FlightMapClass operations

//Read cities from a data file and puts them into the cities vector
//Also setting each visited vector to false
void FlightMapClass::ReadCities(ifstream &myCities){
	int num;
	string city;

	myCities >> num;
	size = num;

	//Adds all the cities into its vector and creates the visited vector for each one
	while (getline(myCities,city)){
		cities.push_back(city);
		visited.push_back(false);
	}

	//Organizes the cities in order
	string temp;
	for (int i = 0; i < size; i++){
		for (int x = 0; x < size; x++){
			if (cities[i] < cities[x]){
				temp = cities[i];
				cities[i] = cities[x];
				cities[x] = temp;
			}
		}
	}
	
	return;
}

//Builds the adjacency list for the flights
void FlightMapClass::BuildMap(ifstream &myFlights){
	map = new list<flightRec>[size];

	//Variables for the Flights
	int flightnum, price;
	string origin, destination;
	flightRec temp;

	//Reads file information into temporary variables
	while (myFlights >> flightnum >> origin >> destination >> price){
		temp.flightNum = flightnum;
		temp.origin = origin;
		temp.destination = destination;
		temp.price = price;

		//Pushes those temporary variables into the list of flights
		for (int i = 0; i < size; i++){
			if (cities[i] == temp.origin){
				map[i].push_back(temp);
			}
		}
		myFlights.ignore(100,'\n');
	}
	
	return;
}

//Displays the table for all the flights
void FlightMapClass::DisplayMap(){
	//Map Formatted Table
	cout << "     " << "Origin" << setw(20) << "Destination" << setw(10) << "Flight" << setw(10) << "Price" << endl;
	cout << "======================================================";

	//Prints out all the flights
	for (int x = 0; x < size; x++){
		list<flightRec>::iterator i = map[x].begin();

		while (i != map[x].end()){
			if (i == map[x].begin()){
				cout << "from " << i->origin << " to: " << endl
					 << right
					 << setw(30) << i->destination 
					 << setw(10) << i->flightNum 
					 << setw(8) << "$" << i->price;
			}
			else {
				cout << right
					 << setw(30) << i->destination 
					 << setw(10) << i->flightNum  
					 << setw(8) << "$" << i->price;
			}
			i++;
			cout << endl;
		}
		cout << endl;
	}
	cout << "======================================================" << endl;
	
	return;
}


// methods below this point are added new

//Checks to see whether a certain city is offered by the airline
bool FlightMapClass::CheckCity(string cityName) const{
	for (int i = 0; i < size; i++){
		if (cityName == cities[i]){
			return true;
		}
	}
	return false;
}

//Displays all the current offered cities
void FlightMapClass::DisplayAllCities() const{
	for (int i = 0; i < size; i++){
		cout << cities[i] << endl;
	}
}

//Marks a City as visited
void FlightMapClass::MarkVisited(int city){
	visited[city] = true;
}

//Clears all marks on all cities visited
void FlightMapClass::UnvisitAll(){
	for (int i = 0; i < size; i++){
		visited[i] = false;
	}
}

//Checks to see whether a city was visited or not
bool FlightMapClass::IsVisited(int city) const{
	if (visited[city] == true){
		return true;
	}
	else{
		return false;
	}
}

//Gives the next unvisited city if there is one still unvisited
//True if a city was found that was unvisited
//False if all cities were visited already
bool FlightMapClass::GetNextCity(string fromCity, string &nextCity){
	int x = GetCityNumber(fromCity);
	
	//iterator to check for unvisited city
	for (list<flightRec>::iterator it = map[x].begin(); it != map[x].end(); ++it){
		int NextCityIndex = GetCityNumber(it->destination);
		if (IsVisited(NextCityIndex) == false){
			nextCity = it->destination;
			return true;
		}
	}
	return false;
}

//Returns the city number for a specific city
int FlightMapClass::GetCityNumber(string cityName) const{
	for (int i = 0; i < size; i++){
		if (cities[i] == cityName){
			return i;
		}
	}
	return 0;
}

//Returns the name of a city given the number of the city
string FlightMapClass::GetCityName(int cityNumber) const{
	return cities[cityNumber];
}

//Finds the path from one location to the other
//Inputs a message if no flights are found
//If found then outputs all flights that will bring you to the destination
void FlightMapClass::FindPath(string originCity, string destinationCity){
	//Unmarks all cities just to make sure
	UnvisitAll();

	//Stacks to hold cities to visit
	stack<string> path;
	stack<string> rpath;

	//Starting stack with the origin
	path.push(originCity);
	MarkVisited(GetCityNumber(originCity));

	string topcity, nextcity;

	//While loop to gather all flights into the stack path
	while (!path.empty()){
		topcity = path.top();
		if (topcity == destinationCity){
			break;
		}

		//pushing flights into the stack
		if (GetNextCity(topcity, nextcity)){
			path.push(nextcity);
			MarkVisited(GetCityNumber(nextcity));
		}
		else{
			path.pop();
		}
	}
	
	if (!path.empty()){
		//While loop to reverse stack path
		while(!path.empty()){
			rpath.push(path.top());
			path.pop();
		}

		//Prints out all the flight options if avilable
		cout << "The flight itinerary is: " << endl;
		cout << "Flight #		 From				To		   Cost" << endl;
		
		int price = 0;
		string prev = rpath.top();
		rpath.pop();
		
		while (!rpath.empty()){
			string curr = rpath.top();
			rpath.pop();
			for (list<flightRec>::iterator it = map[GetCityNumber(prev)].begin(); it != map[GetCityNumber(prev)].end(); ++it){
				if (it->destination == curr){
					price += it->price;
					cout << it->flightNum << setw(20) 
						 	 << it->origin << setw(18) 
						 	 << it->destination << "	   " 
						 	 << "$" << it->price << endl;	
					break;
				}
			}
			prev = curr;
		}
		cout << setw(48) << "Total: $" << price << endl;
	}
	//otherwise prints out an error if city is not avaible from chosen origin
	else {
		cout << "Sorry, BlueSky airline does not fly from " << originCity << " to " << destinationCity << "." << endl;
	}
}
