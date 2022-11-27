#include <iostream>
#include <sstream>
#include "exception.h"
#include "rectangle.h"

Rectangle::Rectangle() {
    name = "Прямоугольник";
    a_ = c_ = 0;
    b_ = d_ = 0;
    A_ = B_ = C_ = D_ = 90;
}
Rectangle::Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) {
    name = "Прямоугольник";
    a_ = a; b_ = b; c_ = c; d_ = d; A_ = A; B_ = B; C_ = C; D_ = D;
    std::string what7 = whatString(reason7);
    std::string what8 = whatString(reason8);
    std::string what10 = whatString(reason10);
    if (A_ + B_ + C_ + D_ != 360) throw FigureException(what7);
    if ((a_ != c_) && (b_ != d_)) throw FigureException(what8);
    if ((A_ != B_ && B_ != C_ && C_ != D_ && A_ != 90)) throw FigureException(what10);
}
