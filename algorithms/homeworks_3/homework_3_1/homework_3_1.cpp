// homework_3_1.cpp : Задача 1. Сортировка слиянием
#include <iostream>

void merge_sort(int* arr, int size) {
    if (size == 1) { return; }

    int left_size = size / 2;
    int right_size = size - left_size;

    merge_sort(&arr[0], left_size);
    merge_sort(&arr[left_size], right_size);
    
    int i = 0, j = left_size;
    int* temp = new int[size];

        for (int k = 0; k < size; k++) {
            if (j > size-1 || i <= left_size-1 && arr[i] < arr[j]) {
                temp[k] = arr[i];
                i++;
            }
            else {
                temp[k] = arr[j];
                j++;
            }
        }
        for (int k = 0, i = 0; k < size; k++, i++) {
            arr[i] = temp[k];
        }
        delete[] temp;
    }

void print_sorting_result(int* arr, int size) {
    std::cout << "Исходный массив:";
    for (int i = 0; i < size; ++i) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
    merge_sort(arr, size);
    std::cout << "Отсортированный массив:";
    for (int i = 0; i < size; ++i) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl << std::endl;
}
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");

    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    print_sorting_result(arr1, size1);
    
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    print_sorting_result(arr2, size2);

    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    print_sorting_result(arr3, size3);

    return 0;
}

