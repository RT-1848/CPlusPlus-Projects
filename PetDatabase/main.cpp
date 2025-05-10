// Description:
// This program will read in the number of clients and
// the next available client ID from the file
// groomerDB.dat, then will read in all the client info.
// The program will then ask what the user wants to do
// 1.  Print out a bill for a client
// 2.  Print out the information on a pet for a client
// 3.  Add a client
// 4.  Delete a client
// 5.  Print the database of clients
// 6.  Quit and write out the database
// There can be no more than 10 clients (this is the Groomer's side job :-)
// And no one is allowed more than 10 pets

#include <iostream>
#include <fstream>
#include <string>
#include "Client.h"

using std:: cout;
using std:: cin;
using std:: endl;

int main()
{
   Client clients[MAX_CLIENTS]; // Array of Clients
   int count = 0;	
   int nextClientId;            // next id to use if/when adding a client
   int clientId;                // hold's the client id when asked for
                                // by the user
   int choice;                  // hold's the choice entered by the user

    get_clients(clients,count,nextClientId); // Get the clients from the database

    // Steps 1 2 and 3 below will need to be wrapped
    // in the appropriate loop structure to repeat 
    // until the user enters the value 6
    
    // 1) Print out the menu of available options
    // 2) Get the user's action
    // 3) Perform appropriate action based on choice
		cout << "What would you like to do?" << endl;
		cout << "1. Print out a bill for a client" << endl
		<< "2. Print out the information on a pet for a client" << endl 
		<< "3. Add a client" << endl 
		<< "4. Delete a client" << endl
		<< "5. Print the database of clients" << endl 
		<< "6. Quit and write out the database" << endl; cin >> choice;

		while (choice != 6){
			if (choice == 1){
				print_bill(clients, clientId, count);
			}
			else if (choice == 2){
				print_pet(clients, clientId, count);
			}
			else if (choice == 3){
				add_client(clients, count, nextClientId);
			}
			else if (choice == 4){
				remove_client(clients, clientId, count);
			}
			else if (choice == 5){
				print_all_clients(clients, count);
			}
			
		cout << "What would you like to do?" << endl;
		cout << "1. Print out a bill for a client" << endl
		<< "2. Print out the information on a pet for a client" << endl 
		<< "3. Add a client" << endl 
		<< "4. Delete a client" << endl
		<< "5. Print the database of clients" << endl 
		<< "6. Quit and write out the database" << endl; cin >> choice;
		}
	
		if (choice == 6){
			save_database(clients, count, nextClientId);
		}
	
    return 0;
}
