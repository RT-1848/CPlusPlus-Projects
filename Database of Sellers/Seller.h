// header file for Seller class
#ifndef SELLER_H
#define SELLER_H

#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Seller : public Person
{
public:
	//Constructor
	Seller();

	//Copy Constructor
	Seller(const Seller& source);

	//Value Constructor
	Seller(string newFirstName, string newLastName, string newUserID, string newEmailAddress, double newaverageRating, int newtotalSold);

	//Function for getting sellers average rating
	double getaverageRating() const;

	//Function for getting sellers total sold items
	int gettotalSold() const;

	//Function for setting the seller's average rating
	void setaverageRating(const double &newaverageRating);

	//Function for setting the seller's total sold items
	void settotalSold(const int &newtotalSold);

	//Print and Read Virtual Functions
  virtual void print(ostream& os) const;
  virtual void read(istream& is);

	// overloaded stream input and output operators for getting and setting
	friend istream &operator>>(istream &is, Seller &rhs);
  friend ostream &operator<<(ostream &os, const Seller& rhs);

protected:
	//average star rating received from buyers
	double averageRating;
	//Total number of items sold
	int totalSold;
};

#endif
