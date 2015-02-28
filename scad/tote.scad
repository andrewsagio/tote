use <parts.scad>

base = 39/2;


module leg(hip, knee, ankle) {
    HK15318_single_horn();
    translate([0, 0, -2.5]) SG90_horn_screw();
    rotate(hip) {
        rotate(-90) HK15318();
        translate([8, -8, -16]) rotate([90, 180, 90]) {
            HK15318();
            rotate(knee - 90) {
                HK15318_single_horn();
                translate([0, 0, -2.5]) SG90_horn_screw();
                translate([0, 7, 2.5]) rotate([180, 0 ,0]) SG90_horn_screw();
                translate([0, 11, 2.5]) rotate([180, 0 ,0]) SG90_horn_screw();
                translate([0, 18, -1]) rotate(180) {
                    HK15318_single_horn();
                    translate([0, 0, -2.5]) SG90_horn_screw();
                    rotate(ankle + 90) {
                        HK15318();
                        translate([3.8, -14.5, -12.5]) rotate([0, 90, 0])
                            HK15318_double_horn();
                    }
                }
            }
        }
    }
}

module body() {
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


    translate([1.27 * 13, -2.54 * 4, 1.5]) rotate([0, 0, 90])
        arduino_pro_mini();
    translate([-13.5, 13.5, 1]) capacitor();

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

module robot() {
    translate([0, 0, 40]) {
        translate([base, -base, -1.5]) rotate(45) leg(0, 0, 0);
        mirror([0, 1]) translate([base, -base, -1.5]) rotate(45) leg(0, 0, 0);
        mirror([1, 0]) translate([base, -base, -1.5]) rotate(45) leg(0, 0, 0);
        mirror([1, 0]) mirror([0, 1]) translate([base, -base, -1.5]) rotate(45) leg(0, 0, 0);
        body();
        translate([16.5, 16.5, -2]) SG90_horn_screw();
        translate([-16.5, 16.5, -2]) SG90_horn_screw();
        translate([16.5, -16.5, -2]) SG90_horn_screw();
        translate([-16.5, -16.5, -2]) SG90_horn_screw();
        translate([11.42, 11.42, -2]) SG90_horn_screw();
        translate([-11.42, 11.42, -2]) SG90_horn_screw();
        translate([11.42, -11.42, -2]) SG90_horn_screw();
        translate([-11.42, -11.42, -2]) SG90_horn_screw();
        rotate(90) translate([0, -16, -3.8]) wkLiPo238();
    }
}

robot();
