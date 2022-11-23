//camel.h
#pragma once
#ifdef KPLIBRARY_EXPORTS
#define KPLIBRARY_API __declspec(dllexport)
#else
#define KPLIBRARY_API __declspec(dllimport)
#endif

#include"ground_transport.h"

class Camel : public GroundTransport {
public:
    KPLIBRARY_API Camel();
    KPLIBRARY_API Camel(int s);
};
