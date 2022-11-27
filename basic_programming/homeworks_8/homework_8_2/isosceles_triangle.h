#pragma once
#include "triangle.h"

class IsoscelesTriangle : public Triangle {
protected:
    std::string reason3 = "стороны а и с не равны";
    std::string reason4 = "углы А и С не равны";

public:
    IsoscelesTriangle();
    IsoscelesTriangle(int a, int b, int c, int A, int B, int C);
};
