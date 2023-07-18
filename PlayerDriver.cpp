#include "PlayerDriver.h"
#include "Player.h"
#include "Map.h"
#include <iostream>
using std::cout;
using std::endl;

void testPlayer() {
	cout << endl << "********** Part 2: Player **********" << endl;
	Player* aPlayer = new Player("Congshu");
	aPlayer->issueOrder("advance");
	aPlayer->issueOrder("airlift");
	aPlayer->issueOrder("Advance");
	aPlayer->issueOrder("deploy");
	aPlayer->issueOrder("blockade");
	aPlayer->issueOrder("bomb");
	aPlayer->showOrders();
	cout << "Calling toAttack:" << endl;
	for (auto t : aPlayer->toAttack())
		cout << t->getName() << endl;
	cout << "Calling toDefend:" << endl;
	for (auto t : aPlayer->toDefend())
		cout << t->getName() << endl;
}