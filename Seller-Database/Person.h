
/********************************************************************
 * File: Person.h
 * Contents: declaration of class Person
 ********************************************************************/

#ifndef PERSON_H
#define PERSON_H

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
  // constructors and copy constructors
  Person();

  Person(const Person &source);

  Person(string newFirstName, string newLastName, string newUserID,
         string newEmailAddress);

  // destructor (not required for this project)
  // virtual ~Person();

  // overloaded operators for comparing two Persons
  // These operators check the sellers' names for equality and inequality.
  // If they are, true is returned.  If they are not equal, then false is
  // returned
  bool operator==(const Person &rhs) const;
  bool operator!=(const Person &rhs) const;
  bool operator<(const Person &rhs) const;
  // bool operator<= (const Person& rhs) const;
  bool operator>(const Person &rhs) const;
  // bool operator>= (const Person& rhs) const;

  // overloaded operator for assigning one Person's information to another
  Person &operator=(const Person &rhs);

  // overloaded stream input and output operators for getting and setting
  // Person information easily.

  friend istream &operator>>(istream &is, Person &rhs);

  friend ostream &operator<<(ostream &os, Person &rhs);

  // Optional function for getting the seller's whole name
  // string getName() const;

  // function for getting the seller's first name
  string getFirstName() const;

  // function for getting the seller's last name
  string getLastName() const;

  // function for getting the seller's email address
  string getEmailAddress() const;

  // function for getting the seller's location (address)
  string getUserID() const;

  // declare the "print" function below
  // function for printing object info, generally to screen.
  // The parameter of this method should be of output filestream type
  // IMPORTANT: The declaration of the "print" method was intentionally left
  // empty for the students to fill in
  virtual void print(ostream& os) const;

  // declare the "read" function below
  // function for retrieving object info from file
  // The parameter of this function should be of input filestream type
  // IMPORTANT: The declaration of the "read" method was intentionally left
  // empty for the students to fill in
  virtual void read(istream& is);

  // Optional function for setting the seller's name
  // void setName(const string& newFirstName, const string& newLastName);

  // function for setting the seller's name
  void setFirstName(const string &newFirstName);

  // function for setting the seller's name
  void setLastName(const string &newLastName);

  // function for setting the seller's email address
  void setEmailAddress(const string &newEmailAddress);

  // function for setting the seller's location (address)
  void setUserID(const string &newUserID);



protected:
  // first name of person
  string firstName;
  // last name of person
  string lastName;
  // user ID of person
  string userID;
  // email address
  string emailAddress;
};

#endif
