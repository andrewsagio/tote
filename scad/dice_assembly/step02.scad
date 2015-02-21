use <../parts.scad>

HK15318();
translate([0, 0, 3]) rotate(90) HK15318_single_horn();
translate([0, 0, 6]) SG90_horn_screw();

translate([20, 0, 0]) {
    HK15318();
    translate([0, 0, 3]) rotate(-90) HK15318_single_horn();
    translate([0, 0, 6]) SG90_horn_screw();
}
