#include "Card.h"
#include "Deck.h"

using namespace std;

//default constructor. It is required since another class
//may declare an array of Card objects.
Card::Card(){
	
}

  //another constructor
Card::Card(int face, cardType atype){
	faceValue = face;
	suit = atype;
	if (faceValue == 14){ //Points for the Ace card
		pointValue = 15;
	}
	else if (faceValue > 10 && faceValue < 14){ //Points for Jack, King, Queen
		pointValue = 10;
	}
	else if (faceValue <= 10){ //Points for 2-10
		pointValue = faceValue;
	}
}

	
  // overload the << operator
ostream& operator << (ostream& os, const Card& rhs){
	//outputs the suits for the deck
	if (rhs.suit == HEART){
		os << "HEART-";
	}
	else if (rhs.suit == DIAMOND){
		os << "DIAMOND-";
	}
	else if (rhs.suit == CLUB){
		os << "CLUB-";
	}
	else if (rhs.suit == SPADE){
		os << "SPADE-";
	}

	//outputs the face values and points for the deck
	if (rhs.faceValue == 14){
		os << "Ace" << " " << rhs.pointValue << " points"; //" 15 points";
	}
	else if (rhs.faceValue == 13){
		os << "King" << " " << rhs.pointValue << " points";// " 10 points";
	}
	else if (rhs.faceValue == 12){
		os << "Queen" << " " << rhs.pointValue << " points";//" 10 points";
	}
	else if (rhs.faceValue == 11){
		os << "Jack" << " " << rhs.pointValue << " points";//" 10 points";
	}
	else {
		os << rhs.faceValue << " " << rhs.pointValue << " points";
	}
	
return os;
}

// compare the point value of cards *this and cd.
// return true if *this has a smaller pointer value than cd.
// otherwise, return false.
bool Card::operator < (const Card& rhs) const{
	if (pointValue < rhs.pointValue){
		return true;
	}
	else {
		return false;
	}
}


// compare the point value of cards *this and cd.
// return true if *this has a larger point value than cd.
// otherwise, return false.
bool Card::operator > (const Card& rhs) const{
	if (pointValue > rhs.pointValue){
		return true;
	}
	else {
		return false;
	}
}

// compare the point value of cards *this and cd
// return true if they have the same point value,
// otherwise return false.
bool Card::operator == (const Card& rhs) const{
	if (pointValue == rhs.pointValue){
		return true;
	}
	else {
		return false;
	}
}

// return the point value  // inline method
int Card::getPointValue() const{
	return pointValue;
}
