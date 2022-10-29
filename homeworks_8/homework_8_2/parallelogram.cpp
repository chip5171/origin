#include <iostream>
#include <sstream>
#include "exception.h"
#include "parallelogram.h"


Parallelogram::Parallelogram() {
    name = "ֿאנאככוכמדנאלל";
    a_ = b_ = c_ = d_ = 0;
    A_ = C_ = B_ = D_ = 0;
}
Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) {
    name = "ֿאנאככוכמדנאלל";
    a_ = a; b_ = b; c_ = c; d_ = d; A_ = A; B_ = B; C_ = C; D_ = D;
    std::string what7 = whatString(reason7);
    std::string what9 = whatString(reason9);
    std::string what8 = whatString(reason8);
    if (A_ + B_ + C_ + D_ != 360) throw FigureException(what7);
    if ((a_ != c_) && (b_ != d_)) throw FigureException(what8);
    if ((A_ != C_) && (B_ != D_)) throw FigureException(what9);
}
