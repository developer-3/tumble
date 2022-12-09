#include "system.h"
#include <vector>
#include <iostream>

namespace tumble {

    System::System() {
        std::cout << "system initialized" << std::endl;
    };


    void System::addEntity(std::shared_ptr<Entity> entity)
    {
        this->entities.push_back(entity);
    }


    void System::integrateEntities(real duration)
    {
        for (auto &component : components)
        {
            for (auto &entity : entities)
            {
                //if (!entity->hasFiniteMass()) continue;
                entity->addForce(component->force * entity->getMass());
            }
        }

        for (auto &entity : entities)
        {
            entity->integrate(duration);
        }
    }

    void System::addComponent(std::shared_ptr<Component> component)
    {
        this->components.push_back(component);
    }

}
