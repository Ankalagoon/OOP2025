#pragma once
#include "Car.h"
class Fiat : public Car
{
public:
	Fiat(int cap = 200, int con = 4, int rains = 11, int suns = 21, int snows = 6)
		:Car(cap, con, rains, suns, snows) {
	};
};

