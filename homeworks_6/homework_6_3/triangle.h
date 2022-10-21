#pragma once
#include "figure.h"

class Triangle : public Figure {
protected:
    int a_, b_, c_;
    int A_, B_, C_;
public:
    Triangle();
    Triangle(int a, int b, int c, int A, int B, int C);
    int get_a();
    int get_b();
    int get_c();
    int get_A();
    int get_B();
    int get_C();
    void printInfo() override;
};