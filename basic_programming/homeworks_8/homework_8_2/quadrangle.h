#pragma once
#include "figure.h"

class Quadrangle : public Figure {
protected:
    int a_, b_, c_, d_;
    int A_, B_, C_, D_;
    std::string reason7 = "сумма углов не равна 360";
public:
    Quadrangle();
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
    int get_a();
    int get_b();
    int get_c();
    int get_d();
    int get_A();
    int get_B();
    int get_C();
    int get_D();

    std::string whatString(std::string reason);
    void printInfo();
};

