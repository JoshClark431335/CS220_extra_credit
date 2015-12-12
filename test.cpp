#include <iostream>
#include "doublylinked.cpp"
//#include "cashier.h"
#include "restaurant.h"
using namespace std;

int main(){
	Cashier Ed;
	Customer Cust;
	List<Customer> myList;
	Restaurant mcMartys;

	cout << "0\n";
	mcMartys.add_cashier(.9);
	cout << "1\n";
	myList = Ed.customers;

	for (int i=0; i<10; i++){
		Ed.addOrder();
		/*
		   Customer *newCust;
		   newCust = new Customer;
		   myList.insert(i, *newCust);
		 */
	}
	for (int i=0; i<Ed.customers.size(); i++){
		Customer holder;
		Ed.customers.retrieve(i, holder);
		cout << holder.orderSize << " " << holder.waitTime << endl;
	}
	cout << endl;

	while (!Ed.customers.empty()){
		cout << Ed.customers.size() << endl;
		Ed.fillOrder();
	}
	cout << endl;

	return 0;
}
