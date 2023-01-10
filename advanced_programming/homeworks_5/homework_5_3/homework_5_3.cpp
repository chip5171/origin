// homework_5_3.cpp : CPPL-5 Задача 3. Счётчик чисел

#include <algorithm>
#include <iostream>

class MyFunctor {
private:
    int sum_;
    int count_;
public:
    MyFunctor() : count_(0), sum_(0) {}
    void operator()(int x) {
        if (x % 3 == 0) {
            count_++;
            sum_ += x;
        }
    }
    int get_sum() const { return sum_; }
    int get_count() const { return count_; }
};

int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "Rus");
    
    MyFunctor mf;

    int arr[] = { 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN]: ";
    for (int value : arr) std::cout << value << ' ';
    std::cout << std::endl;

    mf = std::for_each(arr, arr + sizeof(arr) / sizeof(arr[0]), mf);

    std::cout << "[OUT]: get_sum() = " << mf.get_sum() << "\n";
    std::cout << "[OUT]: get_count() = " << mf.get_count() << "\n";

    return 0;
}


