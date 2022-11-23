//ground_transport.h
#pragma once
#ifdef KPLIBRARY_EXPORTS
#define KPLIBRARY_API __declspec(dllexport)
#else
#define KPLIBRARY_API __declspec(dllimport)
#endif

#include "transport.h"

class GroundTransport : public Transport {
protected:
    int movementTime_;
    int restTime_;
public:
    KPLIBRARY_API GroundTransport();
    KPLIBRARY_API GroundTransport(int s);

    KPLIBRARY_API int getMovementTime();
    KPLIBRARY_API int getRestTime(int s);

    KPLIBRARY_API int getStopNumber(int s);
    KPLIBRARY_API double getTotalTime(int s) override;
};
