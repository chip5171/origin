#include <iostream>
#include <sstream>
#include "exception.h"
#include "rhombus.h"

Rhombus::Rhombus() {
    name = "Ромб";
    a_ = b_ = c_ = d_ = 0;
    A_ = C_ = B_ = D_ = 0;
}
Rhombus::Rhombus(int a, int b, int c, int d, int A, int B, int C, int D) {
    name = "Ромб";
    a_ = a; b_ = b; c_ = c; d_ = d; A_ = A; B_ = B; C_ = C; D_ = D;
    std::string what7 = whatString(reason7);
    std::string what9 = whatString(reason9);
    std::string what11 = whatString(reason11);
    if (A_ + B_ + C_ + D_ != 360) throw FigureException(what7);
    if ((A_ != C_) && (B_ != D_)) throw FigureException(what9);
    if ((a_ != b_) && (b_ != c_) && (c_ != d_)) throw FigureException(what11);
}
