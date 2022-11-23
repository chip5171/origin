//speed_camel.cpp
#include "speed_camel.h"

SpeedCamel::SpeedCamel() {
    name_ = "Верблюд-быстроход";
}
SpeedCamel::SpeedCamel(int s) {
    name_ = "Верблюд-быстроход";
    movementTime_ = 10;
    speed_ = 40;
    int sn = getStopNumber(s);
    if (sn == 1) restTime_ = 5;
    else if (sn == 2) restTime_ = 11.5;
    else if (sn > 2) restTime_ = (11.5 + (sn - 2) * 8);
    else restTime_ = 0;
}