#pragma once

#include <vector>

#include "component.h"
#include "entity/entity.h"

namespace tumble {

    class System {

        public:

            System();

            System(std::vector<Entity> *ents) : entities(ents) {};
            System(std::vector<Component>);
            System(std::vector<Entity> *ents, std::vector<Component> comps) : 
                entities(ents), components(comps) {};

            void addEntity(Entity* entity);

        private:
            std::vector<Entity> *entities;
            std::vector<Component> components;
    };
};
