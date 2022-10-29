#include "exception.h"
#include "isosceles_triangle.h"

IsoscelesTriangle::IsoscelesTriangle() {
    name = "Равнобедренный треугольник";
}
IsoscelesTriangle::IsoscelesTriangle(int a, int b, int c, int A, int B, int C) {
    a_ = a; b_ = b; c_ = c; A_ = A; B_ = B; C_ = C;
    sidesCount = getSidesCount();
    name = "Равнобедренный треугольник";
    std::string what1 = whatString(reason1);
    std::string what3 = whatString(reason3);
    std::string what4 = whatString(reason4);
    if (A_ + B_ + C_ != 180) throw FigureException(what1);
    if (a_ != c_) throw FigureException(what3);
    if (A_ != C_) throw FigureException(what4);
}

