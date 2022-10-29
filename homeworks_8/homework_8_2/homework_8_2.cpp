// homework_8_2.cpp: Задача 2. Исключения в конструкторах

#include <iostream>
#include <sstream>
#include <string>
#include "exception.h"
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

//class Square : public Rectangle {
//protected:
//    std::string reason11 = "все стороны не равны между собой";
//public:
//    Square() {
//        name = "Квадрат";
//        a_ = b_ = c_ = d_ = 0;
//        A_ = B_ = C_ = D_ = 90;
//    }
//    Square(int a, int b, int c, int d, int A, int B, int C, int D) {
//        name = "Квадрат";
//        a_ = a; b_ = b; c_ = c; d_ = d; A_ = A; B_ = B; C_ = C; D_ = D;
//        std::string what7 = whatString(reason7);
//        std::string what10 = whatString(reason10);
//        std::string what11 = whatString(reason11);
//        if (A_ + B_ + C_ + D_ != 360) throw FigureException(what7);
//        if ((A_ != C_) && (B_ != D_)) throw FigureException(what10);
//        if ((a_ != b_) && (b_ != c_) && (c_ != d_)) throw FigureException(what11);
//    }
//};


int main(int argc, char** argv) {
    setlocale(LC_ALL, "rus");
    Figure figure(0);
    Figure* f;

    try {
        f = &figure; f->printInfo();
    }
    catch (const FigureException& ex) { std::cout << ex.what() << std::endl; }
    
    //_________________________Треугольники__________________________________//
    try {
        Triangle triangle(10, 20, 30, 50, 70, 70);
        f = &triangle; f->printInfo();
    }
    catch (const FigureException& ex) { std::cout << ex.what() << std::endl; }
    try {
        RightTriangle rTriangle(10, 20, 30, 50, 60, 70);
        f = &rTriangle; f->printInfo();
    }
    catch (const FigureException& ex) { std::cout << ex.what() << std::endl; }
    try {
        IsoscelesTriangle iTriangle(10, 20, 10, 80, 40, 60);
        f = &iTriangle; f->printInfo();
    }
    catch (const FigureException& ex) { std::cout << ex.what() << std::endl; }
    try {
        EquilateralTriangle eTriangle(10, 20, 10, 30, 60, 90);
        f = &eTriangle; f->printInfo();
    }
    catch (const FigureException& ex) { std::cout << ex.what() << std::endl; }

    //_________________________Четырехугольники__________________________________//

    try {
        Quadrangle quadrangle(20, 90, 20, 90, 30, 90, 70, 90);
        f = &quadrangle; f->printInfo();
    }
    catch (const FigureException& ex) { std::cout << ex.what() << std::endl; }
    try {
        Parallelogram parallelogram (90, 90, 90, 90, 20, 90, 20, 90);
        f = &parallelogram; f->printInfo();
    }
    catch (const FigureException& ex) { std::cout << ex.what() << std::endl; }
    try {
        Rectangle rectangle(20, 30, 20, 30, 90, 90, 90, 90);
        f = &rectangle; f->printInfo();
    }
    catch (const FigureException& ex) { std::cout << ex.what() << std::endl; }
    try {
        Rhombus rhombus(30, 30, 30, 30, 80, 100, 90, 90);
        f = &rhombus; f->printInfo();
    }
    catch (const FigureException& ex) { std::cout << ex.what() << std::endl; }
    try {
        Square square(30, 30, 30, 30, 90, 90, 90, 90);
        f = &square; f->printInfo();
    }
    catch (const FigureException& ex) { std::cout << ex.what() << std::endl; }

    return 0;
}

