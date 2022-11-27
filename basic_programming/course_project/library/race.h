//race.h
#pragma once
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "centaur.h"
#include "camel.h"
#include "all_terrain_boots.h"
#include "speed_camel.h"
#include "air_transport.h"
#include "eagle.h"
#include "carpet_plane.h"
#include "broomstick.h"

class Race {
protected:
    std::string name_;
    double totalTime_ = 1;

public:

    LIBRARY_API Race();
    LIBRARY_API Race(int s, int k);

    LIBRARY_API std::string getName();
    LIBRARY_API double getTotalTime(int s);
    LIBRARY_API double totalTime();
};

