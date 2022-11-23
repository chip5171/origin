//all_terrain_boots.h
#pragma once
#ifdef KPLIBRARY_EXPORTS
#define KPLIBRARY_API __declspec(dllexport)
#else
#define KPLIBRARY_API __declspec(dllimport)
#endif

#include "camel.h"

class AllTerrainBoots : public Camel {
public:
    KPLIBRARY_API AllTerrainBoots();
    KPLIBRARY_API AllTerrainBoots(int s);
};