use <../dice.scad>
use <../parts.scad>

body();
translate([19.5, -19.5, -5]) rotate(45) leg(0, 0, 0);
translate([16.5, -16.5, 5]) SG90_horn_screw();
translate([11.42, -11.42, 5]) SG90_horn_screw();
