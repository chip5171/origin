// homework_1_1.cpp : CPPL-5 Задача 1. Лямбда-функция

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char** argv) {

    setlocale(LC_ALL, "Rus");

    std::vector<int> v = { 4, 7, 9, 14, 12 };
    
    std::cout << "Входные данные:";
    std::for_each(v.begin(), v.end(), [](int v) { std::cout << ' ' << v; });
    std::cout << std::endl;
       
    std::cout << "Выходные данные:";
    std::for_each(v.begin(), v.end(), [](int v) { 
        if (v % 2 != 0) std::cout << " " << v * 3;
        else std::cout << " " << v;});
    std::cout << std::endl;

    return 0;
}

