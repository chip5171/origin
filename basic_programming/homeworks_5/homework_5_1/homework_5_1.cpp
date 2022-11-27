// homework_5_1.cpp : Задача 1. Фигуры. Количество сторон

#include <iostream>
#include <sstream>

class Figure {
protected:
    int sidesCount = 0;
    std::string name = "Фигура";
public:
    int getSidesCount() {
        return sidesCount;
    }
    std::string getName() {
        return name;
    }
};
class Triangle : public Figure {
public:
    Triangle() {
        sidesCount = 3;
        name = "Треугольник";
    }
};
class Quadrangle : public Figure {
public:
    Quadrangle() {
        sidesCount = 4;
        name = "Четырехугольник";
    }
};
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "rus");
    std::cout << "Количество сторон:" << std::endl;
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;
    std::cout << figure.getName() << ": " << figure.getSidesCount() << std::endl;
    std::cout << triangle.getName() << ": " << triangle.getSidesCount() << std::endl;
    std::cout << quadrangle.getName() << ": " << quadrangle.getSidesCount() << std::endl;

    return 0;
}
