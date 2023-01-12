// homeworks_6_2.cpp : CPPL-5 Задача 2. Удаление дубликатов

#include <iostream>
#include <set>

int main(int argc, char** argv) {

    int number, chek;
    
    std::cout << "[IN]: " << std::endl;
    std::cin >> chek;
    int count = 0;
    std::set<int, std::greater<>> mm;
    while (count < chek) {
        std::cin >> number;
        mm.insert(number);
        count++;
    }
    std::cout << "[OUT]: " << std::endl;
    for (const auto& var : mm) {
        std::cout << var << std::endl;
    }
    return 0;
}

