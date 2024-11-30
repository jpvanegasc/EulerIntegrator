#ifndef __INTEGRATOR_H
#define __INTEGRATOR_H

#include <stdlib.h>

float step(float time, float velocity, float acceleration);
float *integrate(float v0, float a, int steps);

#endif // __INTEGRATOR_H
