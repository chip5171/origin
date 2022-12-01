// homework_4_3.cpp : Задача 3*. Удаление первого элемента из изменяемого динамического массива
#include <iostream>
#include <Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < logical_size; i++) {
        std::cout << " " << arr[i];
    }
    for (int i = logical_size; i < actual_size; ++i) {
        std::cout << " _";
    }
    std::cout << std::endl;
}

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size) {

    if ((logical_size - 1) > (actual_size / 3)) {
        for (int i = 0; i < logical_size; i++) {
            arr[i] = arr[i + 1];
        }
        logical_size--;
        return arr;
    }
    if ((logical_size - 1) <= (actual_size / 3)) {
        actual_size /= 3;
        logical_size--;
        int* new_arr = new int[actual_size]();
        for (int i = 0; i < actual_size; i++) {
            new_arr[i] = arr[i + 1];
        }
        delete[] arr;
        arr = new_arr;
        return arr;
    }
    if (actual_size = 0) {
        arr[0] = 0;
        std::cout << "Невозможно удалить первый элемент, так как массив пустой.До свидания!" << std::endl;
        return 0;
    }
}

int main(int argc, char** argv)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int logical_size, actual_size;
    std::string answer;

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
        std::cout << "Удалить первый элемент? ";
        std::cin >> answer;
        if (logical_size == 0) {
            std::cout << "Невозможно удалить первый элемент, так как массив пустой.До свидания!" << std::endl;
            return 0;
        }
        if (answer == "да") {
            if (logical_size != 0) {
                arr = remove_dynamic_array_head(arr, logical_size, actual_size);
                std::cout << "Динамический массив:";
                print_dynamic_array(arr, logical_size, actual_size);
            }
        }
        else if (answer == "нет") {
            std::cout << "Спасибо! Ваш динамический массив :";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
        else {
            std::cout << "Не верный ответ! Выберите да/нет." << std::endl;
            continue;
        }
    }

    delete[] arr;
    return 0;
}
