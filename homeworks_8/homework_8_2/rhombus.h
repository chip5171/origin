#pragma once
#include "parallelogram.h"

class Rhombus : public Parallelogram {
protected:
    std::string reason11 = "��� ������� �� ����� ����� �����";
public:
    Rhombus();
    Rhombus(int a, int b, int c, int d, int A, int B, int C, int D);
};