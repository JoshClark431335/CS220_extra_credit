/* 
 * Simulates the flow of customers through a line at McMarty's.
 * Updated to give stats on wait time, number of orders dropped etc and 
 * to change the number of cashiers (previously 1)
 * Makes use of lists.
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "doublylinked.cpp"
#include "restaurant.h"

using namespace std;

int main ()
{
	Restaurant mcMarty;

	int simLength;
	int numCashiers;
	int ordersTaken =0;
	int busyness = 75;

	srand(time(NULL));

	cout << "Enter the length of time to run the McMarty's simulator: ";
	cin >> simLength;
	cout << "Enter the number of cashiers McMarty's has: ";
	cin >> numCashiers;
	cout << "Enter the efficiency of each cashier (percentage .70 - 1.00):\n";
	for (int i=0; i<numCashiers; i++){
		double newSpeed;
		cout << "Cashier #" << i+1 << ": ";
		cin >> newSpeed;
		mcMarty.addCashier(newSpeed);
	}
	cout << "Enter the probability as a percentage of a customer joining every minute:\n";
	cin >> busyness;

	for (int minute = 0; minute < simLength; minute++) {

		for (int i=0; i<mcMarty.num_cashiers; i++){
			Cashier* active;
			active = &mcMarty.registers[i];
			if (active->customers.size() > 0)
				active->fillOrder();
		}

		Cashier* shortestLine;
		for (int i=0; i<mcMarty.num_cashiers; i++){
			int length;
			if (i==0) {
				shortestLine = &mcMarty.registers[0];
				length = shortestLine->customers.size();
			}
			if (mcMarty.registers[i].customers.size() < length){
				shortestLine = &mcMarty.registers[i];
				length = shortestLine->customers.size();
			} else if (mcMarty.registers[i].customers.size() == length){
				int choice = rand() % 2;
				if (choice == 1){
					shortestLine = &mcMarty.registers[i];
					length = shortestLine->customers.size();
				}
			} 
		}

		//if a customer arrives
		if ((rand() % 100) <  busyness) {
			//and the lines aren't full
			if (shortestLine->customers.size() < 4){
				//add a customer
				shortestLine->addOrder();
				ordersTaken++;
			} else {
				//otherwise add to number of dropped customers
				mcMarty.dropped_custs++;
			}
		}

		cout << "minute=" << minute << endl;
		for (int i=0; i<mcMarty.num_cashiers; i++){
			Cashier *active;

			cout << "cashier #" << i+1 << endl;
			active = &mcMarty.registers[i];
			cout << "line size=" << active->customers.size() << endl;
			cout << "wait times=";
			for (int i=0; i<active->customers.size(); i++){
				Customer cust;
				active->customers.retrieve(i, cust);
				cout << cust.waitTime << " ";
			}
			cout << endl;
			cout << "first wait=";
			for (int i=0; i<active->customers.size(); i++){
				Customer cust;
				active->customers.retrieve(i, cust);
				cout << cust.timeWaited << " ";
			}
			cout << endl << endl;
		}
		char wait;
		//cin >> wait;
	}
	cout << "Restaurant stats\n";
	cout << "\taverage wait:  " << mcMarty.avgWait() << endl;
	cout << "\tlongest wait:  " << mcMarty.longestWait() << endl;
	cout << "\torders filled/taken: " << mcMarty.ordersFilled()  << "/" <<
		ordersTaken << ", " << setprecision(2) << (double) mcMarty.ordersFilled()
		/ ordersTaken << endl;
	cout << "\torders dropped: " << mcMarty.dropped_custs << endl;
	cout << endl;

	cout << "Cashier stats\n";
	for (int i=0; i<mcMarty.num_cashiers; i++){
		cout << "Cashier #" << i+1 << endl;
		cout << "\taverage wait: " << mcMarty.registers[i].avgWait() << endl;
		cout << "\tlongest wait: " << mcMarty.registers[i].longestWait << endl;
		cout << "\torders filled: " << mcMarty.registers[i].numFilled << endl;
		cout << endl;
	}

	return 0;
}
