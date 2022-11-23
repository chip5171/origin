//centaur.h
#pragma once
#ifdef KPLIBRARY_EXPORTS
#define KPLIBRARY_API __declspec(dllexport)
#else
#define KPLIBRARY_API __declspec(dllimport)
#endif

#include"ground_transport.h"

class Centaur : public GroundTransport {
public:
    KPLIBRARY_API Centaur();
    KPLIBRARY_API Centaur(int s);
};