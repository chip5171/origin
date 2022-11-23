//air_transport.cpp
#pragma once
#include "transport.h"

class AirTransport : public Transport {
protected:
    double distanceReduction_;
public:
    AirTransport();
    AirTransport(int s);

double getDistanceReduction();
    
double getTotalTime(int s) override;
};