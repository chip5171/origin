#include <iostream>
#include <sstream>
#include "exception.h"
#include "quadrangle.h"


Quadrangle::Quadrangle() {
    sidesCount = 4;
    name = "Четырехугольник";
    a_ = b_ = c_ = d_ = 0;
    A_ = B_ = C_ = D_ = 0;
}
Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
    a_ = a; b_ = b; c_ = c; d_ = d; A_ = A; B_ = B; C_ = C; D_ = D;
    name = "Четырехугольник";
    std::string what7 = whatString(reason7);
    if (A_ + B_ + C_ + D_ != 360) throw FigureException(what7);
}
int Quadrangle::get_a() { return a_; }
int Quadrangle::get_b() { return b_; }
int Quadrangle::get_c() { return c_; }
int Quadrangle::get_d() { return d_; }
int Quadrangle::get_A() { return A_; }
int Quadrangle::get_B() { return B_; }
int Quadrangle::get_C() { return C_; }
int Quadrangle::get_D() { return D_; }

std::string Quadrangle::whatString(std::string reason) {
    std::ostringstream ostr;
    ostr << getName() << " (стороны " << get_a() << ", " << get_b() << ", " << get_c() << ", " << get_d() << "; "
         << "углы " << get_A() << ", " << get_B() << ", " << get_C() << ", " << get_D()
         << ") не был создан. Причина: " << getReason(reason);
    std::string what = ostr.str();
    return what;
}
void Quadrangle::printInfo() {
    std::cout << getName() << " (стороны " << get_a() << ", " << get_b() << ", " << get_c() << ", " << get_d() << "; "
              << "углы " << get_A() << ", " << get_B() << ", " << get_C() << ", " << get_D()
              << ") создан" << std::endl;
}
