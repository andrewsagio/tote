use <tote.scad>
use <parts.scad>


module robot(explode) {
    translate([20.75, 20.75, -2.1 - explode]) rotate(-135) {
        leg(-20, 5, -12, explode);
    }
    translate([-20.75, -20.75, -2.1 - explode]) rotate(45) {
        leg(20, 5, -12, explode);
    }
    translate([20.75, -20.75, -2.1 - explode]) rotate(135) mirror([0, 1, 0]) {
        leg(0, -40, 10, explode);
    }
    translate([-20.75, 20.75, -2.1 - explode]) rotate(-45) mirror([0, 1, 0]) {
        leg(0, 5, 30, explode);
    }
    body(explode);
    translate([16.5, 16.5, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([-16.5, 16.5, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([16.5, -16.5, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([-16.5, -16.5, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([11.2, 11.2, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([-11.2, 11.2, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([11.2, -11.2, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([-11.2, -11.2, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
}

translate([0, 0, 61]) robot(0);
translate([15, -15, 0]) color("DodgerBlue", 0.25) difference() {
    cube([120, 120, 0.1], center=true);
    rotate(-45) translate([100, 0, 0]) cube([200, 200, 0.2], center=true);
}
