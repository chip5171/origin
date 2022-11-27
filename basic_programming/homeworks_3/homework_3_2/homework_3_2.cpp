// homework_3_2.cpp : Задача 2. Счётчик

#include <iostream>
#include <Windows.h>

class Counter {
private:
    int privCount;
public:
    void setPrivCount(int value) { 
        privCount = value;
    } 
    Counter(int value) { 
        setPrivCount(value);
    }
    Counter() {
        privCount = 1;
    } 
    int increment() {
        return (++privCount);
    }
    int decrement() {
        return (--privCount);
    }
    void getPrivCount() {
        std::cout << privCount << std::endl;
    }
};

void counterCalc(Counter& count) {
    bool b = true;
    char d;
    while (b != false) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> d;
        switch (d) {
            case('+'):
                count.increment();
                break;
            case ('-'):
                count.decrement();
                break;
            case('='):
                count.getPrivCount();
                break;
            case('x'):
                std::cout << "До свидания! \n";
                b = false;
                break;
            default:
                std::cout << "Не верная команда!\n";
                break;
        }
    }
}

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
        //count.getPrivCount();
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

