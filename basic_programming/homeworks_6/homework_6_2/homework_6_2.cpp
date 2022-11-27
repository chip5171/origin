// homework_6_2.cpp : Задача 2. Класс

#include <iostream>
#include <Windows.h>
#include "counter.h"

int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str;
    int val;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> str;
    if (str == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> val;
        Counter count(val);
        counterCalc(count);
    }
    else if (str == "нет") {
        Counter count;
        count.getPrivCount();
        counterCalc(count);
    }
    else {
        std::cout << "Не верный ответ!";
    }
    return 0;
}
