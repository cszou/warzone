#pragma once
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <ostream>

class OrderList {
public:
	OrderList();
	OrderList(const OrderList& orderList);
	OrderList& operator =(const OrderList& orderList);
	~OrderList();
	void remove();
	void move();
private:
	vector<Order> orders;
};

class Order {
public:
	virtual ~Order();
	virtual bool validate() = 0;
	virtual void execute() = 0;
	virtual string getName() = 0;
	friend std::ostream& operator<<(std::ostream&, const Order&);
};

class Deploy :public Order {
public:
	Deploy();
	~Deploy();
	bool validate();
	void execute();
	string getName();
};

class Advance :public Order {
public:
	Advance();
	~Advance();
	bool validate();
	void execute();
	string getName();
};

class Bomb :public Order {
public:
	Bomb();
	~Bomb();
	bool validate();
	void execute();
	string getName();
};

class Blockade :public Order {
public:
	Blockade();
	~Blockade();
	bool validate();
	void execute();
	string getName();
};

class Airlift :public Order {
public:
	Airlift();
	~Airlift();
	bool validate();
	void execute();
	string getName();
};

class Negotiate :public Order {
public:
	Negotiate();
	~Negotiate();
	bool validate();
	void execute();
	string getName();
};