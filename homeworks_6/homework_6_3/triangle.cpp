#include <iostream>
#include "triangle.h"

Triangle::Triangle() {
    sidesCount = 3;
    name = "�����������";
    a_ = 0; b_ = 0; c_ = 0;
    A_ = 0; B_ = 0; C_ = 0;
}
Triangle::Triangle(int a, int b, int c, int A, int B, int C) {
    a_ = a; b_ = b; c_ = c; A_ = A; B_ = B; C_ = C;
    sidesCount = 3;
    name = "�����������";
}
int Triangle::get_a() { return a_; }
int Triangle::get_b() { return b_; }
int Triangle::get_c() { return c_; }
int Triangle::get_A() { return A_; }
int Triangle::get_B() { return B_; }
int Triangle::get_C() { return C_; }

void Triangle::printInfo() {
    std::cout << getName() << ": " << std::endl;
    std::cout << "�������: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << std::endl;
    std::cout << "����: �=" << get_A() << " B=" << get_B() << " C=" << get_C() << std::endl;
    std::cout << std::endl;
}
