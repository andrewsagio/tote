#ifndef CREEP_H
#define CREEP_H

/* Walking speed. */
extern float creep_dx; // Sideways.
extern float creep_dy; // Forward.
extern float creep_spread;
extern float creep_rotation;
extern float creep_height;

/* Perform one step of the creep gait with the current speed. */
void walk();

#endif
