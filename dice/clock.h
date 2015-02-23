#ifndef CLOCK_H
#define CLOCK_H

#define FPS 32

const unsigned char TICK = 1000 / FPS;
void tick(unsigned int ms);

#endif
