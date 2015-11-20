#include "queue.h"

struct customer{
    customer();
    int order_size;
    int wait_time;
    int time_waited;
};

class Cashier{
    public:
        Cashier();
        Cashier(double new_speed);
        void fill_order();
        Queue customers;
        int longest_wait;
    private:
        int total_wait;
        int num_filled;
        double speed;
};
