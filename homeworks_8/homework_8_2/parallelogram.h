#pragma once
#include "quadrangle.h"

class Parallelogram : public Quadrangle {
protected:
    std::string reason8 = "стороны a,c и b,d попарно не равны";
    std::string reason9 = "углы A,C и B,D попарно не равны";

public:
    Parallelogram();
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D);
};