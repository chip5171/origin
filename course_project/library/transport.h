//transport.h
#pragma once
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include <sstream>

class Transport {
protected:
    std::string name_;
    double speed_ = 1;
public:
    LIBRARY_API Transport();
    LIBRARY_API Transport(int s);
    LIBRARY_API std::string getName();
    LIBRARY_API double getSpeed();

    LIBRARY_API virtual double getTotalTime(int s);
}; 
