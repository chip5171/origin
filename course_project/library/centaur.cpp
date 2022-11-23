//centaur.cpp
#include "centaur.h"

Centaur::Centaur() {
    name_ = "Кентавр";
}
Centaur::Centaur(int s) {
    name_ = "Кентавр";
    movementTime_ = 8;
    speed_ = 15;
    int sn = getStopNumber(s);
    if (sn >= 1) restTime_ = 2 * sn;
    else restTime_ = 0;
}