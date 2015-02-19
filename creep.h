#ifndef CREEP_H
#define CREEP_H

/* Walking speed. */
extern double creep_dx; // Sideways.
extern double creep_dy; // Forward.

/* Perform one step of the creep gait with the current speed. */
void creep();

#endif
