#include "entity.h"

namespace tumble {

    void Entity::addForce(const Vector3& force)
    {
        forceAccum += force;
    }

}