#include "type.h"
//Implement the struct type defined in type.h here

//overloaded < operator for flightRec
//this function compares the destinations between two flightRec
bool flightRec::operator < (const flightRec & rhs) const{
	return rhs.destination < destination;
}

//overloaded == operator for flightRec
//this function compares the origins and destinations between two flightRec
bool flightRec::operator == (const flightRec & rhs) const{
	if (rhs.origin == origin && rhs.destination == destination){
		return true;
	}
	else {
		return false;
	}
}

//overloaded output operator for flightRec struct
ostream& operator << (ostream & os, const flightRec & f){
	os << f.origin << "\t" << f.destination << "\t" << f.flightNum << "\t" << f.price << "\t" << endl;
	return os;
}
