/* 
 Program Description:    
  This program keeps tracks of sellers on a website named BidHere where you can add/delete sellers and see their performance
*/ 

#include <iostream>
#include <fstream>
#include <list>
#include "Person.h"
#include "Seller.h"
#include "Powerseller.h"
using namespace std;

//Function Prototypes
void printallSellers(list<Seller*>& sellers);
void checkSeller(list<Seller*>& sellers);
void addSeller(list<Seller*>& sellers);
void removeSeller(list<Seller*>& sellers);
void DisplayMenu();
bool ValidUser(bool valid);

int main() {
  /* main program logic:
  1. Initialization Step: Build the database of all the sellers.*/
	//Opens up the seller file and reads it into a seller list
	list<Seller*> sellers;
	string sellerType;
	ifstream file;
	file.open("sellers.dat");
	while (file >> sellerType){
		//Reading information for the Seller
		if (sellerType == "S"){
			double rating = 0;
			int totalitems = 0;
			string first, last, userID, email;

			file >> first >> last >> userID >> email >> rating >> totalitems;
			Seller* newSeller = new Seller(first, last, userID, email, rating, totalitems);
			sellers.push_back(newSeller);
		}
		else if (sellerType == "P"){
			//Reading information for the PowerSeller
			double rating = 0, currentsold;
			int totalitems = 0;
			string first, last, userID, email, website;

			file >> first >> last >> userID >> email >> rating >> totalitems >> website >> currentsold;
			PowerSeller* newPowerSeller = new PowerSeller(first,last,userID,email,rating,totalitems,website,currentsold);
			sellers.push_back(newPowerSeller);
		}
	}

  /*2.	User Authentication*/
	//Initialize valid variable to false and calls the user checker function
	bool valid = false;
	valid = ValidUser(valid);
	//If false then exits function
	if (valid == false){
		return 0;
	}

	//else continues to menu
  //*3.	Perform seller management:
	bool done = false;
	while (!done){

		//Displays the menu
		DisplayMenu();

		//Asks user for their choice
		int choice;
		cout << "Enter your choice:	", cin >> choice;

		//choosing 1 prints all seller info
		if (choice == 1){
			printallSellers(sellers);
		}
		//choosing 2 checks info of one particular seller
		else if (choice == 2){
			checkSeller(sellers);
		}
		//choosing 3 adds a seller to the list
		else if (choice == 3){
			addSeller(sellers);
		}
		//choosing 4 removes a seller from the list
		else if (choice == 4){
			removeSeller(sellers);
		}
		//choosing 5 exits the menu
		else if (choice == 5){
			cout << "\n" << "Thank you for using BidHere.com!" << endl;
			done = true;
		}
	}

	//Closes the files
	file.close();
	return 0;
}

//Function to display seller management menu
void DisplayMenu(){
	cout << "\n\n";
	cout << "Please choose from the following menu:" << endl;
	cout << "		1. Print all seller information" << endl;
	cout << "		2. Check information of one seller" << endl;
	cout << "		3. Add a seller" << endl;
	cout << "		4. Remove a seller" << endl;
	cout << "		5. Quit" << endl;
}

//Function to check whether the user is valid to enter the menu
bool ValidUser(bool valid){
	//Reading in users into a user list
	list<Person*> users;
	ifstream infile;
	infile.open("users.dat");
	while (infile){
		string first, last, userID, email;
		infile >> first >> last >> userID >> email;
		Person* newusers = new Person(first,last,userID,email);
		users.push_back(newusers);
	}

	//Closes File
	infile.close();

	//Checking for a valid user (using first and last name) to continue using the system
	string firstname,lastname, ID, pwinput;
	cout << "User Login:	" << "\n\n";
	cout << "First Name:	", cin >> firstname;
	cout << "Last Name:	", cin >> lastname;

	//While loop to check whether first and last name match the names in the user system
	bool invalidfirst = false;
	bool invalidlast = false;
	list<Person*>::iterator it = users.begin();
	while(it != users.end()){
		if (lastname == (*it)->getLastName()){
			invalidlast = true;
		}
		if (firstname == (*it)->getFirstName()){
			invalidfirst = true;
		}
		it++;
	}
	
	//If invalid user
	if (invalidfirst == false || invalidlast == false){
		cout << "\n";
		cout << "Invalid User. . . exit." << endl;
		valid = false;
		return valid;
	}

	//If passed the valid user check, then it asks for the password to access the seller menu
	string password = "LETMEIN";
	cout << "Password:	";
	cin >> pwinput;
	//If wrong password
	if (pwinput != password){
		cout << "\n";
		cout << "Invalid Password. . . exit." << endl;
		valid = false;
		return valid;
	}
	else{
		//If valid password
		cout << "\n";
		cout << "User Authentication Successful. . . Loading Main Menu" << endl;
		valid = true;
		return valid;
	}	
}


//Function that prints out all of the sellers information
void printallSellers(list<Seller*>& sellers){
	cout << "\n";
	PowerSeller* p;
	Seller* s;
	//For loop to iterate through the list and print out each seller
	for (Seller* seller : sellers){
		//Dynamic binding to print if powerseller
		if (PowerSeller* powerseller = dynamic_cast<PowerSeller*>(seller)){
			cout << *powerseller << endl;
		}
		//Else prints out the seller
		else{
			cout << *seller << endl;
		}
	}

	return;
}


//Function that checks the information of one seller
void checkSeller(list<Seller*>& sellers){
	string first,last;
	//Asks user for first and last name
	cout << "\n";
	cout << "Enter first name:	", cin >> first;
	cout << "Enter last name:	", cin >> last;
	cout << endl;
	//For loop to iterate through the list and check if first and last name matches the ones in the list
	for (Seller* seller : sellers){
		if (seller->getFirstName() == first && seller->getLastName() == last){
				//Prints out if the seller is a powerseller
				if (PowerSeller* powerseller = dynamic_cast<PowerSeller*>(seller)){
					cout << *powerseller << endl;
				}
				//Prints out if the seller is a seller
				else{
					cout << *seller << endl;
				}
		}
	}
	return;
}


//Function that adds a seller either S or P to the seller list
void addSeller(list<Seller*>& sellers){
	string first, last, userID, email, website;
	double rating;
	int itemsSold, yearsold;
	char choice;

	//Asks the user whether it is a powerseller or seller
	cout << "\n" << "Please enter the following information (enter invalid type to quit):" << "\n\n";
	cout << "Is the seller a (S)eller or (P)ower Seller?	", cin >> choice;
	//If choice is Seller
	if (choice == 'S'){
		cout << "\n";
		cout << "First name:	", cin >> first;
		cout << "Last name:	", cin >> last;
		cout << "User ID:	", cin >> userID;
		cout << "Email Address:	", cin >> email;
		cout << "Average Star Rating:	", cin >> rating;
		cout << "Total Items sold:	", cin >> itemsSold;
		cout << "\n";
		//Creates new seller and pushes it into the list
		Seller* newSeller = new Seller(first, last, userID, email, rating, itemsSold);
		sellers.push_back(newSeller);
		cout << "The new Seller has been added. Returning to Seller Management..." << "\n\n";
	}
	//If choice is PowerSeller
	else if (choice == 'P'){
		cout << "\n";
		cout << "First name:	", cin >> first;
		cout << "Last name:	", cin >> last;
		cout << "User ID:	", cin >> userID;
		cout << "Email Address:	", cin >> email;
		cout << "Average Star Rating:	", cin >> rating;
		cout << "Total Items sold:	", cin >> itemsSold;
		cout << "Website Address:	", cin >> website;
		cout << "Current year products Sold:	", cin >> yearsold;
		cout << "\n";
		//Creates new powerseller and pushes it into the list
		PowerSeller* newPowerSeller = new PowerSeller(first, last, userID, email, rating, itemsSold, website, yearsold);
		sellers.push_back(newPowerSeller);
		cout << "The new Power Seller has been added.	Returning to Seller Management..." << "\n\n";
	}
	//Else if invalid type of input then it goes back to menu
	else{
		return;
	}
}


//Function to remove a seller from the list
void removeSeller(list<Seller*>& sellers){
	string first,last;
	cout << "\n";
	cout << "Enter first name:	", cin >> first;
	cout << "Enter last name:	", cin >> last;
	//For loop to iterate through the seller list to see if first and last name match and to remove it
	for (list<Seller*>::iterator it = sellers.begin(); it !=sellers.end(); it++){
		//If found then delete the seller
		if (first == (*it)->getFirstName() && last == (*it)->getLastName()){
			delete *it;
			sellers.erase(it);
			return;
		}
	}
	//Else prints an error message and returns to the menu
	cout << "Seller not found. Returning to menu..." << endl;
	return;
}
