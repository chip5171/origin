//speed_camel.h
#pragma once
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

#include "camel.h"

class SpeedCamel : public Camel {
public:
    LIBRARY_API SpeedCamel();
    LIBRARY_API SpeedCamel(int s);
};
