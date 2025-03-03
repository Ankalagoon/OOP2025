#include <iostream>
#include "Student.h"
#include "FunctiiGlobale.h"

int main() {
	Student* Gigel = new Student;
	Student* Marcu = new Student;
	Gigel->SetName("Gigel",5);
	Gigel->SetMath(9.99);
	Gigel->SetEng(5.3);
	Gigel->SetHist(7.6);
	printf("Nume: %s\n", Gigel->GetName());
	printf("Nota la Matematica: %f\n", Gigel->GetMath());
	printf("Nota la Engleza: %f\n", Gigel->GetEng());
	printf("Nota la Istorie: %f\n", Gigel->GetHist());
	printf("Media: %f\n", Gigel->GetAvg());
	Marcu->SetName("Marcu", 5);
	Marcu->SetMath(4.44);
	Marcu->SetEng(6.4);
	Marcu->SetHist(7.6);
	printf("NameCmp: %d\n", compareName(Gigel, Marcu,5));
	printf("MathCmp: %d\n", compareMath(Gigel, Marcu));
	printf("EngCmp: %d\n", compareEng(Gigel, Marcu));
	printf("HistCmp: %d\n", compareHist(Gigel, Marcu));
	printf("AvgCmp: %d\n", compareAvg(Gigel, Marcu));
}