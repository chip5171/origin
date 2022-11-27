#include "rectangle.h"

Rectangle::Rectangle() {
    name = "Прямоугольник";
    a_ = c_ = 0;
    b_ = d_ = 0;
    A_ = B_ = C_ = D_ = 90;
}
Rectangle::Rectangle(int a, int b) {
    name = "Прямоугольник";
    a_ = c_ = a;
    b_ = d_ = b;
    A_ = B_ = C_ = D_ = 90;
}
