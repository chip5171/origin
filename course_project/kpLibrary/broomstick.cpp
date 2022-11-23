//broomstick.cpp
#include "broomstick.h"

Broomstick::Broomstick() {
    name_ = "Метла";
}
Broomstick::Broomstick(int s) {
    name_ = "Метла";
    speed_ = 20;
    if (s >= 1000) distanceReduction_ = (1 - ratio(s) / 100);
    else distanceReduction_ = 1;
}

double Broomstick::ratio(int s) { 
    return s / 1000;
}
