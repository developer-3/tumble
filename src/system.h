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
            System(std::vector<std::shared_ptr<Component> > comps) : 
                components(comps) {};
            System(std::vector<std::shared_ptr<Entity> > ents, std::vector<std::shared_ptr<Component> > comps) : 
                entities(ents), components(comps) {};

            void addEntity(std::shared_ptr<Entity> entity);

            std::shared_ptr<Entity> getEntity(int idx) { return entities.at(idx); }

            std::vector<std::shared_ptr<Entity> > getEntities() { return entities; }

            void integrateEntities(float duration);

            void addComponent(std::shared_ptr<Component> component);

            std::vector<std::shared_ptr<Component> > getComponents() { return components; }

        private:
            std::vector<std::shared_ptr<Entity> > entities;
            std::vector<std::shared_ptr<Component> > components;
    };
};
