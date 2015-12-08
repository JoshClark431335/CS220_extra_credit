#include "cashier.h"
#include <stdlib.h>
#include <iostream>

Cashier::Cashier(){
    srand(time(NULL));
    speed = ((rand() % 31) / 100.0) + .7; //.70-1.00
    totalWait = 0;
    numFilled = 0;
}

Cashier::Cashier(double newSpeed){
    speed = newSpeed;
    totalWait = 0;
    numFilled = 0;
}

void Cashier::fillOrder(){
    /*double temp1;
    customer cust;
    
    customers.retrieve(cust);

    srand(time(NULL));
    if (cust->wait_time != 0){
        for (int i=0; i < cust->order_size; i++){
            temp1 = ((rand() % 101 + 1) / 100.0);
            if (temp1>=speed)
                cust->wait_time += 2;
            else
                cust->wait_time += 1;
        }
    }

    cust->time_waited++;
    custo*/
}

