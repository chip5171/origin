//transport.h
#pragma once
#include <sstream>

class Transport {
protected:
    std::string name_;
    double speed_ = 1;
public:
    Transport();
    Transport(int s);
    std::string getName();
    double getSpeed();

    virtual double getTotalTime(int s);
};