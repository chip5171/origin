#pragma once
#include <string>

class Figure {
protected:
    int sidesCount;
    std::string name = "������";
    std::string reason1 = "���������� ������ �� ����� 0";
    
public:
    int getSidesCount();
    std::string getName();
    std::string getReason(std::string reason);
    Figure();
    Figure(int s);
    virtual std::string whatString(std::string reason);
    virtual void printInfo();
};