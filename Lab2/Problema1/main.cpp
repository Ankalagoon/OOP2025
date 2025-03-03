#include <iostream>
#include "NumberList.h"

int main() {
    NumberList a;
    a.Init();
    a.Add(10);
    a.Add(2);
    a.Add(4);
    a.Add(8);
    a.Add(6);
    a.Sort();
    a.Print();
}