// homework_2_2.cpp : Ускоряем Фибоначчи на C++

// Сложность алгоритма по скорости: O(n)

// Сложность алгоритма по памяти: O(n)


#include <iostream>

unsigned long long f(int n) {
    static long long arr[100];
    if (arr[n] != 0) return arr[n];
    unsigned long long t = n;
    if (n < 0) return 0;
    if (n > 1) t = f(n - 1) + f(n - 2);
    return arr[n] = t;
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