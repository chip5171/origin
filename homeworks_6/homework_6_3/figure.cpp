//figure.cpp
#include <iostream>
#include "figure.h"

int Figure::getSidesCount() {
    return sidesCount;
}
std::string Figure::getName() {
    return name;
}
Figure::Figure() {};
Figure::Figure(int s, std::string n) {
    sidesCount = s;
    name = n;
}
void Figure::printInfo() {
    std::cout << getName() << ": " << std::endl;
    std::cout << std::endl;
}
