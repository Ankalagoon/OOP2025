#pragma once
#include "Car.h"
class Volvo : public Car
{
public:
	Volvo(int cap = 200, int con = 5, int rains = 12, int suns = 16, int snows = 6)
		:Car(cap, con, rains, suns, snows) {
	};
};

