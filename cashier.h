#include "customer.h"
#include "doublylinked.h"

class Cashier{
	public:
		Cashier();
		void changeSpeed(double newSpeed);
		void addOrder();
		void fillOrder();
		List<Customer> customers;
		int longestWait;
		double avgWait();
		int numFilled;
	private:
		int totalWait;
		double speed;
};
