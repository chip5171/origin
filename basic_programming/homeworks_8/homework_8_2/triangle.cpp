#include <iostream>
#include <sstream>
#include "exception.h"
#include "triangle.h"

Triangle::Triangle() {
    sidesCount = 3;
    name = "Треугольник";
    a_ = 0; b_ = 0; c_ = 0;
    A_ = 0; B_ = 0; C_ = 0;

}
Triangle::Triangle(int a, int b, int c, int A, int B, int C) {
    a_ = a; b_ = b; c_ = c; A_ = A; B_ = B; C_ = C;
    sidesCount = getSidesCount();
    name = "Треугольник";
    std::string what = whatString(reason1);
    if (A_ + B_ + C_ != 180) throw FigureException(what);
}
int Triangle::get_a() { return a_; }
int Triangle::get_b() { return b_; }
int Triangle::get_c() { return c_; }
int Triangle::get_A() { return A_; }
int Triangle::get_B() { return B_; }
int Triangle::get_C() { return C_; }

std::string Triangle::whatString(std::string reason) {
    std::ostringstream ostr;
    ostr << getName() << " (стороны " << get_a() << ", " << get_b() << ", " << get_c() << "; "
        << "углы " << get_A() << ", " << get_B() << ", " << get_C()
        << ") не был создан. Причина: " << getReason(reason);
    std::string what = ostr.str();
    return what;
}
void Triangle::printInfo() {
    std::cout << getName() << " (стороны " << get_a() << ", " << get_b() << ", " << get_c() << "; "
              << "углы " << get_A() << ", " << get_B() << ", " << get_C()
              << ") создан" << std::endl;
}
