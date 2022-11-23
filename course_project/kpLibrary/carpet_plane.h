//carpet_plane.h
#pragma once
#ifdef KPLIBRARY_EXPORTS
#define KPLIBRARY_API __declspec(dllexport)
#else
#define KPLIBRARY_API __declspec(dllimport)
#endif

#include"air_transport.h"

class CarpetPlane : public AirTransport {
public:
    KPLIBRARY_API CarpetPlane();
    KPLIBRARY_API CarpetPlane(int s);
};
