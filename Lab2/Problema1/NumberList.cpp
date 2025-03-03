#include "NumberList.h"
#include <iostream>

void NumberList::Init()
{
    this->count = 0;
}

bool NumberList::Add(int x)
{
    if (count == 10) return false;
    this->numbers[count] = x;
    this->count++;
    return true;
}



void NumberList::Sort()
{
    int ok = 1, x;
    while (ok) { /// bubble sort
        ok = 0;
        for (int i = 0;i < this->count - 1;i++) {
            if (this->numbers[i] > this->numbers[i + 1]) { /// swap(this->numbers[i],this->numbers[i+1])
                x = this->numbers[i];
                this->numbers[i] = this->numbers[i + 1];
                this->numbers[i + 1] = x;
                ok = 1;
            }
        }
    }
}

void NumberList::Print()
{
    for (int i = 0;i < count;i++) {
        printf_s("%d ", this->numbers[i]);
    }
}


