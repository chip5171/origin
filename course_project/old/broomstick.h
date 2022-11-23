//broomstick.h
#pragma once
#include "air_transport.h"

class Broomstick : public AirTransport {
public:
    Broomstick();
    Broomstick(int s);
    
    double ratio(int s);
};