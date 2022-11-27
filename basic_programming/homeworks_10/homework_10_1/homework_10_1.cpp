// homework_10_1.cpp : Задача 1. Простейший проект

#include <iostream>
#include <Windows.h>
#include <cstdlib>

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    std::string name;
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "Здравствуйте, " << name << "!" << std::endl;
    system("pause");
    return 0;
}

