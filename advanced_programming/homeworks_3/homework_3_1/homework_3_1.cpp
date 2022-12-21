// homework_3_1.cpp : CPPL-5 Задача 1. Умный массив

#include <iostream>

class smart_array {
private:
    int logical_size;
    int actual_size; 
    int* array;
public:
    smart_array() {
        logical_size = 0;
        actual_size = 0;
        array = NULL;
    }
    smart_array(int size) {
        logical_size = 0;
        actual_size = size;
        if (size != 0) array = new int[size]();
        else array = 0;
    }
    ~smart_array() {
        if (array) delete[] array;
    }
    int* add_element(int element) {
        if (logical_size < actual_size) {
            array[logical_size] = element;
            logical_size++;
            return array;
        }
        else {
            throw std::exception("Количество элементов превышает размер массива");
        }
    }
    int size() const {
        return logical_size;
    }
    int get_element(int index) {
        if (index < actual_size) {
            return array[index];
        }
        else {
            throw std::exception("В массиве нет элемента с таким индексом");
        }
    }
};

//______________________________________________________________________________

int main(int argc, char** argv) {

    setlocale(LC_ALL, "Rus");
    
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
