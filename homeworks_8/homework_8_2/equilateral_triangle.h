#pragma once
#include "triangle.h"

class EquilateralTriangle : public Triangle {
    std::string reason5 = "все стороны не равны между собой";
    std::string reason6 = "все углы не равны 60";
public:
    EquilateralTriangle();
    EquilateralTriangle(int a, int b, int c, int A, int B, int C);
};

