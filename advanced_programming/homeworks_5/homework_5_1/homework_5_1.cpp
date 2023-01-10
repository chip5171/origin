// homework_5_1.cpp : CPPL-5 Задача 1. Возведение в квадрат

#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
T square(T n) {
    return n * n;
}

template <class VT>
std::vector<VT> square(std::vector<VT> v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] * v[i];
    }
    return v;
}
template <class VT>
void printVector(VT v) {
    std::for_each(v.begin(), v.end(), [](int v) { std::cout << v << ", "; });
}

int main(int argc, char** argv) {

    int n = 4;
    std::vector<int> v {-1, 4, 8 };

    std::cout << "[IN]: " << n << std::endl;
    std::cout << "[OUT]: " << square(n) << std::endl;

    std::cout << "[IN]: "; 
    printVector(v);
    std::cout << std::endl;
    std::cout << "[OUT]: ";
    printVector(square(v));
   
    return 0;
}
