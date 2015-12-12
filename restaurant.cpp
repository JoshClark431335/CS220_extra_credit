#include "restaurant.h"
#include <iostream>
using namespace std;

Restaurant::Restaurant(){
	num_cashiers = 0;
	dropped_custs= 0;
}

int Restaurant::longestWait(){
	int longest = 0;
	
	for (int i=0; i<num_cashiers; i++){
		if (registers[i].longestWait > longest)
			longest = registers[i].longestWait;
	}
	return longest;
}

int Restaurant::avgWait(){
	double sum = 0;

	for (int i=0; i<num_cashiers; i++){
		sum += registers[i].avgWait();
	}
	return sum / num_cashiers;
}

void Restaurant::addCashier(double speed){
	if (speed < .7 || speed > 1.0)
		return;
	if (num_cashiers>=0 && num_cashiers<10){
		num_cashiers++;
		registers[num_cashiers].changeSpeed(speed);
	}
}

int Restaurant::ordersFilled(){
	int numFilled = 0;
	for (int i=0; i<num_cashiers; i++){
		numFilled += registers[i].numFilled;
	}
	return numFilled;
}
