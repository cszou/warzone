#pragma once
#include "Player.h"
#include "Cards.h"
#include "Map.h"
#include "Orders.h"
#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
using std::transform;

Player::Player()
{
	this->name = "noName";
	this->listOfOrder = new OrderList();
	this->cardsInHand = new Hand();
}

Player::Player(const Player& p)
{
	this->name = p.name;
	this->listOfOrder = new OrderList(*(p.listOfOrder));
	this->cardsInHand = new Hand(*p.cardsInHand);
	for (auto t : p.territoriesOwned)
		this->territoriesOwned.push_back(new Territory(*t));
}

Player::Player(string name)
{	
	this->name = name;
	this->cardsInHand = new Hand();
	this->listOfOrder = new OrderList();
}

Player::Player(string name, Hand* h)
{
	this->name = name;
	this->cardsInHand = h;
}

Player& Player::operator=(const Player& p)
{
	this->name = p.name;
	this->listOfOrder = new OrderList(*(p.listOfOrder));
	this->cardsInHand = new Hand(*p.cardsInHand);
	for (auto t : p.territoriesOwned)
		this->territoriesOwned.push_back(new Territory(*t));
	return *this;
}

vector<Territory*> Player::toAttack()
{
	vector<Territory*> toAttack;
	toAttack.push_back(new Territory("Quebec"));
	toAttack.push_back(new Territory("Ontario"));
	return toAttack;
}

vector<Territory*> Player::toDefend()
{
	vector<Territory*> toDefend;
	toDefend.push_back(new Territory("Alberta"));
	toDefend.push_back(new Territory("BC"));
	return toDefend;
}

void Player::issueOrder(string type)
{
	transform(type.begin(), type.end(), type.begin(), std::tolower);
	if (type == "advance") {
		Order* newOrder = new Advance();
		this->listOfOrder->add(newOrder);
	}
	else if (type == "deploy") {
		Order* newOrder = new Deploy();
		this->listOfOrder->add(newOrder);
	}
	else if (type == "bomb") {
		Order* newOrder = new Bomb();
		this->listOfOrder->add(newOrder);
	}
	else if (type == "blockade") {
		Order* newOrder = new Blockade();
		this->listOfOrder->add(newOrder);
	}
	else if (type == "airlift") {
		Order* newOrder = new Airlift();
		this->listOfOrder->add(newOrder);
	}
	else if (type == "negotiate") {
		Order* newOrder = new Negotiate();
		this->listOfOrder->add(newOrder);
	}
	else
		cout << "Wrong order instuction!" << endl;
}

void Player::showOrders()
{
	this->listOfOrder->showOrders();
}

void Player::setHand(Hand* h)
{
	this->cardsInHand = h;
}

Hand* Player::getHand()
{
	return this->cardsInHand;
}

