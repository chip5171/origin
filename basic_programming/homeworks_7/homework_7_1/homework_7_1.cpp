// homework_7_1.cpp : Задача 1. Препроцессорные директивы

#include <iostream>
#define MODE 1

#ifndef MODE
#error Сonstant is not defined
#endif

#if MODE == 1
int add(int x, int y) {
    return (x + y);
}
#endif

//___________________________________________________________________//

int main(int argc, char** argv) {
    setlocale(LC_ALL, "rus");
    int a, b;
#if MODE == 0 
    std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == 1
    std::cout << "Работаю в боевом режиме" << std::endl;
    std::cout << "Введите число 1: ";
    std::cin >> a;
    std::cout << "Введите число 2: ";
    std::cin >> b;
    std::cout << "Результат сложения: " << add(a, b) << std::endl;
#else
    std::cout << "Неизвестный режим.Завершение работы" << std::endl;
#endif
    return 0;
}

