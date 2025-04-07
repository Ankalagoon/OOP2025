#pragma once
#include "Car.h"
class Seat : public Car
{
public:
	Seat(int cap = 100, int con = 3, int rains = 8, int suns = 12, int snows = 3)
		:Car(cap, con, rains, suns, snows) {
	};
};

