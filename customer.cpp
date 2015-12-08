#include "customer.h"
#include <stdlib.h>

Customer::Customer(){
	orderSize = (rand() % 3) + 1;
	waitTime = 0;
	timeWaited = 0;
}
