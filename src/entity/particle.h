#pragma once

#include <iostream>

#include "entity.h"

namespace tumble {

    class Particle : public Entity {
    public:
        Particle() {
            std::cout << "particle created." << std::endl;
        }

        ~Particle() { };

        void integrate(real duration);

    };
}