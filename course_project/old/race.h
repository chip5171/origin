//race.h
#pragma once
#include "centaur.h"
#include "camel.h"
#include "all_terrain_boots.h"
#include "speed_camel.h"
//#include "air_transport.h"
#include "eagle.h"
#include "carpet_plane.h"
#include "broomstick.h"

class Race {
protected:
    std::string name_;
    double totalTime_ = 1;

public:

    Race();
    Race(int s, int k);

    std::string getName();
    double getTotalTime(int s);
    double totalTime();
};
