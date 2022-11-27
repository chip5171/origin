#include "greeting_static_library.h"

namespace Greeting {
    void Greeter::setName(std::string name) {
        name_ = name;
    }
    std::string Greeter::getName() {
        return name_;
    }
    void Greeter::greet(std::string name) {
        setName(name);
        std::cout << "Здравствуйте, " << getName() << "!" << std::endl;
    }
}