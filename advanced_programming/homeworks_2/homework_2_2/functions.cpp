#include "functions.h" 

int* create_array(int size) {
    int* arr = new int[size]();
    return arr;
}
int* writing_array(std::ifstream& file, int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        file >> arr[i];
    }
    return arr;
}
void print_array(int* arr, int size) {
    // Семантическая ошибка - в цикле перебор массива начинается не с 0 элемента
    // на экран будет выведен не весь массив
    for (int i = 1; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void delete_array(int* arr, int size) {
    delete[] arr;
    arr = nullptr;
}