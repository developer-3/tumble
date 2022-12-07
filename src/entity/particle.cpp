#include "assert.h"
#include "particle.h"

namespace tumble {

    void Particle::integrate(real duration)
    {
        assert(duration > 0.0);

        /** update position */
        position.addScaledVector(velocity, duration);    

        /** update acceleration from force */
        Vector3 resultingAcc = acceleration;
        resultingAcc.addScaledVector(forceAccum, inverseMass);

        /** update velo */
        velocity.addScaledVector(resultingAcc, duration);

        /** drag */
        velocity *= real_pow(damping, duration);

        clearAccumulator();
    }

}