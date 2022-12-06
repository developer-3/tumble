#include "assert.h"
#include "particle.h"

namespace tumble {

    void Particle::integrate(real duration)
    {
        assert(duration > 0.0);

        /** update position */
        // position.addScaledVector(velocity, duration);
    }

}