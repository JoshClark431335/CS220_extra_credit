#include <iostream>
#include "cashier.h"
using namespace std;

int main(){
	Cashier cashierA(1.0);
	Customer Bill;

	//Bill= new Customer>;
	cashierA.customers.insert(cashierA.customers.size(), Bill);

	return 0;
}
