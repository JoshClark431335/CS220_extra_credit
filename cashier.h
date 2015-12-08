#include "customer.h"
#include "doublylinked.h"

class Cashier{
	public:
		Cashier();
		Cashier(double newSpeed);
		void fillOrder();
		List<Customer> customers;
		int longestWait;
	private:
		int totalWait;
		int numFilled;
		double speed;
};
