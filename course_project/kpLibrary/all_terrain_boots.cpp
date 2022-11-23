//all_terrain_boots.cpp
#include "all_terrain_boots.h"

AllTerrainBoots::AllTerrainBoots() {
    name_ = "Ботинки-вездеходы";
}
AllTerrainBoots::AllTerrainBoots(int s) {
    name_ = "Ботинки-вездеходы";
    movementTime_ = 60;
    speed_ = 6;
    int sn = getStopNumber(s);
    if (sn == 1) restTime_ = 10;
    else if (sn > 1) restTime_ = (10 + (sn - 1) * 5);
    else restTime_ = 0;
}
