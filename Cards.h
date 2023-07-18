#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;
class Player;

class Card {
public:
	Card();
	Card(string type);
	~Card();
	string getType();
	void play();
	friend std::ostream& operator<<(std::ostream&, const Card&);
private:
	Player* owner;
	string type;
};

class Deck {
public:
	Deck();
	~Deck();
	Card* Draw();
	void showAllCards();
private:
	vector<Card*> deckOfCards;
};

class Hand {
public:
	Hand();
	~Hand();
	void add(Card*);
	void showAllCards();
	vector<Card*> getCards();
private:
	vector<Card*> cardsinHand;
};