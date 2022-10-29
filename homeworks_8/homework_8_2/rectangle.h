#pragma once
#include "parallelogram.h"

class Rectangle : public Parallelogram {
protected:
    std::string reason10 = "все углы не равны 90";
public:
    Rectangle();
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D);
};