//camel.h
#pragma once
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include"ground_transport.h"

class Camel : public GroundTransport {
public:
    LIBRARY_API Camel();
    LIBRARY_API Camel(int s);
};
