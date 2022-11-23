//ground_transport.h
#pragma once
#include "transport.h"

class GroundTransport : public Transport {
protected:
    int movementTime_;
    int restTime_;
public:
    GroundTransport();
    GroundTransport(int s);

    int getMovementTime();
    int getRestTime(int s);

    int getStopNumber(int s);
    double getTotalTime(int s) override;
};
