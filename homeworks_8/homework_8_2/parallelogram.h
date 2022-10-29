#pragma once
#include "quadrangle.h"

class Parallelogram : public Quadrangle {
protected:
    std::string reason8 = "������� a,c � b,d ������� �� �����";
    std::string reason9 = "���� A,C � B,D ������� �� �����";

public:
    Parallelogram();
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D);
};