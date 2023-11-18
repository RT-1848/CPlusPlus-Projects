// implementation file for Person class
#include "Person.h"

// the code for overloaded >> and << operator is provided for you
/********************************************************************
* function: Person overloaded >> operator
* arguments: an input stream and a right hand side Person object
* returns: the input stream provided as an argument to this function
* comments: This function uses getline to read values from the input stream
*           into the corresponding variables in the right hand side Person object.
********************************************************************/

istream& operator>> (istream& is, Person& rhs)
{
	cout << "First name:  ";
	getline(is,rhs.firstName);

	cout << "Last name:  ";
	getline(is,rhs.lastName);

	cout << "User ID:  ";
	getline(is,rhs.userID);

	cout << "Email Address:  ";
	getline(is,rhs.emailAddress);

	return is;
}

/********************************************************************
* function: Person overloaded << operator
* arguments: an output stream and a right hand side Person object
* returns: the output stream provided as an argument to this function
* comments: This function prints values from the right hand side Person object
*           to the output stream provided as an argument to this function.
********************************************************************/
ostream& operator<< (ostream& os, Person& rhs)
{
	// allow the incoming argument to have a valid this pointer
	// (so we can actually call functions from it)
	//Person * person = (Person *)&rhs;

	// print person information and return the output stream
	//os << " Name: " << rhs.getName() << endl;
	os << " Name: " << rhs.firstName << " " << rhs.lastName << endl;
	os << " User ID: " << rhs.userID << endl;
	os << " Email: " << rhs.emailAddress << endl;

	return os;
}

//Virtual print function to display information
void Person::print(ostream& os) const{
	os << " Name: " << firstName << " " << lastName << endl;
	os << " User ID: " << userID << endl;
	os << " Email: " << emailAddress << endl;
}

//Virtual function to read in info of a person
void Person::read(istream& is){
	cout << "First name:  ";
	getline(is,firstName);

	cout << "Last name:  ";
	getline(is,lastName);

	cout << "User ID:  ";
	getline(is,userID);

	cout << "Email Address:  ";
	getline(is,emailAddress);
}

//Constructors
Person::Person(){
	firstName = "";
	lastName = "";
	userID = "";
	emailAddress = "";
}

//Copy Constructor
Person::Person(const Person& source){
	firstName = source.firstName;
	lastName = source.lastName;
	userID = source.userID;
	emailAddress = source.emailAddress;
}

//Value Constructor
Person::Person(string newFirstName, string newLastName, string newUserID, string newEmailAddress){
	firstName = newFirstName;
	lastName = newLastName;
	userID = newUserID;
	emailAddress = newEmailAddress;
}

//Function to set first name
void Person::setFirstName(const string &newFirstName){
	firstName = newFirstName;
}

//Function to set last name
void Person::setLastName(const string &newLastName){
	lastName = newLastName;
}

//Function to set email 
void Person::setEmailAddress(const string &newEmailAddress){
	emailAddress = newEmailAddress;
}

//Function to set user ID
void Person::setUserID(const string &newUserID){
	userID = newUserID;
}

//Function to get first name
string Person::getFirstName() const{
	return firstName;
}

//Function to get last name
string Person::getLastName() const{
	return lastName;
}

//Function to get email 
string Person::getEmailAddress() const{
	return emailAddress;
}

//Function to get user ID
string Person::getUserID() const{
	return userID;
}

//Overloaded Operator == to compare
bool Person::operator== (const Person& rhs) const{
	if (firstName == rhs.firstName && lastName == rhs.lastName){
		return true;
	}
	else{
		return false;
	}
}

//Overloaded Operator != to compare
bool Person::operator!= (const Person& rhs) const{
	if (firstName != rhs.firstName && lastName != rhs.lastName){
		return true;
	}
	else{
		return false;
	}
}

//Overloaded Operator < to compare
bool Person::operator< (const Person& rhs) const{
	if (firstName < rhs.firstName && lastName < rhs.lastName){
		return true;
	}
	else{
		return false;
	}
}

//Overloaded Operator > to compare
bool Person::operator> (const Person& rhs) const{
	if (firstName > rhs.firstName && lastName > rhs.lastName){
		return true;
	}
	else{
		return false;
	}
}

//Overloaded Operator = to assign
Person& Person::operator= (const Person& rhs){
	firstName = rhs.firstName;
	lastName = rhs.lastName;
	userID = rhs.userID;
	emailAddress = rhs.emailAddress;
	
	return *this;
}
