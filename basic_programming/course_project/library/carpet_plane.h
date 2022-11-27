//carpet_plane.h
#pragma once
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include"air_transport.h"

class CarpetPlane : public AirTransport {
public:
    LIBRARY_API CarpetPlane();
    LIBRARY_API CarpetPlane(int s);
};
