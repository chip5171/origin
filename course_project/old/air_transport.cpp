//air_transport.cpp
#include "air_transport.h"

AirTransport::AirTransport() {
    name_ = "Воздушный транспорт";
}
AirTransport::AirTransport(int s) {
    name_ = "Воздушный транспорт";
    double speed_ = 1;
    distanceReduction_ = 1;
}

double AirTransport::getDistanceReduction() { 
    return distanceReduction_; 
}
double AirTransport::getTotalTime(int s) {
    return ((s * distanceReduction_) / speed_);
}
