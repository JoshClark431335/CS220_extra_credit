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
    //Line of customers - each value in this queue
    //represents a the time (minute) a customer arrived
    //at McMarty's and got in line.
    Queue custQ;      

    int simLength,         // Length of simulation (minutes)
        timeArrived,       // Time the customer that was just served arrived
        waitTime,          // How long the customer just served waited (current minute - timeArrived)
        totalServed = 0,   // Total number of customers served
        totalWait   = 0,   // Total waiting time for all customers
        maxWait     = 0,   // Longest wait
        numArrivals = 0;

    srand(time(NULL)); //initialize random number generator

    cout << "Enter the length of time to run the McMarty's simulator : ";
    cin >> simLength;

    for (int minute = 0 ; minute < simLength ; minute++ ) {
        if ( !custQ.empty() ) {
            custQ.retrieve(timeArrived);
            custQ.serve();
            totalServed++;
            waitTime = minute - timeArrived;
            totalWait += waitTime;
            if (waitTime>maxWait)
                maxWait = waitTime;

        }


        switch ( rand() % 4 ) {
            // The number generated above will be between 0 and 3
            // If 0 or 3, then no customers will be added, 
            // If 2, then 2 customers will be added. 
            // If 1, then one customer will be added.

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
