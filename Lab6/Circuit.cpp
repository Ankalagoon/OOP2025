#include "Circuit.h"
#include <iostream>
void Circuit::SetLength(int x)
{
	this->length = x;
}

void Circuit::AddCar(Car* c)
{
	this->num++;
	this->cars[num] = c;
}

void Circuit::SetWeather(Weather w) {
	this->w = w;
}

Weather Circuit::GetWeather()
{
	return this->w;
}

void Circuit::Race()
{
	for (int i = 1;i <= num;i++) {
		cars[i]->SetSpeed(this->w);
		int sp = cars[i]->GetSpeed();
		int cost = cars[i]->GetFuelCap() / cars[i]->GetFuelCon();
		if (sp * cost < length) times[i] = 1e9;
		else times[i] = length / sp;
		ranks[i] = i;
	}
	///Sortare
	for (int i = 1;i <= this->num;i++) {
		for (int j = 1;j <= this->num;j++) {
			if (times[i] < times[j]) {
				int swp;
				swp = times[i];
				times[i] = times[j];
				times[j] = swp;
				swp = ranks[i];
				ranks[i] = ranks[j];
				ranks[j] = swp;
			}
		}
	}
}

void Circuit::ShowFinalRanks()
{
	printf("Final rankings:\n");
	for (int i = 1;i <= this->num;i++) {
		if(times[i]!=1e9) printf("%d\n", ranks[i]);
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	printf("DNFs:\n");
	for (int i = 1;i <= this->num;i++) {
		if (times[i] == 1e9) printf("%d\n", ranks[i]);
	}
}
