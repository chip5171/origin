// homework_5_1.cpp : Задача 1. Вывод пирамиды на массиве

#include <iostream>
#include <cmath>

void print_array(int* arr, int size) {
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
}
int get_level(int i) {
   return ilogb(i+1);
}
void print_pyramid(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::string position;
        if (i == 0) {
            std::cout << 0 << " root " << arr[i] << std::endl;
        }
        else {
            if (i % 2 == 0 && i != 0) position = "right";
            if (i % 2 != 0 && i != 0) position = "left";
            std::cout << get_level(i) << " " << position << "(" << arr[(i - 1) / 2] << ")" << " " << arr[i] << std::endl;
        }
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "Rus");

    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    
    print_array(arr1, size1);
    print_pyramid(arr1, size1);

    print_array(arr2, size2);
    print_pyramid(arr2, size2);

    print_array(arr3, size3);
    print_pyramid(arr3, size3);

    return 0;
}
