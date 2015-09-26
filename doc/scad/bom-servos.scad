use <parts.scad>;

SG90();
translate([-10, 0, 0]) SG90_horn_screw();
translate([20, 0, 0]) SG90_mount_screw();
translate([10, 0, 0]) SG90_mount_screw();
translate([0, 10, 0]) SG90_single_horn();
translate([0, 20, 0]) SG90_double_horn();
translate([-10, 20, -30]) rc_servo_plug();
