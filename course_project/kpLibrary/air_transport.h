//air_transport.cpp
#pragma once
#ifdef KPLIBRARY_EXPORTS
#define KPLIBRARY_API __declspec(dllexport)
#else
#define KPLIBRARY_API __declspec(dllimport)
#endif

#include "transport.h"

class AirTransport : public Transport {
protected:
    double distanceReduction_;
public:
    KPLIBRARY_API AirTransport();
    KPLIBRARY_API AirTransport(int s);

    KPLIBRARY_API double getDistanceReduction();
    
    KPLIBRARY_API double getTotalTime(int s) override;
};