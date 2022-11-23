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
int GroundTransport::getRestTime(int s) {
    return restTime_;
}
int GroundTransport::getStopNumber(int s) {
    return (s / speed_ / movementTime_);
}
double GroundTransport::getTotalTime(int s) {
    return (s / speed_ + restTime_);
}



