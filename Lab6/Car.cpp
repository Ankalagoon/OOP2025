#include "Car.h"


Car::~Car()
{
	this->fuel_capacity = 0;
	this->fuel_consumption = 0;
	this->rain_speed = 0;
	this->sunny_speed = 0;
	this->snow_speed = 0;
	this->speed = 0;
}

Car::Car(int cap, int con, int rains, int suns, int snows)
{
	this->fuel_capacity = cap;
	this->fuel_consumption = con;
	this->rain_speed = rains;
	this->sunny_speed = suns;
	this->snow_speed = snows;
}

void Car::SetFuelCap(int cap)
{
	this->fuel_capacity = cap;
}

int Car::GetFuelCap()
{
	return this->fuel_capacity;
}

void Car::SetFuelCon(int con)
{
	this->fuel_consumption = con;
}

int Car::GetFuelCon()
{
	return this->fuel_consumption;
}

void Car::SetSpeed(Weather cond)
{
	switch (cond) {
		case Weather::Rain:
			this->speed = this->rain_speed;
		case Weather::Sunny:
			this->speed = this->sunny_speed;
		case Weather::Snow:
			this->speed = this->snow_speed;
	}
}

int Car::GetSpeed() {
	return this->speed;
}
