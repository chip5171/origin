//carpet_plane.cpp
#include "carpet_plane.h"

CarpetPlane::CarpetPlane() {
    name_ = "Ковёр-самолёт";
}
CarpetPlane::CarpetPlane(int s) {
    name_ = "Ковёр-самолёт";
    speed_ = 10.00;
    if (s < 1000) distanceReduction_ = 1;
    else if (s >= 1000 && s < 5000) distanceReduction_ = 0.97;
    else if (s >= 5000 && s < 10000) distanceReduction_ = 0.9;
    else if (s >= 10000) distanceReduction_ = 0.95;
}