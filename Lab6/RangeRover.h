#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
	RangeRover(int cap = 400, int con = 2, int rains = 8, int suns = 10, int snows = 8)
		:Car(cap, con, rains, suns, snows) {
	};
};

