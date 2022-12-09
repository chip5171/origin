// homework_6_2.cpp : Задача 2. Настоящая хэш-функция для строки

#include <iostream>
#include <string>
#include <cmath>

unsigned long real_string_hash(std::string str, int p, int n) {
    unsigned long sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += (static_cast<int>(str[i]) * pow(p,i));
    }
    return sum%n;
}

//______________________________________________________________________________________________________

int main(int argc, char** argv) {

    setlocale(LC_ALL, "Rus");

    std::string str;
    unsigned long hash = 0;
    int p, n;
    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;

    do {
        std::cout << "Введите строку: ";
        std::cin >> str;
        hash = real_string_hash(str, p, n);
        std::cout << "Хэш строки " << str << " = " << hash << std::endl;
    } 
    while (str != "exit");

    return 0;
}
