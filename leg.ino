#include "leg.h"
#include "misc.h"

#define HOME ((COXA + FEMUR) / SQRT2)

double leg_position[4][3] = {
    {HOME, LEG_SIDE[0] * HOME, -TIBIA},
    {HOME, LEG_SIDE[1] * HOME, -TIBIA},
    {HOME, LEG_SIDE[2] * HOME, -TIBIA},
    {HOME, LEG_SIDE[3] * HOME, -TIBIA},
};


double _solve_triangle(double a, double b, double c) {
    // Calculate the angle between a and b, opposite to c.
    a = abs(a);
    b = abs(b);
    c = abs(c);
    if (a + b < c || a + c < b || b + c < a) { return NaN; }
    return acos((a * a + b * b - c * c) / (2 * a * b));
}

double _norm(double a, double b) {
    // Calculate the norm of a vector.
    return sqrt(a * a + b * b);
}

bool _inverse_kinematics(double x, double y, double z,
                         double *ankle, double *knee, double *hip) {
    // Calculate angles for knee and ankle, and put them in those variables.
    // Return true on success, and false if x and y are out of range.
    double f = _norm(x, y) - COXA;
    double d = min(FEMUR + TIBIA, _norm(f, z));
    *hip = atan2(y, x) - PI4;
    if (isnan(*hip)) { return false; }
    *knee = _solve_triangle(FEMUR, d, TIBIA) - atan2(-z, f);
    if (isnan(*knee)) { return false; }
    *ankle = _solve_triangle(FEMUR, TIBIA, d) - PI2;
    if (isnan(*ankle)) { return false; }
    return true;
}

bool move_leg(unsigned char leg, double x, double y, double z) {
    // Move the tip of the leg to x, y. Return false when out of range.
    double ankle = NaN;
    double knee = NaN;
    double hip = NaN;
    if (!_inverse_kinematics(x, y * LEG_SIDE[leg], z, &ankle, &knee, &hip)) {
        return false;
    }
    servo_move(leg * 3 + 0, ankle);
    servo_move(leg * 3 + 1, knee);
    servo_move(leg * 3 + 2, hip);
    leg_position[leg][0] = x;
    leg_position[leg][1] = y;
    leg_position[leg][2] = z;
    return true;
}

bool move_leg_by(unsigned char leg, double dx, double dy, double dz) {
    // Move the tip of the leg by dx, dy. Return false when out of range.
    return move_leg(leg,
                    leg_position[leg][0] + dx,
                    leg_position[leg][1] + dy,
                    leg_position[leg][2] + dz);
}
