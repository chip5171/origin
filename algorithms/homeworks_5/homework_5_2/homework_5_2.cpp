// homework_5_2.cpp : Задача 2. «Путешествие» по пирамиде
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
    return ilogb(i + 1);
}
bool get_left_index(int& index, int i, int size) {
    index = 2 * i + 1;
    if (index >= size) return false;
}
bool get_right_index(int& index, int i, int size) {
    index = 2 * i + 2;
    if (index >= size) return false;
}
void get_parent_index(int& index, int i) {
    index = (i - 1) / 2;
}
void print_pyramid(int* arr, int size) {
    std::cout << "Пирамида: " << std::endl;
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
}
void print_element(int* arr, int i) {
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
//______________________________________________________________________________________________________

int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "Rus");
    std::string com;
    
    int arr[] = { 1, 3, 6, 5, 9, 8 };
    //int arr[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    //int arr[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

    int size = sizeof(arr) / sizeof(arr[0]);
  
    print_array(arr, size);
    print_pyramid(arr, size);
   
    int i = 0;
    int j = 0;
    
    do {
        std::cout << "Вы находитесь здесь: ";
        print_element(arr, j);
        std::cout << "Введите команду: ";
        std::cin >> com;

        if (com == "up") {
            if (i == 0) {
                std::cout << "Ошибка! Отсутствует родитель" << std::endl;
                j = i;
            }
            else {
                get_parent_index(j, i);
                std::cout << "Ok" << std::endl;
                i = j;
            }
        }
        else if (com == "left") {
            if (get_left_index(j, i, size) == false) {
                std::cout << "Ошибка! Отсутствует левый потомок" << std::endl;
                j = i;
            }
            else {
                std::cout << "Ok" << std::endl;
                i = j;
            }
        }
        else if (com == "right") {
            if (get_right_index(j, i, size) == false) {
                std::cout << "Ошибка! Отсутствует правый потомок" << std::endl;
                j = i;
            }
            else {
                std::cout << "Ok" << std::endl;
                i = j;
            }
        }
        else if (com == "exit") break;
        else std::cout << "Ошибка! Неверная команда" << std::endl;

    } while (com != "exit");
    
    return 0;
}
