#include <stdlib.h>
#include "customer.h"

Customer::Customer(){
	orderSize = (rand() % 3) + 1;
	waitTime = 0;
	timeWaited = 0;
}
