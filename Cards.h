#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;

class Card {
public:
	Card();
	Card(string type);
	~Card();
	string getType();
	void play();
private:
	string type();
};

class Deck {
public:
	Deck();
	~Deck();
	void Draw();
private:
	vector<Card*> deckOfCards;
};

class Hand {
public:
	Hand();
	~Hand();
private:
	vector<Card*> cardsinHand;
};