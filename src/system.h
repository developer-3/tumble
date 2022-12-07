#pragma once

#include <vector>
#include <memory>

#include "component.h"
#include "entity/entity.h"

namespace tumble {

    class System {

        public:

            System();

            System(std::vector<std::shared_ptr<Entity> > ents) : entities(ents) {};
            System(std::vector<Component>);
            System(std::vector<std::shared_ptr<Entity> > ents, std::vector<Component> comps) : 
                entities(ents), components(comps) {};

            void addEntity(std::shared_ptr<Entity> entity);

            std::shared_ptr<Entity> getEntity(int idx) { return entities.at(idx); }

            std::vector<std::shared_ptr<Entity> > getEntities() { return entities; }

            void integrateEntities(float duration);

        private:
            std::vector<std::shared_ptr<Entity> > entities;
            std::vector<Component> components;
    };
};
