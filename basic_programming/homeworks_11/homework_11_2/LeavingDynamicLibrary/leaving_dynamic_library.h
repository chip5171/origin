// leaving_dynamic_library.h
#pragma once

#ifdef LEAVINGDYNAMICLIBRARY_EXPORTS
#define LEAVINGDYNAMICLIBRARY_API __declspec(dllexport)
#else
#define LEAVINGDYNAMICLIBRARY_API __declspec(dllimport)
#endif
#include <iostream>

namespace Leaving {
	class Leaver {
    protected:
        std::string name_;
	public:
        LEAVINGDYNAMICLIBRARY_API void setName(std::string name);
        LEAVINGDYNAMICLIBRARY_API std::string getName();
        LEAVINGDYNAMICLIBRARY_API void leave(std::string name);
    };
}