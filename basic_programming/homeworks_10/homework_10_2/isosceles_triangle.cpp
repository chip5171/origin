#include "isosceles_triangle.h"

IsoscelesTriangle::IsoscelesTriangle() {
    name = "Равнобедренный треугольник";
}
IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B) {
    a_ = c_ = a;
    b_ = b;
    A_ = C_ = A;
    B_ = B;
    name = "Равнобедренный треугольник";
}
