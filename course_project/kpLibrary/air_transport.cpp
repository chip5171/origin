//air_transport.cpp
#include "air_transport.h"

AirTransport::AirTransport() {
    name_ = "��������� ���������";
}
AirTransport::AirTransport(int s) {
    name_ = "��������� ���������";
    double speed_ = 1;
    distanceReduction_ = 1;
}

double AirTransport::getDistanceReduction() { 
    return distanceReduction_; 
}
double AirTransport::getTotalTime(int s) {
    return ((s * distanceReduction_) / speed_);
}
