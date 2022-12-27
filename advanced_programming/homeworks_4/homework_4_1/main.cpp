// homework_4_1 main.cpp : CPPL-5 Задача 1. Проверка базовых функций двусвязного списка

#include <iostream>
#include "list_node.h"
#include "list.h"

int main()
{
    List list;
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);
    list.PushBack(5);

    std::cout << "Firs element: " << list.PopFront() << std::endl;
    std::cout << "Last element: " << list.PopBack() << std::endl;

    return 0;
}
