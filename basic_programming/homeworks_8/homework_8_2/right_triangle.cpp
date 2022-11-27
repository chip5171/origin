#include "exception.h"
#include "right_triangle.h"

RightTriangle::RightTriangle() {
    name = "Прямоугольный треугольник";
    C_ = 90;
}
RightTriangle::RightTriangle(int a, int b, int c, int A, int B, int C) {
    name = "Прямоугольный треугольник";
    a_ = a; b_ = b; c_ = c; A_ = A; B_ = B; C_ = C;
    std::string what1 = whatString(reason1);
    std::string what2 = whatString(reason2);
    if (A_ + B_ + C_ != 180) throw FigureException(what1);
    if (C_ != 90) throw FigureException(what2);
}
