//eagle.h
#pragma once
#ifdef KPLIBRARY_EXPORTS
#define KPLIBRARY_API __declspec(dllexport)
#else
#define KPLIBRARY_API __declspec(dllimport)
#endif

#include "air_transport.h"

class Eagle : public AirTransport {
public:
    KPLIBRARY_API Eagle();
    KPLIBRARY_API Eagle(int s);
};
