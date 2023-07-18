#pragma once
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <ostream>
#include <iostream>
using std::cout;
using std::endl;

class Order {
public:
	virtual ~Order() {};
	virtual bool validate() = 0;
	virtual void execute() = 0;
	virtual string getName() { return name; };
	friend std::ostream& operator<<(std::ostream&, const Order&);
private:
	string name = "";
};

class OrderList {
public:
	OrderList();
	OrderList(vector<Order*>);
	//OrderList& operator =(const OrderList& orderList);
	~OrderList();
	void add(Order* order);
	void remove(int pos);
	void move(int beginPos, int targetPos);
	void showOrders();
private:
	vector<Order*> orders;
};

class Deploy :public Order {
public:
	Deploy() { name = "deploy"; };
	~Deploy() {};
	bool validate();
	void execute();
	string getName() { return name; };
private:
	string name;
};

class Advance :public Order {
public:
	Advance() { name = "advance"; };
	~Advance() {};
	bool validate();
	void execute();
	string getName() { return name; };
private:
	string name;
};

class Bomb :public Order {
public:
	Bomb() { name = "bomb"; };
	~Bomb() {};
	bool validate();
	void execute();
	string getName() { return name; };
private:
	string name;
};

class Blockade :public Order {
public:
	Blockade() { name = "blockade"; };
	~Blockade() {};
	bool validate();
	void execute();
	string getName() { return name; };
private:
	string name;
};

class Airlift :public Order {
public:
	Airlift() { name = "airlift"; };
	~Airlift() {};
	bool validate();
	void execute();
	string getName() { return name; };
private:
	string name;
};

class Negotiate :public Order {
public:
	Negotiate() { name = "negotiate"; };
	~Negotiate() {};
	bool validate();
	void execute();
	string getName() { return name; };
private:
	string name;
};