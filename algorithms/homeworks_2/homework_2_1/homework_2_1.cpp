// homework_2_1.cpp : Рекурсивное нахождение чисел Фибоначчи на C++

// Сложность алгоритма по скорости: O(2^n)

// Сложность алгоритма по памяти: O(1)


#include <iostream>

unsigned long long f(unsigned int n)
{
    return n < 2 ? n : f(n - 2) + f(n - 1);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");
    
    unsigned int x;
    std::cout << "Сколько вывести чисел? ";
    std::cin >> x;
    std::cout << "Числа Фибоначчи:" << std::endl;
    for (int i = 0; i < x; ++i) {
        std::cout << i + 1 << ".\t" << "F(" << i << ") = " << f(i) << std::endl;
    }
    return 0;
}