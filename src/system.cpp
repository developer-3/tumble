#include "system.h"
#include <vector>
#include <iostream>

namespace tumble {

    System::System() {
        std::cout << "system initialized" << std::endl;
    };

    System::System(std::vector<Component> components) {
        this->components = components;
    };


    void System::addEntity(std::shared_ptr<Entity> entity)
    {
        this->entities.push_back(entity);
    }


    void System::integrateEntities(real duration)
    {
        for (auto &entity : entities)
        {
            entity->integrate(duration);
        }
    }

}
