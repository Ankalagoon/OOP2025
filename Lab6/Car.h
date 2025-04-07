#pragma once
#include "Weather.h"
class Car 
{
	
protected:
	int fuel_capacity;
	int fuel_consumption;
	int speed=0;
	int rain_speed, sunny_speed, snow_speed;
public:
	virtual ~Car();
	Car(int cap, int con, int rains, int suns, int snows);
	virtual void SetFuelCap(int cap);
	virtual int GetFuelCap();
	virtual void SetFuelCon(int con);
	virtual int GetFuelCon();
	virtual void SetSpeed(Weather cond);
	virtual int GetSpeed();
};

