#include "core.h"

namespace tumble {

    void Vector3::addScaledVector(const Vector3& vec, real duration) {
        x += vec.x * duration;
        y += vec.y * duration;
        z += vec.z * duration;
    }

}