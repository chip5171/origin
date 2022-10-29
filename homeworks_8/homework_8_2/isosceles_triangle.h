#pragma once
#include "triangle.h"

class IsoscelesTriangle : public Triangle {
protected:
    std::string reason3 = "������� � � � �� �����";
    std::string reason4 = "���� � � � �� �����";

public:
    IsoscelesTriangle();
    IsoscelesTriangle(int a, int b, int c, int A, int B, int C);
};
