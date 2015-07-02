#ifndef LEG_H
#define LEG_H

const float COXA = 12.0;
const float FEMUR = 42.0;
const float TIBIA = 38.5;
const float BASE = 21.0;

const int LEG_X[4] = {-1, -1, 1, 1};
const int LEG_Y[4] = {1, -1, -1, 1};
const float HOME = (COXA + FEMUR) / SQRT2;

bool move_leg(unsigned char leg, float x, float y, float z);
bool move_leg_by(unsigned char leg, float dx, float dy, float dz);
bool rotate_leg_by(unsigned char leg, float angle);

extern float leg_position[4][3];

#endif
