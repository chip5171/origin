//eagle.h
#pragma once
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "air_transport.h"

class Eagle : public AirTransport {
public:
    LIBRARY_API Eagle();
    LIBRARY_API Eagle(int s);
};
