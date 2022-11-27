//camel.cpp
#include"camel.h"

Camel::Camel() {
    name_ = "Верблюд";
}
Camel::Camel(int s) {
    name_ = "Верблюд";
    movementTime_ = 30;
    speed_ = 10;
    int sn = getStopNumber(s);
    if (sn == 1) restTime_ = 5;
    else if (sn > 1) restTime_ = (5 + (sn - 1) * 8);
    else restTime_ = 0;
}