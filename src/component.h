#pragma once

#include "core/core.h"

namespace tumble {

    class Component {
        public:
            Component() : 
                force(Vector3(0.0f, 0.0f, 0.0f)) { };

            Component(Vector3 force) :
                force(force) {};


            virtual ~Component() { };

            Vector3 getForce() { return force; }

            void setForce(Vector3 force) { this->force = force; }

            Vector3 force;
    };

};
