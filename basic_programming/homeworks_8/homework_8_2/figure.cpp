#include <iostream>
#include <sstream>
#include "exception.h"
#include "figure.h"

int Figure::getSidesCount() { 
    return sidesCount; 
}
std::string Figure::getName() { 
    return name; 
}
std::string Figure::getReason(std::string reason) {
    return reason;
}
Figure::Figure() { 
    sidesCount = 0; 
}
Figure::Figure(int s) {
    sidesCount = s;
    name = "Фигура";
    std::string reason1 = "количество сторон не равно 0";
    std::string what = whatString(reason1);
    if (sidesCount != 0) throw FigureException(what);
}
std::string Figure::whatString(std::string reason) {
    std::ostringstream ostr;
    ostr << getName() << " (количество сторон " << getSidesCount() << ") не была создана. Причина: " << reason << std::endl;
    std::string what = ostr.str();
    return what;
}
void Figure::printInfo() {
    std::cout << getName() << " (количество сторон " << getSidesCount() << ") " << "создана" << std::endl;
}