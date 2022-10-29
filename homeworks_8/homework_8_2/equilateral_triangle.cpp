#include "exception.h"
#include "equilateral_triangle.h"

EquilateralTriangle::EquilateralTriangle() {
    name = "Равносторонний треугольник";
}
EquilateralTriangle::EquilateralTriangle(int a, int b, int c, int A, int B, int C) {
    a_ = a; b_ = b; c_ = c; A_ = A; B_ = B; C_ = C;
    sidesCount = getSidesCount();
    name = "Равносторонний треугольник";
    std::string what1 = whatString(reason1);
    std::string what5 = whatString(reason5);
    std::string what6 = whatString(reason6);
    if (A_ + B_ + C_ != 180) throw FigureException(what1);
    if (a_ != b_ && b_ != c_) throw FigureException(what5);
    if ((A_ != B_ != C_) && (A_!= 60)) throw FigureException(what6);
    name = "Равносторонний треугольник";
}
