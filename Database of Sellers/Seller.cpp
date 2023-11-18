// implementation file for Seller class
#include "Seller.h"

// the code for overloaded << and >> operators are provided for you
/********************************************************************
* function: Seller overloaded >> operator
* arguments: an input stream and a right hand side Seller object
* returns: the input stream provided as an argument to this function
* comments: This function uses getline to read values from the input stream
*           into the corresponding variables in the right hand side Seller object.
********************************************************************/

istream& operator>> (istream& is, Seller& rhs)
{
	// read base class information
	string buffer;
	Person * person = &rhs;
	is >> *person;

	cout << "Average Star Rating:  ";
	getline(is, buffer);
	if( buffer[0] == '-' )
	{
		// we don't allow negative ratings
		rhs.averageRating = 0;
	}
	else
	{
		// if positive, convert string to unsigned
		rhs.averageRating = (unsigned)atoi(buffer.c_str());
	}
  cout << "Total Items sold:   ";
  getline(is, buffer);
  rhs.totalSold = (unsigned)atoi(buffer.c_str());
  
	return is;
}

/********************************************************************
* function: Seller overloaded << operator
* arguments: an output stream and a right hand side Seller object
* returns: the output stream provided as an argument to this function
* comments: This function prints values from the right hand side Seller object
*           to the output stream provided as an argument to this function.
********************************************************************/

ostream& operator<< (ostream& os, const Seller& rhs) //const Seller& rhs)
{
	rhs.print(os);

	// print the seller's information and return the output stream 
	
	return os;
}

//Constructor
Seller::Seller() : Person(){
	averageRating = 0;
	totalSold = 0;
}

//Copy Constructor
Seller::Seller(const Seller& source) : Person(source){
	averageRating = source.averageRating;
	totalSold = source.totalSold;
}

//Value Constructor
Seller::Seller(string newFirstName, string newLastName, string newUserID, string newEmailAddress, double newaverageRating, int newtotalSold) : Person(newFirstName, newLastName, newUserID, newEmailAddress){
	averageRating = newaverageRating;
	totalSold = newtotalSold;
}

//Function to set average rating for seller
void Seller::setaverageRating(const double &newaverageRating){
	averageRating = newaverageRating;
}

//Function to set total sold items for seller
void Seller::settotalSold(const int &newtotalSold){
	totalSold = newtotalSold;
}

//Function to get average rating for seller
double Seller::getaverageRating() const{
	return averageRating;
}

//Function to get total sold items for seller
int Seller::gettotalSold() const{
	return totalSold;
}

//Virtual print and read functions for the Seller Class
void Seller::print(ostream &os) const{
	Person::print(os);
	os << "Average Star Rating: " << averageRating << endl;
	os << "Total Items Sold: " << totalSold << endl;
}

void Seller::read(istream &is){
	Person::read(is);
	is >> averageRating;
	is >> totalSold;
}
