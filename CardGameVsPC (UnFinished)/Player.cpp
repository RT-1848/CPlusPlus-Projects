#include <iostream>
#include <string>
#include "Deck.h"
#include "Card.h"
#include "Player.h"

// constructor
Player::Player(string pname){
	name = pname;
	score = 0;
	//hand[Max_Cards];
}

// The player removes one card from his hand and returns it.
// Depending on whether the player is a computer or human player, use different code:
// If the player is computer, i.e., the name of the player is "computer":
//      You can use whatever stratge you want here such as
//      choose a card randomly, choose the largest card,
//      choose the first card, or other more complicated algorithm
// If the player is "you" the human player, 
//      display the cards in hand
// Think what to do when there are less than 3 cards in each player's hand?
Card Player::playCard(){
	return hand[0];
}

// The player gets one card from the deck
void Player::drawCard(Deck& dk){
	for (int x = 0; x < Max_Cards; x++){
		if (!played[x]){
			hand[x] = dk.dealCard();
		}
		else if (played[x]){
			hand[x] = dk.dealCard();
		}
	}
	return;
}

// Add the point value of the card
// to the score of the player
void Player::addScore(Card aCard){
	score += aCard.getPointValue();
}

// Return the score the player has earned so far
int Player::getScore() const{
	return score;
}

// return the name of the player
string Player::getName() const{
	return name;
}

// Return true if no more cards in the player's hands,
// otherwise false
bool Player::emptyHand() const{
	if (played[0] > 0 || played[1] > 0 || played[2] > 0){
		return false;
	}
	else {
		return true;
	}
}

// overload the << operator to display all cards in player's hand
ostream& operator << (ostream& os, const Player& player){
	for (int x = 0; x < 3; x++){
		os << " " << (x+1) << " " << player.hand[x] << endl;
	}
	return os;
}
