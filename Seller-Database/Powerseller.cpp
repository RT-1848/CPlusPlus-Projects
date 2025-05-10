// implementation file for Powerseller class
#include "Powerseller.h"

// the code for overloaded << and >> operators are provided for you

/********************************************************************
* function: PowerSeller overloaded >> operator
* arguments: an input stream and a right hand side PowerSeller object
* returns: the input stream provided as an argument to this function
* comments: This function uses getline to read values from the input stream
*           into the corresponding variables in the right hand side PowerSeller object.
********************************************************************/
istream& operator>> (istream& is, PowerSeller& rhs)
{
	string buffer;
	Seller * seller = &rhs;

	// get base class information

	is >> *seller;

	cout << "Website Address:  ";
	getline(is,rhs.website);

	cout << "Current year products Sold:  ";
	getline(is,buffer);
	if( buffer[0] == '-' )
	{
		// we don't allow negative numbers
		rhs.currentSold = 0;
	}
	else
	{
		// if positive, convert string to unsigned
		rhs.currentSold = (unsigned)atoi(buffer.c_str());
	}

	return is;
}

/********************************************************************
* function: PowerSeller overloaded << operator
* arguments: an output stream and a right hand side PowerSeller object
* returns: the output stream provided as an argument to this function
* comments: This function prints values from the right hand side PowerSeller object
*           to the output stream provided as an argument to this function.
********************************************************************/

ostream& operator<< (ostream& os, const PowerSeller& rhs)
{
		// Print base class information

	rhs.print(os);

	// Print PowerSeller information

	os << "Website Address: " << rhs.website << endl;
	os << "Current Year Products Sold: " << rhs.currentSold << endl;

	// print the seller's information and return the output stream 
	return os;
}

//Constructor
PowerSeller::PowerSeller() : Seller(){
	website = "";
	currentSold = 0;
}

//Copy Constructor
PowerSeller::PowerSeller(const PowerSeller& source) : Seller(source){
	website = source.website;
	currentSold = source.currentSold;
}

//Value Constructor
PowerSeller::PowerSeller(string newFirstName, string newLastName, string newUserID, string newEmailAddress, double newaverageRating, int newtotalSold, string newwebsite, int newcurrentSold) : Seller(newFirstName, newLastName, newUserID, newEmailAddress, newaverageRating, newtotalSold){
	website = newwebsite;
	currentSold = newcurrentSold;
}

//Function to set seller website
void PowerSeller::setWebsite(const string &newWebsite){
	website = newWebsite;
}

//Function to set currently sold items for seller
void PowerSeller::setCurrentSold(const int &newcurrentSold){
	currentSold = newcurrentSold;
}

//Function to get seller website
string PowerSeller::getwebsite() const{
	return website;
}

//Function to get currently sold items for seller
int PowerSeller::getcurrentSold() const{
	return currentSold;
}

//Virtual print and read functions for the Seller Class
void PowerSeller::print(ostream &os) const{
	Seller::print(os);
}

void PowerSeller::read(istream &is){
	Seller::read(is);
	getline(is, website);
	is >> currentSold;
}
