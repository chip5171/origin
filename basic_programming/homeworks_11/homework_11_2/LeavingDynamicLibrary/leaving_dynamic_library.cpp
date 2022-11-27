#include "leaving_dynamic_library.h"

namespace Leaving {
    void Leaver::setName(std::string name) {
        name_ = name;
    }
    std::string Leaver::getName() {
        return name_;
    }
    void Leaver::leave(std::string name) {
        setName(name);
        std::cout << "До свидания, " << getName() << "!" << std::endl;
    }
}