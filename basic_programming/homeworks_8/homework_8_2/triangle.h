#pragma once
#include "figure.h"

class Triangle : public Figure {
protected:
    int a_, b_, c_;
    int A_, B_, C_;
    std::string reason1 = "сумма углов не равна 180";
public:
    Triangle();
    Triangle(int a, int b, int c, int A, int B, int C);
    int get_a();
    int get_b();
    int get_c();
    int get_A();
    int get_B();
    int get_C();
    std::string whatString(std::string reason) override;
    void printInfo() override;
};