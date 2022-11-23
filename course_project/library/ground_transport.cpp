//ground_transport.cpp
#include"ground_transport.h"

GroundTransport::GroundTransport() {
    name_ = "Наземный транспорт";
}
GroundTransport::GroundTransport(int s) {
    name_ = "Наземный транспорт";
    speed_ = 1;
    movementTime_ = 1;
    restTime_ = 1;
}

int GroundTransport::getMovementTime() {
    return movementTime_;
}
double GroundTransport::getRestTime(int s) {
    return restTime_;
}
int GroundTransport::getStopNumber(int s) {
    int stopNumber;
    int baseTime = s / speed_;
    if (baseTime % movementTime_ != 0) stopNumber = baseTime / movementTime_;
    else stopNumber = baseTime / movementTime_ - 1;
    return stopNumber;
}
double GroundTransport::getTotalTime(int s) {
    double baseTime = s / speed_;
    return (baseTime + restTime_);
}



