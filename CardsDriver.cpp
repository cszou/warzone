#include "Cards.h"
#include "CardsDriver.h"
#include "Player.h"
#include <iostream>
using std::cout;
using std::endl;

void testCards() {
	cout << endl<< "********** Part 4: Cards **********" << endl;
	Deck* newDeck = new Deck();
	Hand* newHand = new Hand();
	newDeck->showAllCards();
	for (int i = 0; i < 10; i++) {
		Card* newCard = newDeck->Draw();
		cout << *newCard << endl;
		newHand->add(newCard);
	}
	newDeck->showAllCards();
	newHand->showAllCards();
	Player* p = new Player("congshu", newHand);
	cout << p->getHand()->getCards()[0]->getType() << endl;
}