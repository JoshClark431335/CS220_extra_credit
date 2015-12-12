#include <stdlib.h>
#include <iostream>
#include "cashier.h"
#include "doublylinked.cpp"
using namespace std;

Cashier::Cashier(){
	srand(time(NULL));
	speed = ((rand() % 31) / 100.0) + .7; //.70-1.00
	totalWait = 0;
	numFilled = 0;
	longestWait = 0;
}

void Cashier::changeSpeed(double newSpeed){
	speed = newSpeed;
}

void Cashier::addOrder(){
	Customer newCust;
	for (int i=0; i<newCust.orderSize; i++){
		double randnum = ((rand() % 100) + 1) / 100.0;
		if (randnum >= speed)
			newCust.waitTime += 2;
		else
			newCust.waitTime += 1;
	}
	customers.insert(customers.size(), newCust);
}

void Cashier::fillOrder(){
	Customer cust;
	if (!customers.empty()) {
		//cout << "size=" << customers.size() << endl;
		customers.retrieve(0, cust);
		//cout << cust.timeWaited << " " << cust.waitTime << endl;
		if (cust.timeWaited >= cust.waitTime -1){
			customers.remove(0, cust);
			totalWait += cust.waitTime;
			if (cust.waitTime > longestWait)
				longestWait = cust.waitTime;
			numFilled++;
		} else {
			cust.timeWaited++;
			customers.replace(0, cust);
		}
	}
}

double Cashier::avgWait(){
	return ((double) totalWait) / numFilled;
}
