#pragma once
#include "rectangle.h"

class Square : public Rectangle {
protected:
    std::string reason11 = "��� ������� �� ����� ����� �����";
public:
    Square();
    Square(int a, int b, int c, int d, int A, int B, int C, int D);
};
