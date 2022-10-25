// homework_7_1.cpp : Задача 1. Препроцессорные директивы

#include <iostream>
#define MODE 1

int func(int x, int y) {
    return (x + y);
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "rus");
    int x, y;

#ifndef MODE
#error Сonstant is not defined
#endif
#if MODE == 0 
    std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
    std::cout << "Работаю в боевом режиме" << std::endl;
    std::cout << "Введите число 1: ";
    std::cin >> x;
    std::cout << "Введите число 2: ";
    std::cin >> y;
    std::cout << "Результат сложения: " << func(x, y) << std::endl;
#else
    std::cout << "Неизвестный режим.Завершение работы" << std::endl;
#endif
    return 0;
}

