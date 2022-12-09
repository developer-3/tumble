#pragma once

#include "../core/core.h"

namespace tumble {

    class Entity {
    public:
        Entity() 
            : position(Vector3(0.0f,0.0f,0.0f)), velocity(Vector3(0.0f,0.0f,0.0f)), damping(0.995f) 
            { };

        virtual ~Entity() { };

        Vector3 position;

        Vector3 velocity;

        Vector3 acceleration;

        real damping;

        real inverseMass;

        Vector3 forceAccum;

        void setPosition(const Vector3& vec)
        {
            position = vec;
        }

        Vector3 getPosition() { return position; }

        void setVelocity(const Vector3& vec)
        {
            velocity = vec;
        }

        void setAcceleration(const Vector3& vec)
        {
            acceleration = vec;
        }

        void setDamping(const real value)
        {
            damping = value;
        }

        real getMass() { return 1/inverseMass; }

        void setMass(const real value)
        {
            inverseMass = 1/value;
        }

        void clearAccumulator()
        {
            forceAccum.clear();
        }

        virtual void integrate(real duration) = 0;

        void addForce(const Vector3 &force);
    };

};
