//aux_functions.h
#ifdef KPLIBRARY_EXPORTS
#define KPLIBRARY_API __declspec(dllexport)
#else
#define KPLIBRARY_API __declspec(dllimport)
#endif


//#ifndef aux_functions_h
//#define aux_functions_h

#include "race.h"

KPLIBRARY_API void arraySort(Race* arr, int x);

KPLIBRARY_API void except(std::string name, int n);

//#endif // aux_functions_h