/* 
 * Simulates the flow of customers through a line at McMarty's.
 * Makes use of queues.
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "queue.h"

using namespace std;

int main ()
{
	Restaurant mcMarty;

	int simLength,         // Length of simulation (minutes)
	    timeArrived,       // Time the customer that was just served arrived
	    waitTime,          // How long the customer just served waited (current minute - timeArrived)
	    totalServed = 0,   // Total number of customers served
	    totalWait   = 0,   // Total waiting time for all customers
	    maxWait     = 0,   // Longest wait
	    numArrivals = 0;

	srand(time(NULL)); //initialize random number generator

	cout << "Enter the length of time to run the McMarty's simulator: ";
	cin >> simLength;

	mcMarty.add_cashier(1.0);
	mcMarty.add_cashier(0.9);
	mcMarty.add_cashier(0.7);

	for (int minute = 0; minute < simLength; minute++) {

		/*if ( !custQ.empty() ) {
			custQ.retrieve(timeArrived);
			custQ.serve();
			totalServed++;
			waitTime = minute - timeArrived;
			totalWait += waitTime;
			if (waitTime>maxWait)
				maxWait = waitTime;

		}*/

		for (int server=0; i<mcMarty.num_cashiers; i++){
			Cashier* active;
			if Cashier.customers
		}

		switch ( rand() % 4 ) {
			case 0 :
			case 3 : numArrivals = 0; break;
			case 1 : numArrivals = 1; break;
			case 2 : numArrivals = 2;
		}

		//add new customers to the line
		for ( int j = 0 ; j < numArrivals ; j++ )
			custQ.append(minute);

	}

	cout << endl;
	cout << "Customers served : " << totalServed << endl;
	cout << "Average wait     : " << setprecision(2) 
		<< double(totalWait)/totalServed << endl;
	cout << "Longest wait     : " << maxWait << endl;

	return 0;
}
