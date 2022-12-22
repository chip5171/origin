// homework_3_2.cpp : CPPL-5 Задача 2. Копирование умных массивов

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
    smart_array(const smart_array& a) {
        logical_size = a.logical_size;
        actual_size = a.actual_size;
        array = new int[actual_size]();
        for (int i = 0; i < actual_size; ++i)
            array[i] = a.array[i];
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
    int get_size() const {
        return logical_size;
    }
    int get_element(int index) {
        if (index >= 0 && index < actual_size) {
            return array[index];
        }
        else {
            throw std::exception("В массиве нет элемента с таким индексом");
        }
    }
    void add_element(int element) {
        if (logical_size < actual_size) {
            array[logical_size] = element;
            logical_size++;
        }
        else {
            throw std::exception("Количество элементов превышает размер массива");
        }
    }
    void print_array(smart_array a) {
        for (int i = 0; i < a.get_size(); i++) {
            std::cout << a.get_element(i) << " ";
        }
    }
    smart_array& operator = (const smart_array& b) {
        if (&b != this) {
            if (actual_size > 0)
                delete[] array;
            actual_size = b.actual_size;
            logical_size = b.logical_size;
            array = new int[actual_size];
            for (int i = 0; i < actual_size; i++)
                array[i] = b.array[i];
        }
        return *this;
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
        std::cout << "массив arr: ";
        arr.print_array(arr);
        std::cout << std::endl;

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);
        std::cout << "массив new_array: ";
        arr.print_array(new_array);
        std::cout << std::endl;

        arr = new_array;
        std::cout << "Если arr = new_array, то" << std::endl;
        std::cout << "массив arr: ";
        arr.print_array(arr);
        std::cout << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
