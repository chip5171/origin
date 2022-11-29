// homework_3_3.cpp : Задача 3. Сортировка подсчётом
#include <iostream>

void count_sort(int* arr, int size) {

    int* arr_sort = new int[size]();
    int* arr_count = new int[25](); 

    for (int j = 0; j < size; j++) {
        arr_count[arr[j]] = arr_count[arr[j]] + 1;
    }
    for (int i = 1; i <= 24; i++) {
        arr_count[i] = arr_count[i] + arr_count[i - 1];
    }
    for (int j = size - 1; j >= 0; j--) {
        arr_sort[arr_count[arr[j]] - 1] = arr[j];
        arr_count[arr[j]] = arr_count[arr[j]] - 1;
    }
    for (int i = 0; i < size; i++) { arr[i] = arr_sort[i]; }

    delete[](arr_sort);
    delete[](arr_count);
}


void print_sorting_result(int* arr, int size) {
    std::cout << "Исходный массив:";
    for (int i = 0; i < size; ++i) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
    count_sort(arr, size);
    std::cout << "Отсортированный массив:";
    for (int i = 0; i < size; ++i) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl << std::endl;
}
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");

    int arr1[] = { 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int arr2[] = { 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
    int arr3[] = { 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    print_sorting_result(arr1, size1);

    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    print_sorting_result(arr2, size2);

    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    print_sorting_result(arr3, size3);

    return 0;
}
