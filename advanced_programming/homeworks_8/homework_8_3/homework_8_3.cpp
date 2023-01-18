// homework_8_3.cpp : CPPL-5 Задача 3*. std::unique_ptr своими руками

#include <iostream>

struct sTest {
    sTest() = default;
    sTest(int a, double b) : a_(a), b_(b) {}
    ~sTest() { std::cout << "destructor called\n"; }
    int a_ = 0;
    double b_ = 0;
};


template <class T>

class MyUniquePtr {
public:
    MyUniquePtr(T* p) {
        ptr_ = p;
    }
    ~MyUniquePtr() {
        delete ptr_;
    }
    MyUniquePtr<T>& operator*() const {
        return *ptr_;
    }
    T* release(T* p) {
        T* tmp = p;
        p = nullptr;
        return tmp;
    }
    MyUniquePtr(const MyUniquePtr<T>& uptr) = delete;
    MyUniquePtr<T>& operator=(const MyUniquePtr<T>& uptr) = delete;

private:
    T* ptr_;
};

int main() {
    
    sTest* S_ptr = new sTest(1, 2.0);

    MyUniquePtr<sTest> ptr(S_ptr);
    sTest* p = ptr.release(S_ptr);
    std::cout << p->a_ << "\n";
    
    return 0;
}