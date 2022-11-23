//broomstick.h
#pragma once
#ifdef KPLIBRARY_EXPORTS
#define KPLIBRARY_API __declspec(dllexport)
#else
#define KPLIBRARY_API __declspec(dllimport)
#endif

#include "air_transport.h"

class Broomstick : public AirTransport {
public:
    KPLIBRARY_API Broomstick();
    KPLIBRARY_API Broomstick(int s);
    
    KPLIBRARY_API double ratio(int s);
};