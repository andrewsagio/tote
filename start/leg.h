#ifndef LEG_H
#define LEG_H

const double COXA = 12.0;
const double FEMUR = 42.0;
const double TIBIA = 38.5;
const double BASE = 21.0;

const char LEG_X[4] = {-1, -1, 1, 1};
const char LEG_Y[4] = {1, -1, -1, 1};
extern double leg_position[4][3];
const double HOME = (COXA + FEMUR) / SQRT2;

bool move_leg(unsigned char leg, double x, double y, double z);
bool move_leg_by(unsigned char leg, double dx, double dy, double dz);
bool rotate_leg_by(unsigned char leg, double angle);

#endif
