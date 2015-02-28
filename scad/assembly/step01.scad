use <../parts.scad>;

module body2() {
    color("Orange") translate([0, 0, 0.6]) difference() {
        cube([38.3, 38.2, 1.2], center=true);
        translate([16.5, 16.5, 0]) cylinder(r=1.2, h=2, center=true);
        translate([-16.5, 16.5, 0]) cylinder(r=1.2, h=2, center=true);
        translate([16.5, -16.5, 0]) cylinder(r=1.2, h=2, center=true);
        translate([-16.5, -16.5, 0]) cylinder(r=1.2, h=2, center=true);
        translate([11.42, 11.43, 0]) cylinder(r=1.2, h=2, center=true);
        translate([-11.42, 11.43, 0]) cylinder(r=1.2, h=2, center=true);
        translate([11.42, -11.43, 0]) cylinder(r=1.2, h=2, center=true);
        translate([-11.42, -11.43, 0]) cylinder(r=1.2, h=2, center=true);
    }


    translate([1.27 * 13, -2.54 * 3.5, 1.5]) rotate([0, 0, 90])
        arduino_pro_mini();

    translate([2.54 * 6.5, 2.54 * 6, 1]) rotate(180) HK15318_plug();
    translate([2.54 * 3.5, 2.54 * 6, 1]) rotate(180) HK15318_plug();
    translate([2.54 * 2, 2.54 * 6, 1]) rotate(180) HK15318_plug();
    translate([2.54 * 0.5, 2.54 * 6, 1]) rotate(180) HK15318_plug();
    translate([2.54 * -1, 2.54 * 6, 1]) rotate(180) HK15318_plug();
    translate([2.54 * -2.5, 2.54 * 6, 1]) rotate(180) HK15318_plug();

    translate([2.54 * -3, 2.54 * -7, 1]) HK15318_plug();
    translate([2.54 * -1.5, 2.54 * -7, 1]) HK15318_plug();
    translate([2.54 * 0, 2.54 * -7, 1]) HK15318_plug();
    translate([2.54 * 1.5, 2.54 * -7, 1]) HK15318_plug();
    translate([2.54 * 3, 2.54 * -7, 1]) HK15318_plug();
    translate([2.54 * 4.5, 2.54 * -7, 1]) HK15318_plug();

    translate([2.54 * -6, 2.54 * -7, 10]) ir_sensor();
    translate([-2.54, 2.54 * 6, -2.54 * 2]) switch();
}

body2();
