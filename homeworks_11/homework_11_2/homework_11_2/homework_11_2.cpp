// homework_11_1.cpp : Задача 2. Динамическая библиотека

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>
#include "leaving_dynamic_library.h"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);

    Leaving::Leaver lv;
    std::string name;

    std::cout << "Введите имя: ";
    std::cin >> name;
    lv.leave(name);

    system("pause");
    return 0;
}