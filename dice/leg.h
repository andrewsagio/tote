#ifndef LEG_H
#define LEG_H

#define COXA    8.0
#define FEMUR   20.5
#define TIBIA   28.5
#define BASE    18.0

const char LEG_X[4] = {-1, -1, 1, 1};
const char LEG_Y[4] = {1, -1, -1, 1};
extern double leg_position[4][3];

bool move_leg(unsigned char leg, double x, double y, double z);
bool move_leg_by(unsigned char leg, double dx, double dy, double dz);

#endif
