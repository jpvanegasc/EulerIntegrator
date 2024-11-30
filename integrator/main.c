#include <stdio.h>
#include <stdlib.h>

#include "integrator.h"

int main() {
    int steps = 200;
    float *distance = integrate(10, -9.8, steps);

    for (int i = 0; i < steps; i++) {
        printf("%d,%f\n", i, distance[i]);
    }

    return 0;
}
