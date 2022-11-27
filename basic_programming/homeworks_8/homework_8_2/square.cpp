#include <iostream>
#include <sstream>
#include "exception.h"
#include "square.h"

Square::Square() {
    name = "�������";
    a_ = b_ = c_ = d_ = 0;
    A_ = B_ = C_ = D_ = 90;
}
Square::Square(int a, int b, int c, int d, int A, int B, int C, int D) {
    name = "�������";
    a_ = a; b_ = b; c_ = c; d_ = d; A_ = A; B_ = B; C_ = C; D_ = D;
    std::string what7 = whatString(reason7);
    std::string what10 = whatString(reason10);
    std::string what11 = whatString(reason11);
    if (A_ + B_ + C_ + D_ != 360) throw FigureException(what7);
    if ((A_ != C_) && (B_ != D_)) throw FigureException(what10);
    if ((a_ != b_) && (b_ != c_) && (c_ != d_)) throw FigureException(what11);
}
