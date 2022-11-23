//race.h
#pragma once
#ifdef KPLIBRARY_EXPORTS
#define KPLIBRARY_API __declspec(dllexport)
#else
#define KPLIBRARY_API __declspec(dllimport)
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

    KPLIBRARY_API Race();
    KPLIBRARY_API Race(int s, int k);

    KPLIBRARY_API std::string getName();
    KPLIBRARY_API double getTotalTime(int s);
    KPLIBRARY_API double totalTime();
};
