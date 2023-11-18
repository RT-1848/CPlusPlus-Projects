#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Deck.h"
#include "Card.h"

using namespace std; 

class Player
{
public:
    static const int Max_Cards = 3; //Max # of cards a player can have

    // constructor
	Player(string pname);

    // The player removes one card from his hand and returns it.
    // Depending on whether the player is a computer or human player, use different code:
    // If the player is computer, i.e., the name of the player is "computer":
    //      You can use whatever stratge you want here such as
    //      choose a card randomly, choose the largest card,
    //      choose the first card, or other more complicated algorithm
    // If the player is "you" the human player, 
    //      display the cards in hand
    // Think what to do when there are less than 3 cards in each player's hand?
	Card playCard();

    // The player gets one card from the deck
	void drawCard(Deck& dk);

    // Add the point value of the card
    // to the score of the player
	void addScore(Card aCard);

    // Return the score the player has earned so far
	int getScore() const;

    // return the name of the player
  string getName() const; 

    // Return true if no more cards in the player's hands,
    // otherwise false
	bool emptyHand() const;

    // overload the << operator to display all cards in player's hand
  friend ostream& operator << (ostream&, const Player&);

private:
	string  name="unknown";       //player's name
	int     score;      //score the player has earned so far
	Card    hand[Max_Cards];    //the array holding cards 
	bool    played[Max_Cards];  //played[i] indicates if hand[i] has a card or not.
                              // make sure to initialize the values to "false"
};

#endif
