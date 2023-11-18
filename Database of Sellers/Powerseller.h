// header file for Powerseller class
#ifndef POWERSELLER_H
#define POWERSELLER_H

#include "Seller.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class PowerSeller : public Seller
{
public:
	//Constructor
	PowerSeller();

	//Copy Constructor
	PowerSeller(const PowerSeller& source);

	//Value Constructor
	PowerSeller(string newFirstName, string newLastName, string newUserID, string newEmailAddress, double newaverageRating, int newtotalSold, string website, int currentSold);

	//Function for getting seller's website
	string getwebsite() const;

	//Function for getting seller's currently sold items
	int getcurrentSold() const;

	//Function for setting the seller's current website
	void setWebsite(const string &newWebsite);

	//Function for setting the seller's currently sold items
	void setCurrentSold(const int &newcurrentSold);

	//Print and Read Virtual Functions
  virtual void print(ostream& os) const;
  virtual void read(istream& is);

	// overloaded stream input and output operators for getting and setting
	friend istream &operator>>(istream &is, PowerSeller &rhs);
  friend ostream &operator<<(ostream &os, const PowerSeller& rhs);

private:
	//Website of the seller
	string website;
	//Current items sold by the seller
	int currentSold;
};

#endif
