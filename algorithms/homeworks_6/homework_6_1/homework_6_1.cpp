// homework_6_1.cpp : Задача 1. Наивная хэш-функция для строки

#include <iostream>
#include <string>

int simple_string_hash(std::string str) {
    int hash = 0;
    for (int i = 0; i < str.length(); i++) {
         hash += static_cast<int>(str[i]);
    }
    return hash;
}

//______________________________________________________________________________________________________

int main(int argc, char** argv) {

    setlocale(LC_ALL, "Rus");
    
    std::string str;
    int hash = 0;

    do {
        std::cout << "Введите строку: ";
        std::cin >> str;
        hash = simple_string_hash(str);
        std::cout << "Наивный хэш строки " << str << " = " << hash << std::endl;
    } while (str != "exit");

    return 0;
}
