//aux_functions.cpp
#include <iostream>
#include "aux_functions.h"

void arraySort(Race* arr, int x) {
    for (int i = x - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j].totalTime() > arr[j + 1].totalTime())
            {
                Race tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}


void except(std::string name, int n) {
    if (n == 1)
        std::cout << "Попытка зрегистрировать неправильный тип транспортного средства!" << std::endl;
    if (n == 2)
        std::cout << name << " уже зарегистрирован!" << std::endl;
}
