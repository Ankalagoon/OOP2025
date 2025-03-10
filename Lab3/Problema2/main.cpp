#include "Canvas.h";
#include <iostream>

using namespace std;

int main() {
	Canvas C(60, 60);
	C.DrawCircle(20,20,10,'x');
	C.Print();
	C.FillCircle(20, 20, 10, 'x');
	C.Print();
	C.DrawRect(10, 50, 40, 20,'-');
	C.Print();
	C.FillRect(10, 50, 40, 20,'-');
	C.Print();
	C.Clear();
	C.SetPoint(20, 20, 'W');
	C.Print();
	C.DrawLine(10,10,20,20,'=');
	C.Print();
}