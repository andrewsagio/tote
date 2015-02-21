use <../parts.scad>

HK15318_single_horn();
translate([0, 0, -2.5]) SG90_horn_screw();
rotate(90) HK15318();
color("LightSkyBlue", 0.5) translate([3, -13, -13]) rotate([90, 0, 0]) cylinder(r=6, h=0.5);
translate([16, -18, -16]) rotate([90, 180, 90]) {
    HK15318();
    rotate(-90) {
        HK15318_single_horn();
        translate([0, 0, -2.5]) SG90_horn_screw();
        translate([0, 7, -12.5]) rotate([180, 0 ,0]) SG90_horn_screw();
        translate([0, 11, -12.5]) rotate([180, 0 ,0]) SG90_horn_screw();
        translate([0, 18, -8]) rotate(180) {
            HK15318_single_horn();
            translate([0, 0, -2.5]) SG90_horn_screw();
            rotate(90) {
                HK15318();
                translate([9.8, -15, -13]) rotate([0, 90, 0])
                    HK15318_double_horn();
                    color("LightSkyBlue", 0.5) translate([5, -8, -13]) rotate([0, 90, 0]) cylinder(r=4, h=0.5);
            }
        }
    }
}
