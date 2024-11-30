#include "integrator.h"

float step(float time, float velocity, float acceleration) {
    return velocity * time + 0.5 * acceleration * time * time;
}

float *integrate(float v0, float a, int steps) {
    float *distance = malloc(sizeof(float) * steps);

    float dt = 0.01;
    for (int i = 0; i < steps; i++) {
        distance[i] = step(i * dt, v0, a);
    }
    return distance;
}
