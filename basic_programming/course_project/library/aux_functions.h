//aux_functions.h
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif


//#ifndef aux_functions_h
//#define aux_functions_h

#include "race.h"

LIBRARY_API void arraySort(Race* arr, int x);

LIBRARY_API void except(std::string name, int n);

//#endif // aux_functions_h
