#pragma once
#include "Car.h"
#include "Weather.h"
class Circuit
{
	int length;
	int num=0;
	Car* cars[10];
	int ranks[10];
	int times[10];
	Weather w;
public:
	void SetLength(int x);
	void SetWeather(Weather w);
	Weather GetWeather();
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

