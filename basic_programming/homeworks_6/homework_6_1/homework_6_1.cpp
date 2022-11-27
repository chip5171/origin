//homework_6_1: Задача 6.1. Математические функции
#include <iostream>
#include <cmath>
#include "math_func.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");

    double num1 = 1, num2 = 1;
    int calc;
    bool b = true;

    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;
    
    while (b != false) {
    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень, 6 - выход): ";
    std::cin >> calc;
        switch (calc) {
        case 1:
            std::cout << num1 << " + " << num2 << " = " << add(num1, num2) << std::endl;
            break;
        case 2:
            std::cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << std::endl;
            break;
        case 3:
            std::cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << std::endl;
            break;
        case 4:
            if (num2 != 0) {
                std::cout << num1 << " / " << num2 << " = " << divide(num1, num2) << std::endl;
            }
            else {
                std::cout << "На 0 делить нельзя!" << std::endl;
                break;
            }
            break;
        case 5:
            std::cout << num1 << " в степени " << num2 << " = " << power(num1, num2) << std::endl;
            break;
        case 6:
            std::cout << "До свидания! \n";
            b = false;
            break;
        default:
            std::cout << " Неверный номер операции! " << std::endl;
            break;
        }
    }
}


