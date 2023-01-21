// homework_9_1.cpp : CPPL-5 Задача 1. Перемещение объектов

#include <iostream>
#include <vector>

template <class T>
void move_vectors(std::vector<T>& a, std::vector<T>& b) {
    b = std::move(a);
}
template <class T>
void print_vector(std::vector<T>& v) {
    for (const auto elem : v) { std::cout << elem << " "; }
    std::cout << std::endl;
}


int main(int argc, char** argv) {
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;

    move_vectors<std::string>(one, two);

    std::cout << "one: ";
    print_vector(one);
  
    std::cout << "two: ";
    print_vector(two);
          
    return 0;
}

