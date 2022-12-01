// homework_4_1.cpp : Задача 1. Вывод изменяемого динамического массива
#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    std::cout << "Динамический массив:";
    for (int i = 0; i < logical_size; i++) {
        std::cout << " " << arr[i];
    }
    for (int i = logical_size; i < actual_size; i++) {
        std::cout << " _";
    }
    std::cout << std::endl;
}


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");

    int logical_size, actual_size;

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
    print_dynamic_array(arr, logical_size, actual_size);
        
    delete[] arr;
    return 0;
}
