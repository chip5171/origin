// homework_6_3.cpp : CPPL-5 Задача 3*. Аналог std::vector

#include <iostream>

template <class T>

class MyVector {

private:
    int size_;
    int capacity_;
    T* vector_;

public:
    MyVector() {
        size_ = 0;
        capacity_ = 0;
        vector_ = NULL;
    }
    MyVector(const MyVector& v) {
        size_ = v.size_;
        capacity_ = v.capacity_;
        vector_ = new T[capacity_]();
        for (int i = 0; i < capacity_; ++i)
            vector_[i] = v.vector_[i];
    }
    MyVector(int size) {
        size_ = 0;
        capacity_ = size;
        if (size != 0) vector_ = new T[size]();
        else vector_ = 0;
    }
    ~MyVector() {
        if (vector_) delete[] vector_;
    }
    int get_size() const {
        return size_;
    }
    int get_capacity() const {
        return capacity_;
    }
    T at(int index) {
        if (index >= 0 && index < capacity_) {
            return vector_[index];
        }
        else {
            throw std::exception("No element with this index");
        }
    }
    void print_array(MyVector v) {
        for (int i = 0; i < v.get_size(); i++) {
            std::cout << v.at(i) << " ";
        }
    }
    void push_back(T value) {
        if (size_ < capacity_) {
            vector_[size_] = value;
            size_++;
        }
        else {
            capacity_ *= 2;
            T* new_arr = new T[capacity_];
            for (int i = 0; i < size_; i++) {
                new_arr[i] = vector_[i];
            }
            delete[] vector_;
            vector_ = new_arr;
            new_arr[size_] = value;
            size_++;
        }

    }

};

//______________________________________________________________________________

int main(int argc, char** argv) {

    try {
        MyVector<int> vec(3);
        vec.push_back(1);
        vec.push_back(4);
        //vec.push_back(155);
        //vec.push_back(7);
        //vec.push_back(-5);

        std::cout << "Vector: ";
        vec.print_array(vec);
        std::cout << std::endl;
        std::cout << "Size: " << vec.get_size() << std::endl;
        std::cout << "Capacity: " << vec.get_capacity() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}


