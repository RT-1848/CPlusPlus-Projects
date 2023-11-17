
#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

int main() {
	srand(time(NULL));
	Deck deck;

	//Prints out the initial deck of cards
	cout << "Initial Deck of Cards: " << endl;
	cout << deck;
	cout << "=== End Initial Deck of Cards ===" << "\n" << endl;

	//Prints out the deck after shuffling the cards
	cout << "After Shuffle the Cards: " << endl;
	deck.shuffle();
	cout << deck;
	cout << "=== End Shuffled Cards ===" << "\n\n" << endl;

	//Class object and round counter
	int round = 1;
	Player p1("Joey");
	Player p2("Computer");

	
	//While loop to start the game all the way to the end, when the deck is empty
	while(!deck.isEmpty()){
		int choice; //User input choice
		int total; //To add the point value of both computer and user
		Card p1Card, p2Card; //Card objects

		//Draw cards before the start of the game
		p1.drawCard(deck);
		p2.drawCard(deck);
	

		//Game display
		cout << "====================" << endl;
		cout << "Round: " << round << endl;
		cout << p1.getName() << "'s score: " << p1.getScore() << endl;
		cout << p2.getName() << "'s score: " << p2.getScore() << endl;;
		cout << "====================" << endl;
		cout << p2.getName() << ":" << endl;
		cout << p2 << endl;
		cout << "--------------------" << endl;
		cout << "Here are your cards: " << endl;
		cout << p1 << endl;

		//Asks user for input for hand
		cout << "Select one card to play (enter 1, 2, or 3): ";
		cin >> choice;


		cout << p2.getName() << " played " << p2.playCard() << endl;
		cout << p1.getName() << " played " << p1.playCard() << endl;
		cout << endl;

		//If user's play is greater than the computer's play
		if (p1.playCard() > p2.playCard()){
			p1.addScore(p1.playCard());
			p1.addScore(p2.playCard());
			total = p1.playCard().getPointValue() + p2.playCard().getPointValue();
			cout << p1.getName() << " wins the hand, added " << total << " points" << endl;
		}
		//If user's play is less than the computer's play
		else if (p1.playCard() < p2.playCard()){
			p2.addScore(p1.playCard());
			p2.addScore(p2.playCard());
			total = p1.playCard().getPointValue() + p2.playCard().getPointValue();
			cout << p2.getName() << " wins the hand, added " << total << " points" << endl;
		}
		round++; //Increment the round
	}

	
	//The end of the game after the deck is empty, Displays total score and who won
	cout << "\n";
	cout << "=== END OF GAME ===" << endl;
	cout << p2.getName() << "'s" << " score: " << p2.getScore() << endl;
	cout << p1.getName() << "'s" << " score: " << p1.getScore() << endl;
	
	if (p1.getScore() > p2.getScore()){
		cout << p1.getName() << " wins!" << endl;
	}
	else if (p1.getScore() < p2.getScore()){
		cout << p2.getName() << " wins!" << endl;
	}
	
}
