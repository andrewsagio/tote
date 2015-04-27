use <../parts.scad>

SG90();
translate([0, 0, 3]) rotate(180) SG90_single_horn();
translate([0, 0, 6]) SG90_horn_screw();

translate([20, 0, 0]) {
    SG90();
    translate([0, 0, 3]) rotate(0) SG90_single_horn();
    translate([0, 0, 6]) SG90_horn_screw();
}
