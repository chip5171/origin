#include "right_triangle.h"

RightTriangle::RightTriangle() {
	name = "Прямоугольный треугольник";
	C_ = 90;
}
RightTriangle::RightTriangle(int a, int b, int c, int A, int B) {
    name = "Прямоугольный треугольник";
    a_ = a; b_ = b; c_ = c; A_ = A; B_ = B;
    C_ = 90;
}
	