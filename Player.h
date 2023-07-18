#pragma once
#include <vector>
#include "Orders.h"
using std::vector;
class Territory;
class Hand;
class Order;
class OrderList;

class Player {
public:
	Player();
	Player(const Player& p);
	Player(string name);
	Player(string name, Hand* h);
	Player& operator =(const Player& p);
	vector<Territory*> toAttack();
	vector<Territory*> toDefend();
	void issueOrder(string type);
	void showOrders();
	void setHand(Hand* h);
	Hand* getHand();
private:
	string name;
	vector<Territory*> territoriesOwned;
	OrderList* listOfOrder;
	Hand* cardsInHand;
};