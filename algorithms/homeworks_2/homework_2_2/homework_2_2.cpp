// homework_2_2.cpp : Ускоряем Фибоначчи на C++

// Сложность алгоритма по скорости: O(n)

// Сложность алгоритма по памяти: O(n)


#include <iostream>

unsigned long long f(unsigned int n)
{
    unsigned long long first = 0, second = 1, result = n;
    for (int i = 0; i < n; ++i) {
        result = first + second;
        first = second;
        second = result;
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    unsigned int x;
    std::cout << "Сколько вывести чисел?";
    std::cin >> x;
    std::cout << "Числа Фибоначчи:" << std::endl;
    for (int i = 0; i < x; ++i) {
        std::cout << i + 1 << ".\t" << "F(" << i << ") = " << f(i) << std::endl;
    }
    return 0;
}