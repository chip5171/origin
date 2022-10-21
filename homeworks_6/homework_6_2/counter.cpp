#include <iostream>
#include "counter.h"

void Counter::setPrivCount(int value) {
	privCount = value;
}
Counter::Counter(int value) {
	setPrivCount(value);
}
Counter::Counter() {
	privCount = 1;
}
int Counter::increment() {
	return (++privCount);
}
int Counter::decrement() {
	return (--privCount);
}
void Counter::getPrivCount() {
	std::cout << privCount << std::endl;
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