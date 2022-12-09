#include "core.h"

namespace tumble {

    void Vector3::addScaledVector(const Vector3& vec, real scale) {
        x += vec.x * scale;
        y += vec.y * scale;
        z += vec.z * scale;
    }

}