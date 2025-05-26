#include <iostream>
#include "CatalogRo.h"
#include <random>
#include <time.h>
using namespace std;

int main() {

	CatalogRo R;
	///R.PrintStud();
	srand(time(NULL));
	for (int i = 0;i < R.GetNrs();i++) {
		for (int j = 0;j < R.GetNrm();j++) {
			R.GetStud(i).GetM(j).SetGrade(rand()%11);
		}
	}	
	R.Rank([](Student& a, Student& b) {Student Gigel;Gigel = a;a = b;b = Gigel;});
	return 0;
}