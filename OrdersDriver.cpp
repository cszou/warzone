#include "OrdersDriver.h"
#include "Orders.h"

void testOrdersList() {
	cout << endl << "********** Part 3: Orders **********" << endl;
	OrderList* ol = new OrderList();
	ol->add(new Advance());
	ol->add(new Bomb());
	ol->add(new Negotiate());
	ol->add(new Advance());
	ol->add(new Airlift());
	ol->add(new Deploy());
	ol->add(new Blockade());
	ol->showOrders();
	ol->remove(4);
	ol->showOrders();
	ol->move(4, 2);
	ol->showOrders();
	delete ol;
}