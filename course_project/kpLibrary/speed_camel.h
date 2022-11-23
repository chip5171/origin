//speed_camel.h
#pragma once
#ifdef KPLIBRARY_EXPORTS
#define KPLIBRARY_API __declspec(dllexport)
#else
#define KPLIBRARY_API __declspec(dllimport)
#endif

#include "camel.h"

class SpeedCamel : public Camel {
public:
    KPLIBRARY_API SpeedCamel();
    KPLIBRARY_API SpeedCamel(int s);
};