#pragma once
#include "triangle.h"

class EquilateralTriangle : public Triangle {
    std::string reason5 = "��� ������� �� ����� ����� �����";
    std::string reason6 = "��� ���� �� ����� 60";
public:
    EquilateralTriangle();
    EquilateralTriangle(int a, int b, int c, int A, int B, int C);
};

