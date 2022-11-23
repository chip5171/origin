//ground_transport.h
#pragma once
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "transport.h"

class GroundTransport : public Transport {
protected:
    int movementTime_;
    double restTime_;
public:
    LIBRARY_API GroundTransport();
    LIBRARY_API GroundTransport(int s);

    LIBRARY_API int getMovementTime();
    LIBRARY_API double getRestTime(int s);

    LIBRARY_API int getStopNumber(int s);
    LIBRARY_API double getTotalTime(int s) override;
};

