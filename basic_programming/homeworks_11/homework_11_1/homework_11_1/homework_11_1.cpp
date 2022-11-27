// homework_11_1.cpp : Задача 1. Статическая библиотека

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string>
#include "greeting_static_library.h"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);

    Greeting::Greeter grt;
    std::string name;

    std::cout << "Введите имя: ";
    std::cin >> name;
    grt.greet(name);

    system("pause");
    return 0;
}