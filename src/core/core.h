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

        Vector3 operator+(const Vector3& vec)
        {
            return Vector3(x+vec.x, y+vec.y, z+vec.z);
        }

        void operator+=(const Vector3& vec)
        {
            x += vec.x;
            y += vec.y;
            z += vec.z;
        }

        Vector3 operator-(const Vector3& vec)
        {
            return Vector3(x-vec.x, y-vec.y, z-vec.z);
        }

        void operator-=(const Vector3& vec)
        {
            x -= vec.x;
            y -= vec.y;
            z -= vec.z;
        }

        Vector3 operator*(const real value)
        {
            return Vector3(x*value, y*value, z*value);
        }

        void operator*=(const real value)
        {
            x *= value;
            y *= value;
            z *= value;
        }

        void addScaledVector(const Vector3&, real);

        void clear()
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    };
}