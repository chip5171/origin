//air_transport.cpp
#pragma once
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "transport.h"

class AirTransport : public Transport {
protected:
    double distanceReduction_;
public:
    LIBRARY_API AirTransport();
    LIBRARY_API AirTransport(int s);

    LIBRARY_API double getDistanceReduction();

    LIBRARY_API double getTotalTime(int s) override;
};
