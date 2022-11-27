//eagle.cpp
#include "eagle.h"

Eagle::Eagle() {
    name_ = "Орел";
}
Eagle::Eagle(int s) {
    name_ = "Орел";
    speed_ = 8;
    distanceReduction_ = 0.94;
}