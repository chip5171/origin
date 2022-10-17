// homework_5_3.cpp : Задача 3. Фигуры. Методы

#include <iostream>
#include <sstream>

//________________ Базовый класс фигуры________________________
class Figure {
protected:
    int sidesCount;
    std::string name = "Фигура";
public:
    int getSidesCount() {
        return sidesCount;
    }
    std::string getName() {
        return name;
    }
    Figure() {
        sidesCount = 0;
    };
    Figure(int s) {
        sidesCount = s;
        name = "Фигура";
    }
    virtual bool check() {
        if (sidesCount == 0)
            return(true);
        else
            return(false);
    }
    virtual void printInfo() {
        std::cout << std::endl;
        std::cout << getName() << ": " << std::endl;
        if (!check()) {
            std::cout << "Неправильная" << std::endl;
        }
        else {
            std::cout << "Правильная" << std::endl;
        }
        std::cout << "Количество сторон: " << getSidesCount() << std::endl;
    }
};
//_______________________ Треугольники_________________________
class Triangle : public Figure {
protected:
    int a_, b_, c_;
    int A_, B_, C_;
public:
    Triangle() {
        sidesCount = 3;
        name = "Треугольник";
        a_ = 0; b_ = 0; c_ = 0;
        A_ = 0; B_ = 0; C_ = 0;
    }
    Triangle(int a, int b, int c, int A, int B, int C) {
        a_ = a; b_ = b; c_ = c; A_ = A; B_ = B; C_ = C;
        sidesCount = 3;
        name = "Треугольник";
    }
    int get_a() { return a_; }
    int get_b() { return b_; }
    int get_c() { return c_; }
    int get_A() { return A_; }
    int get_B() { return B_; }
    int get_C() { return C_; }
    bool check() override {
        if (sidesCount == 3 && (A_ + B_ + C_ == 180))
            return(true);
        else
            return(false);
    }
    void printInfo() override {
        Figure::printInfo();
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << std::endl;
        std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << std::endl;
    }
};
class RightTriangle : public Triangle {
public:
    RightTriangle() {
        name = "Прямоугольный треугольник";
        C_ = 90;
    }
    RightTriangle(int a, int b, int c, int A, int B) {
        name = "Прямоугольный треугольник";
        a_ = a; b_ = b; c_ = c; A_ = A; B_ = B;
        C_ = 90;
    }
    virtual bool check() override {
        if ((Triangle::check() == true) && (C_ = 90))
            return(true);
        else
            return(false);
    }
};
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle() {
        name = "Равнобедренный треугольник";
    }
    IsoscelesTriangle(int a, int b, int A, int B) {
        a_ = c_ = a;
        b_ = b;
        A_ = C_ = A;
        B_ = B;
        name = "Равнобедренный треугольник";
    }
    virtual bool check() override {
        if ((Triangle::check() == true) && (a_ = c_) && (A_ = C_))
            return(true);
        else
            return(false);
    }
};
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle() {
        name = "Равносторонний треугольник";
    }
    EquilateralTriangle(int a) {
        a_ = c_ = b_ = a;
        A_ = C_ = B_ = 60;
        name = "Равносторонний треугольник";
    }
    virtual bool check() override {
        if ((a_ = b_ = c_) && (A_ = B_ = C_ = 60))
            return(true);
        else
            return(false);
    }
};
//_________________Четырехугольники____________________________
class Quadrangle : public Figure {
protected:
    int a_, b_, c_, d_;
    int A_, B_, C_, D_;
public:
    Quadrangle() {
        sidesCount = 4;
        name = "Четырехугольник";
        a_ = 0; b_ = 0; c_ = 0; d_ = 0;
        A_ = 0; B_ = 0; C_ = 0; D_ = 0;
    }
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
        a_ = a; b_ = b; c_ = c; d_ = d; A_ = A; B_ = B; C_ = C; D_ = D;
        sidesCount = 4;
        name = "Четырехугольник";
    }
    int get_a() { return a_; }
    int get_b() { return b_; }
    int get_c() { return c_; }
    int get_d() { return d_; }
    int get_A() { return A_; }
    int get_B() { return B_; }
    int get_C() { return C_; }
    int get_D() { return D_; }

    bool check() override {
        if (sidesCount == 4 && (A_ + B_ + C_ + D_ == 360))
            return(true);
        else
            return(false);
    }
    void printInfo() override {
        Figure::printInfo();
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << std::endl;
        std::cout << "Углы: А=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << std::endl;
    }
};
class Parallelogram : public Quadrangle {
public:
    Parallelogram() {
        name = "Параллелограмм";
        a_ = c_ = 0;
        b_ = d_ = 0;
        A_ = C_ = 0;
        B_ = D_ = 0;
    }
    Parallelogram(int a, int b, int A, int B) {
        name = "Параллелограмм";
        a_ = c_ = a;
        b_ = d_ = b;
        A_ = C_ = A;
        B_ = D_ = B;
    }
    bool check() override {
        if ((Quadrangle::check() == true) && ((a_ = c_) && (b_ = d_)) && ((A_ = C_) && (B_ = D_)))
            return(true);
        else
            return(false);
    }
};
class Rectangle : public Parallelogram {
public:
    Rectangle() {
        name = "Прямоугольник";
        a_ = c_ = 0;
        b_ = d_ = 0;
        A_ = B_ = C_ = D_ = 90;
    }
    Rectangle(int a, int b) {
        name = "Прямоугольник";
        a_ = c_ = a;
        b_ = d_ = b;
        A_ = B_ = C_ = D_ = 90;
    }
    bool check() override {
        if ((Quadrangle::check() == true) && (A_ = B_ = C_ = D_ = 90))
            return(true);
        else
            return(false);
    }
};
class Rhombus : public Parallelogram {
public:
    Rhombus() {
        name = "Ромб";
        a_ = b_ = c_ = d_ = 0;
        A_ = C_ = 0;
        B_ = D_ = 0;
    }
    Rhombus(int a, int A, int B) {
        name = "Ромб";
        a_ = b_ = c_ = d_ = a;
        A_ = C_ = A;
        B_ = D_ = B;
    }
    bool check() override {
        if ((Quadrangle::check() == true) && (a_ = b_ = c_ = d_) && ((A_ = C_) && (B_ = D_)))
            return(true);
        else
            return(false);
    }
};
class Square : public Rectangle {
public:
    Square() {
        name = "Квадрат";
        a_ = b_ = c_ = d_ = 0;
        A_ = B_ = C_ = D_ = 90;
    }
    Square(int a) {
        name = "Квадрат";
        a_ = b_ = c_ = d_ = a;
        A_ = B_ = C_ = D_ = 90;
    }
    bool check() override {
        if ((Quadrangle::check() == true) && (a_ = b_ = c_ = d_) && (A_ = C_ = B_ = D_ = 90))
            return(true);
        else
            return(false);
    }
};

//___________________________________________________________________

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");
    Figure figure(0);
    Figure* f;

    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rTriangle(10, 20, 30, 50, 60);
    IsoscelesTriangle iTriangle(10, 20, 50, 60);
    EquilateralTriangle eTriangle(30);
    f = &figure; f->printInfo();
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
