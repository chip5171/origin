// homework_4_2 main.cpp : CPPL-5 ������ 2. �������� ������� ���������� � ��������� ��������� �� ����������� ������

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
