#include "cashier.h"

class Restaurant{
    public:
	Restaurant();
        double avgWait();
        int longestWait();
        void addCashier(double speed);
        int dropped_custs;
	int ordersFilled();

        Cashier registers[10];
        int num_cashiers;
};
