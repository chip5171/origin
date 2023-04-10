// homework_1_2.cpp : MAP-5 Задание 2 «Параллельные вычисления»

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <array>

using namespace std::chrono_literals;

std::vector<int> createVector(size_t size) {
    std::vector<int> v(size);
    for (int i = 0; i < size; i++) v[i] = i + 1;
    return v;
}

std::vector<int> sumOfVectors(int size) {
    std::vector<int> v1 = createVector(size);
    std::vector<int> v2 = createVector(size);
    std::vector<int> result;
    std::transform(v1.begin(), v1.end(), v2.begin(), std::back_inserter(result), std::plus<int>());
    return result;
}

//___________________________________________________________________________________
    int main(int argc, char** argv) {
        setlocale(LC_ALL, "rus");

    std::array <int, 4> size{ 1000, 10000, 100000, 1000000 };
    std::array <int, 5> thNumber{ 1, 2, 4, 8, 16 };

    std::cout << "Количество аппаратных ядер: ";
    std::cout << std::thread::hardware_concurrency() << std::endl;

    for (const auto& i : size)
        std::cout << "         " << i << "\t";
    std::cout << std::endl;

    for (const auto& j : thNumber) {
        std::cout << j << " потоков ";
        for (const auto& i : size) {
            auto start = std::chrono::high_resolution_clock::now();
            std::vector<std::thread> t;
            for (int k = 0; k < j; k++) {
                t.push_back(std::thread(sumOfVectors, i));
            }
            for (auto& t : t) { t.join(); }
       
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration <double> time = end - start;
            std::cout << time.count() << " \t";
        }
        std::cout << std::endl;
    }
    return 0;
}

