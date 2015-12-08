#include "cashier.h"

class Restaurant{
    public:
        int avg_wait();
        int longest_wait;
        void add_cashier(double speed);
        int dropped_custs;

        Cashier* registers;
        int num_cashiers;
};
