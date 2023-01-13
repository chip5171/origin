// homeworks_7_1.cpp : CPPL-5 Задача 1. Уникальный вектор

#include <iostream>
#include <vector>
#include <algorithm>

void removeDuplicates(std::vector<int>& v) {
    sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());
}

void printVector(std::vector<int> v) {
    for (const auto& element : v)
        std::cout << element << " ";
    std::cout << std::endl;
}

int main(int argc, char** argv) {

    std::vector<int> v = { 1, 1, 2, 5, 6, 1, 2, 4 };
    
    std::cout << "[IN]: ";
    printVector(v);
    removeDuplicates(v);
    std::cout << "[OUT]: ";
    printVector(v);
    
    return 0;
}
