//all_terrain_boots.h
#pragma once
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "camel.h"

class AllTerrainBoots : public Camel {
public:
    LIBRARY_API AllTerrainBoots();
    LIBRARY_API AllTerrainBoots(int s);
};
