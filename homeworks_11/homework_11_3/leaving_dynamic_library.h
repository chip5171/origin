// leaving_dynamic_library.h
#pragma once
#include <iostream>

namespace Leaving {
	class Leaver {
    protected:
        std::string name_;
	public:
        void setName(std::string name);
        std::string getName();
        void leave(std::string name);
    };
}