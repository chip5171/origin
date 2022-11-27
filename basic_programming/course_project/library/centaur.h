//centaur.h
#pragma once
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include"ground_transport.h"

class Centaur : public GroundTransport {
public:
    LIBRARY_API Centaur();
    LIBRARY_API Centaur(int s);
};