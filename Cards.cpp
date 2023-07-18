#include "Cards.h"
#include "Player.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

Card::Card() {
	this->type = "none";
}

Card::Card(string type) {
	this->type = type;
}

Card::~Card() {
}

string Card::getType()
{
	return this->type;
}

void Card::play()
{
	if (this->type == "reinforcement")
		this->owner->issueOrder("deploy");
	else if (this->type == "deplonacy")
		this->owner->issueOrder("negociate");
	else
		this->owner->issueOrder(this->type);
}

std::ostream& operator<<(std::ostream& strm, const Card &c) {
	return strm << c.type << " card.";
}

Deck::Deck() {
	for (int i = 0; i < 5;i++) {
		deckOfCards.push_back(new Card("bomb"));
		deckOfCards.push_back(new Card("reinforcement"));
		deckOfCards.push_back(new Card("blockade"));
		deckOfCards.push_back(new Card("airlift"));
		deckOfCards.push_back(new Card("diplomacy"));
	}
}

Card* Deck::Draw()
{
	srand(time(0));
	int random = rand() % (deckOfCards.size());
	Card* newCard = deckOfCards.at(random);
	deckOfCards.erase(deckOfCards.begin() + random);
	return newCard;
}

void Deck::showAllCards()
{
	cout << "Cards in the deck: ";
	for (auto c : deckOfCards)
		cout << c->getType() << " ";
	cout << endl;
	cout << "Total " << deckOfCards.size() << " cards." << endl;
}

Hand::Hand() {
	this->cardsinHand = *new vector<Card*>;
}

void Hand::add(Card* newCard) {
	cardsinHand.push_back(newCard);
}

void Hand::showAllCards() {
	cout << "Cards in the deck: ";
	for (auto c : cardsinHand)
		cout << c->getType() << " ";
	cout << endl;
	cout << "Total " << cardsinHand.size() << " cards." << endl;
}

vector<Card*> Hand::getCards()
{
	return this->cardsinHand;
}
