#include "Orders.h"
#include <algorithm>
using std::find;
#include <iostream>
using std::cout;
using std::endl;

std::ostream& operator<<(std::ostream& ostream, const Order& o)
{
	return ostream << "This is " << o.name << " order.";
}

OrderList::OrderList() {
	this->orders = *new vector<Order*>;
}

OrderList::OrderList(vector<Order*> orders) {
	this->orders = orders;
}

//OrderList& OrderList::operator=(const OrderList& orderList)
//{
//	// TODO: insert return statement here
//}

OrderList::~OrderList() {
	for (auto o : this->orders)
		delete o;
}

void OrderList::add(Order* order)
{
	this->orders.push_back(order);
}

void OrderList::remove(int pos)
{
	Order* temp = this->orders[pos - 1];
	this->orders.erase(this->orders.begin() + pos - 1);
	delete temp;
}

void OrderList::move(int beginPos, int targetPos)
{
	if (beginPos != targetPos) {
		Order* tempOrder = this->orders[beginPos - 1];
		this->orders.erase(this->orders.begin() + beginPos - 1);
		this->orders.insert(this->orders.begin() + targetPos - 1, tempOrder);
	}
}

void OrderList::showOrders()
{
	cout << "Showing all orders: ";
	for (auto o : this->orders) {
		cout << o->getName() << ", ";
	}
	cout << endl;
}

bool Deploy::validate() {
	return true;
}

void Deploy::execute() {
	cout << "Deply order executed!" << endl;
}

bool Advance::validate() {
	return true;
}

void Advance::execute() {
	cout << "Advance order executed!" << endl;
}

bool Bomb::validate() {
	return true;
}

void Bomb::execute() {
	cout << "Bomb order executed!" << endl;
}

bool Blockade::validate() {
	return true;
}

void Blockade::execute() {
	cout << "Blockade order executed!" << endl;
}

bool Airlift::validate() {
	return true;
}

void Airlift::execute() {
	cout << "Airlift order executed!" << endl;
}

bool Negotiate::validate() {
	return true;
}

void Negotiate::execute() {
	cout << "Deply order executed!" << endl;
}