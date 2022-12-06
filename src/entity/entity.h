#pragma once

#include "../core/core.h"

namespace tumble {

    class Entity {
    public:
        Entity() { };

        virtual 
        ~Entity() { };

        Vector3 position;

        Vector3 velocity;

        Vector3 acceleration;

        real damping;

        real inverseMass;

        virtual void integrate(real duration) = 0;
    };

};
