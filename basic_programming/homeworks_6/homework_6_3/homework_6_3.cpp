// homework_6_3.cpp : Задача 3. Иерархия классов

#include <iostream>
#include <sstream>
#include "figure.h"
#include "triangle.h"
#include "right_triangle.h" 
#include "isosceles_triangle.h"
#include "equilateral_triangle.h"
#include "quadrangle.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "rhombus.h"
#include "square.h"

int main(int argc, char** argv) {
    setlocale(LC_ALL, "rus");
    Figure figure;
    Figure* f;

    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rTriangle(10, 20, 30, 50, 60);
    IsoscelesTriangle iTriangle(10, 20, 50, 60);
    EquilateralTriangle eTriangle(30);

    f = &triangle; f->printInfo();
    f = &rTriangle; f->printInfo();
    f = &iTriangle; f->printInfo();
    f = &eTriangle; f->printInfo();

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rectangle rectangle(10, 20);
    Rhombus rhombus(30, 30, 40);
    Square square(20);

    f = &quadrangle; f->printInfo();
    f = &rectangle; f->printInfo();
    f = &square; f->printInfo();
    f = &parallelogram; f->printInfo();
    f = &rhombus; f->printInfo();

    return 0;
}
