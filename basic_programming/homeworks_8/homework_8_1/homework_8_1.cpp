// homework_8_1.cpp : Задача 1. Простое исключение

#include <iostream>
#include <string>
#include <Windows.h>

int function(std::string str, int forbidden_length) {
    if ((str.length()) == (forbidden_length))
        throw "Вы ввели слово запретной длины! До свидания";
    return (str.length());
}

//_______________________________________________________________//

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);

    std::string world;
    int length;
    std::cout << "Введите запретную длину: ";
    std::cin >> length;

    while (true) {
        std::cout << "Введите слово: ";
        std::cin >> world;
        try {
            std::cout << "Длина слова " << world << " равна: " << function(world, length) << std::endl;
        }
        catch (const char* bad_length) {
            std::cout << bad_length << std::endl;
            break;
        }
    }
    return 0;
}

