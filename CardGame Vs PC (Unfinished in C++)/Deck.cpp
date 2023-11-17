#include "Deck.h"
#include "Card.h"
#include <iostream>

//Deck Constructor, puts all the cards in the deck
Deck::Deck(){
	topCard = 0;
	for (int x = 2; x <= 14; x++){
		theDeck[topCard] = Card(x, HEART);
		topCard++;
	}
	for (int x = 2; x <= 14; x++){
		theDeck[topCard] = Card(x, SPADE);
		topCard++;
	}
	for (int x = 2; x <= 14; x++){
		theDeck[topCard] = Card(x, CLUB);
		topCard++;
	}
	for (int x = 2; x <= 14; x++){
		theDeck[topCard] = Card(x, DIAMOND);
		topCard++;
	}
}

//Deals the card out by removing one from the top of the deck
Card Deck::dealCard(){
	topCard--;
	return theDeck[topCard];
}

//Deck shuffling
void Deck::shuffle(){
	Card Temporary;

	//randomizes up to 100 times
	for (int i = 0; i < 100; i++){
		int x = rand() % 52;
		int y = rand() % 52;

		Temporary = theDeck[x];
		//Swap the 2 cards
		theDeck[x] = theDeck[y];
		theDeck[y] = Temporary;
	}

}

//Checks to see if deck is empty, returns false is not empty
bool Deck::isEmpty(){
	if (topCard > 0){
		return false;
	}
	else{
		return true;
	}
}

//prints out the deck
ostream& operator << (ostream& os, const Deck& Deck){
	for (int i = 0; i < 52; i++){
		os << Deck.theDeck[i] << endl;
	}
	return os;
}
