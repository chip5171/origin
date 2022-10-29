#pragma once
#include "triangle.h"

class RightTriangle : public Triangle {
protected:
    //std::string reason1 = "сумма углов не равна 180";
    std::string reason2 = "угол С не равен 90";
public:
    RightTriangle();
    RightTriangle(int a, int b, int c, int A, int B, int C);
};