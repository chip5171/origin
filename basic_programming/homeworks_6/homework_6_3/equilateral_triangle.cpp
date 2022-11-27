#include "equilateral_triangle.h"

EquilateralTriangle::EquilateralTriangle() {
    name = "Равносторонний треугольник";
}
EquilateralTriangle::EquilateralTriangle(int a) {
    a_ = c_ = b_ = a;
    A_ = C_ = B_ = 60;
    name = "Равносторонний треугольник";
}

