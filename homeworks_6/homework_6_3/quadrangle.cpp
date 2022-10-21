#include <iostream>
#include "quadrangle.h"

Quadrangle::Quadrangle() {
    sidesCount = 4;
    name = "Четырехугольник";
    a_ = 0; b_ = 0; c_ = 0; d_ = 0;
    A_ = 0; B_ = 0; C_ = 0; D_ = 0;
}
Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
    a_ = a; b_ = b; c_ = c; d_ = d; A_ = A; B_ = B; C_ = C; D_ = D;
    sidesCount = 4;
    name = "Четырехугольник";
}
int Quadrangle::get_a() { return a_; }
int Quadrangle::get_b() { return b_; }
int Quadrangle::get_c() { return c_; }
int Quadrangle::get_d() { return d_; }
int Quadrangle::get_A() { return A_; }
int Quadrangle::get_B() { return B_; }
int Quadrangle::get_C() { return C_; }
int Quadrangle::get_D() { return D_; }
void Quadrangle::printInfo() {
    std::cout << getName() << ": " << std::endl;
    std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl;
    std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl;
    std::cout << std::endl;
}
