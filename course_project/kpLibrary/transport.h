//transport.h
#pragma once
#ifdef KPLIBRARY_EXPORTS
#define KPLIBRARY_API __declspec(dllexport)
#else
#define KPLIBRARY_API __declspec(dllimport)
#endif

#include "pch.h"
#include <sstream>

class Transport {
protected:
    std::string name_;
    double speed_ = 1;
public:
    KPLIBRARY_API Transport();
    KPLIBRARY_API Transport(int s);
    KPLIBRARY_API std::string getName();
    KPLIBRARY_API double getSpeed();

    KPLIBRARY_API virtual double getTotalTime(int s);
};