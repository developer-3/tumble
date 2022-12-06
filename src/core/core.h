#pragma once

#include "precision.h"

namespace tumble {

    class Vector3 {
    public:
        
        real x;
        real y;
        real z;

        Vector3() : x(0), y(0), z(0) {}

        Vector3(const real x, const real y, const real z) 
            : x(x), y(y), z(z) {}


    };
}