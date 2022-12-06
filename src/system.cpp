#include "system.h"
#include <vector>
#include <iostream>

namespace tumble {

    System::System() {
        std::cout << "system initialized" << std::endl;
    };

    // System::System(std::vector<Entity> entities) {
    //     this->entities = entities;
    // };

    System::System(std::vector<Component> components) {
        this->components = components;
    };

    // System::System(std::vector<Entity> *entities, std::vector<Component> components) {
    //     this->entities = entities;
    //     this->components = components;
    // };
}
