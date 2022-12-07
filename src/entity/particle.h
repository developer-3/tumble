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

        /**
         * @brief update particle's position based
         * on velocity and acceleration
         * 
         * @param duration 
         */
        void integrate(real duration);
    };
}