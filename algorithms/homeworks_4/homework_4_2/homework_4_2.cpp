// homework_4_2.cpp : Задача 2. Добавление в изменяемый динамический массив

#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < logical_size; i++) {
        std::cout << " " << arr[i];
    }
    for (int i = logical_size; i < actual_size; i++) {
        std::cout << " _";
    }
    std::cout << std::endl;
}
int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int new_element) {
  
    if (logical_size < actual_size) {
        arr[logical_size] = new_element;
        logical_size++;
        return arr;
    }
    else {
        actual_size *= 2;
        int* new_arr = new int[actual_size];
        for (int i = 0; i < logical_size; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        new_arr[logical_size] = new_element;
        logical_size++;
        return new_arr;
    }
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");

    int logical_size, actual_size, new_element;

    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    while (true) {
        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size;
        if (logical_size > actual_size) {
            std::cout << "Ошибка!Логический размер массива не может превышать фактический!" << std::endl;
        }
        else break;
    }

    int* arr = new int[actual_size]();
    for (int i = 0; i < logical_size; i++) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }
    std::cout << "Динамический массив:";
    print_dynamic_array(arr, logical_size, actual_size);
    
    while (true) {
        std::cout << "Введите элемент для добавления: ";
        std::cin >> new_element;
        if (new_element != 0) {
            arr = append_to_dynamic_array(arr, logical_size, actual_size, new_element);
            std::cout << "Динамический массив:";
            print_dynamic_array(arr, logical_size, actual_size);
        }
        else break;
    }
    std::cout << "Спасибо!Ваш массив :"; 
    print_dynamic_array(arr, logical_size, actual_size);
    
    delete[] arr;
    return 0;
}
