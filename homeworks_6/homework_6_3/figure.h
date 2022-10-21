#pragma once
#include <sstream>

class Figure {
protected:
    int sidesCount = 0;
    std::string name;
public:
    int getSidesCount();
    std::string getName();
    Figure();
    Figure(int s, std::string n);
    virtual void printInfo();
};