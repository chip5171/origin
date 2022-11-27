#pragma once
#include <iostream>

namespace Greeting {
    class Greeter {
    protected:
        std::string name_;
    public:
        void setName(std::string name);
        std::string getName();
        void greet(std::string name);
    };
}