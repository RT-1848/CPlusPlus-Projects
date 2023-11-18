#include <iostream> // for cin, cout
#include <fstream>  // for ifstream, ofstream
#include <string>   // for any string stuff
#include "Client.h" // for Client and Pet structs
                    // and function prototypes
using std::cout;
using std::endl;
using std::cin;

// All of your functions should be implemented below here
void get_clients(Client clients[], int & count, int & nextClientId){
	std:: ifstream file;
	string blank;

	file.open("groomerDB.dat");

	file >> count;
	file >> nextClientId;
	getline(file, blank);
	int x = 0;
		while (file){
			clients[x] = read_one(file);
			x++;
		}

	file.close();
}


Client read_one(istream &file){
	Client clients;
	file >> clients.clientId, file.ignore();
		getline(file, clients.name);
		getline(file, clients.address);
		file >> clients.acctBalance;
		file >> clients.pet_amt, file.ignore();
		for (int y = 0; y < clients.pet_amt; y++){
			getline(file, clients.pets[y].species);
			getline(file, clients.pets[y].breed);
			getline(file, clients.pets[y].name);
			file >> clients.pets[y].gender;
			file >> clients.pets[y].age, file.ignore();
		}
	return clients;
	}
	


int find_client(const Client clients[], int count, int clientId){
	int client_loc = 0;
	for (int x = 0; x < count; x++){
		if(clients[x].clientId == clientId){
			client_loc = x;
			return client_loc;
		}
	}
	if (client_loc == 0){
		return -1;
	}
	
	return -1;
}


void print_bill(const Client clients[], int clientId, int count){
	cout << "\n" << "What is the client's ID: "; cin >> clientId;
	
	int loc = find_client(clients, count, clientId);
	if (loc == -1){
		cout << "Client isn't in the database." << "\n\n";
		return;
	}
	
	cout << "Bill for " << clients[loc].name << endl;
	cout << "Total owed is " << clients[loc].acctBalance << "\n\n";
}


void print_pet(const Client clients[], int clientId, int count){
	cout << "\n" << "What is the client's ID: "; cin >> clientId;
	
	int loc = find_client(clients, count, clientId);
	if (loc == -1){
	cout << "Client isn't in the database." << "\n\n";
	return;
	}
	
	string pet_name;
	cout << "Please input the pet name "; cin >> pet_name;
	for (int x = 0; x < count; x++){
		if (clients[loc].pets[x].name == pet_name){
			cout << "\n" << "Information for " << pet_name << endl;
			cout << "Species: " << clients[loc].pets[x].species << endl;
			cout << "Breed: " << clients[loc].pets[x].breed << endl;
			cout << "Gender: " << clients[loc].pets[x].gender << endl;
			cout << "Age: " << clients[loc].pets[x].age << "\n\n";
			return;
			}

		}
	cout << "The pet isn't in the database" << "\n\n";
		return;
}


void add_client(Client clients[], int & count, int & nextClientId){
	int new_ = nextClientId - 5004700;
	count ++;
	if (count <= 10){
		clients[new_].clientId = nextClientId;
		cout << "\n" << "Input client information: " << endl;
		cout << "Name: ", cin.ignore(), getline(cin, clients[new_].name);
		cout << "Address: ", getline(cin, clients[new_].address);
		cout << "Number of Pets: "; cin >> clients[new_].pet_amt;
		for (int x = 0; x < clients[new_].pet_amt; x++){
			cout << "Pet " << x + 1 << " species: ", cin.ignore(), getline(cin, clients[new_].pets[x].species);
			cout << "Pet " << x + 1 << " breed: ", getline(cin, clients[new_].pets[x].breed);
			cout << "Pet " << x + 1 << " name: ", getline(cin, clients[new_].pets[x].name);
			cout << "Pet " << x + 1 << " gender: ", cin >> clients[new_].pets[x].gender;
			cout << "Pet " << x + 1 << " age: ", cin >> clients[new_].pets[x].age, cin.ignore();
		}
		cout << "\n";
		new_ = nextClientId++ - 5004700;
	}
	else if (count > 10){
		cout << "\n" << "You have reached the maximum number of clients" << "\n\n";
		return;
	}
}


void remove_client(Client clients[], int clientId, int &count){
	cout << "What is the client's ID "; cin >> clientId;
	
  int loc = find_client(clients, count, clientId);
	if (loc == -1){
	cout << "Client isn't in the database." << "\n\n";
	return;
	}

	for (int x = loc; x < count; x++){
		clients[x] = clients[x+1];
	}
	count--;
	

	cout << "\n" << "Client has been deleted..." << "\n\n";
}


void print_all_clients(const Client clients[], int count){	
	cout << "Client List: " << endl;
	for (int x = 0; x < count; x++){
		cout << clients[x].name << endl;
		cout << clients[x].clientId << endl;
		cout << clients[x].address << endl;
		cout << clients[x].acctBalance << endl;
		cout << "Pets: " << endl;
		for (int y = 0; y < clients[x].pet_amt; y++){
			cout << "  " << clients[x].pets[y].name 
			<< "  " << clients[x].pets[y].species 
			<< "  " << clients[x].pets[y].breed 
			<< "  " << clients[x].pets[y].gender 
			<< "  " << clients[x].pets[y].age << endl;
		}
		cout << "\n\n";
	}
}


void save_database(Client clients[],int count, int nextClientId){
	std:: ofstream file;
	
	file.open("groomerDB.dat");
	file << count << endl;
	file << nextClientId << endl;
	for (int x = 0; x < count; x++){
		file << clients[x].clientId << endl;
		file << clients[x].name << endl;
		file << clients[x].address << endl;
		file << clients[x].acctBalance << endl;
		file << clients[x].pet_amt << endl;
		for (int y = 0; y < clients[x].pet_amt; y++){
			file << clients[x].pets[y].species << endl;
			file << clients[x].pets[y].breed << endl;
			file << clients[x].pets[y].name << endl;
			file << clients[x].pets[y].gender << endl;
			file << clients[x].pets[y].age << endl;
		}
		file << "\n\n\n";
	}
	file.close();
	cout << "\n" << "Your database has been updated... Goodbye!!!" << endl;
}
