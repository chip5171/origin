// Задача 3.1. Калькулятор двух чисел

#include <iostream>

class Calculator
{
private:
    double num1;
    double num2;

public:
    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        else {
            return false;
        }
    }
    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        else {
            return false;
        }
    }
    double add() {
        return (num1 + num2);
    }
    double multiply() {
        return (num1 * num2);
    }
    double subtract_1_2() {
        return (num1 - num2);
    }
    double subtract_2_1() {
        return (num2 - num1);
    }
    double divide_1_2() {
        return (num1 / num2);
    }
    double divide_2_1() {
        return(num2 / num1);
    }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");
    double num1 = 1, num2 = 1;
    Calculator calc;

    while (true) {
        std::cout << "Введите num1: ";
        std::cin >> num1;
        if (calc.set_num1(num1) == false) {
            std::cout << "Неверный ввод!" << std::endl;
            continue;
        }
        while (true) {
            std::cout << "Введите num2: ";
            std::cin >> num2;
            if (calc.set_num2(num2) == false) {
                std::cout << "Неверный ввод!" << std::endl;
                continue;
            }
            std::cout << "num1 + num2 = " << calc.add() << std::endl;
            std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
            std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
            std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
            std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
            std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
            break;
        }
    }
}
