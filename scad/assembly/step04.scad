use <../parts.scad>
use <../tote.scad>

body();
translate([20.75, 20.75, 0]) rotate(-135) {
    leg(0, 0, 0, 0);
}
translate([16.5, 16.5, -2.5]) rotate([0, 180, 0]) SG90_horn_screw();
translate([11.2, 11.2, -2.5]) rotate([0, 180, 0]) SG90_horn_screw();
