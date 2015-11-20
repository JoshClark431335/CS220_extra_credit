#include "cashier.h"
#include <stdlib.h>
#include <iostream>

customer::customer(){
    srand(time(NULL));
    order_size = rand() % 3 + 1; //1-3
    wait_time = 0;
    time_waited = 0;
}

Cashier::Cashier(){
    srand(time(NULL));
    speed = ((rand() % 31) / 100.0) + .7; //.70-1.00
    total_wait = 0;
    num_filled = 0;
}

Cashier::Cashier(double new_speed){
    speed = new_speed;
    total_wait = 0;
    num_filled = 0;
}

void Cashier::fill_order(){
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


