#pragma once
#include "Car.h"
class BMW : public Car
{
public:
	BMW(int cap = 100, int con = 2, int rains = 10, int suns = 20, int snows = 5)
		:Car(cap, con, rains, suns, snows) {
	};
};

