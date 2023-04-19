#pragma once
#include <vector>
using std::vector;
class Territory;
class Hand;
class Order;

class Player {
public:
	Player();
	Player(const Player& p);
	Player& operator =(const Player& p);
	vector<Territory*> toAttack();
	vector<Territory*> toDefend();
	void issuOrder();
private:
	vector<Territory*> territoriesOwned;
	vector<Order*> orders;
	Hand* cardsInHand;
};