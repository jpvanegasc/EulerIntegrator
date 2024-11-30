#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int steps = 200;
    float *distance = integrate(10, -9.8, steps);

    for (int i = 0; i < steps; i++) {
        printf("%d,%f\n", i, distance[i]);
    }

    return 0;
}
