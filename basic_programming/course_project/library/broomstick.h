//broomstick.h
#pragma once
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "air_transport.h"

class Broomstick : public AirTransport {
public:
    LIBRARY_API Broomstick();
    LIBRARY_API Broomstick(int s);

    LIBRARY_API double ratio(int s);
};