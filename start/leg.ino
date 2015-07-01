#include "misc.h"
#include "leg.h"

const unsigned char LEG_JOINT[4][3] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {9, 10, 11},
};

float leg_position[4][3] = {
    {HOME, LEG_Y[0] * HOME, -TIBIA},
    {HOME, LEG_Y[0] * HOME, -TIBIA},
    {HOME, LEG_Y[0] * HOME, -TIBIA},
    {HOME, LEG_Y[0] * HOME, -TIBIA},
};


float _solve_triangle(float a, float b, float c) {
    // Calculate the angle between a and b, opposite to c.
    a = max(a, -a);
    b = max(b, -b);
    c = max(c, -c);
    if (a + b < c || a + c < b || b + c < a) { return NAN; }
    return acosf((a * a + b * b - c * c) / (2 * a * b));
}

float _norm(float a, float b) {
    // Calculate the norm of a vector.
    return sqrtf(a * a + b * b);
}

bool _inverse_kinematics(float x, float y, float z,
                         float *ankle, float *knee, float *hip) {
    // Calculate angles for knee and ankle, and put them in those variables.
    // Return true on success, and false if x and y are out of range.
    float f = _norm(x, y) - COXA;
    float d = _norm(f, z);
    if (d > FEMUR + TIBIA) { return false; }
    *hip = atan2f(y, x) - PI4;
    if (isnan(*hip)) { return false; }
    *knee = _solve_triangle(FEMUR, d, TIBIA) - atan2f(-z, f);
    if (isnan(*knee)) { return false; }
    *ankle = _solve_triangle(FEMUR, TIBIA, d) - PI2;
    if (isnan(*ankle)) { return false; }
    return true;
}

bool move_leg(unsigned char leg, float x, float y, float z) {
    // Move the tip of the leg to x, y. Return false when out of range.
    float ankle;
    float knee;
    float hip;

    if (!_inverse_kinematics(x, y, z, &ankle, &knee, &hip)) { return false; }
    servo_move(LEG_JOINT[leg][0], ankle);
    servo_move(LEG_JOINT[leg][1], knee);
    servo_move(LEG_JOINT[leg][2], hip);
    leg_position[leg][0] = x;
    leg_position[leg][1] = y;
    leg_position[leg][2] = z;
    return true;
}

bool move_leg_by(unsigned char leg, float dx, float dy, float dz) {
    // Move the tip of the leg by dx, dy. Return false when out of range.
    return move_leg(leg,
                    leg_position[leg][0] + dx,
                    leg_position[leg][1] + dy,
                    leg_position[leg][2] + dz);
}

bool rotate_leg_by(unsigned char leg, float angle) {
    // Rotate the tip of the leg around the center of robot's body.
    if (angle == 0.0) { return true; }
    float x = leg_position[leg][0] + BASE;
    float y = leg_position[leg][1] + BASE;
    float nx = x * cosf(angle) - y * sinf(angle) - BASE;
    float ny = x * sinf(angle) + y * cosf(angle) - BASE;
    return move_leg(leg, nx, ny, leg_position[leg][2]);
}
