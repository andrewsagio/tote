use <parts.scad>

module leg(hip, knee, ankle, explode) {
    SG90_single_horn();
    translate([0, 0, explode]) SG90_horn_screw();
    translate([0, 0, -explode]) rotate(hip - 90) {
        rotate(-90) SG90();
        translate([12.75, -12 - explode, -23.75]) rotate([90, 180, 90]) {
            SG90();
            translate([0, 0, explode]) rotate(knee) {
                SG90_single_horn();
                translate([0, 0, explode]) SG90_horn_screw();
                translate([17.6, 0, 0]) {
                    translate([0, 0, 6 - explode]) rotate([0, 180, 0])
                        SG90_double_horn();
                    translate([-6, 0, 5 - explode * 2]) rotate([0, 180, 0])
                        SG90_horn_screw();
                    translate([-12, 0, 5 - explode * 2]) rotate([0, 180, 0])
                        SG90_horn_screw();
                    translate([6, 0, 5 - explode * 2]) rotate([0, 180, 0])
                        SG90_horn_screw();
                    translate([12, 0, 5 - explode * 2]) rotate([0, 180, 0])
                        SG90_horn_screw();
                }
                translate([35.2, 0, 0]) rotate([0, 0, 180]) {
                    SG90_single_horn();
                    translate([0, 0, explode]) SG90_horn_screw();
                    translate([0, 0, -explode]) rotate(ankle) {
                        SG90();
                        translate([-3.1 - explode, -20, -15])
                            rotate([-90, 0, 90]) {
                                SG90_double_horn();
                        }
                    }
                }
            }
        }
    }
}

module board() {
    difference() {
        translate([-19.15, -19.15, -0.8]) {
            color("WhiteSmoke") cube([38.3 + 2.54, 38.3, 1.6]);
            color("Gold") {
                for (x = [0:2])
                    translate([1.27 * 6 + 2.54 * x, 1.27 * 1, 0.8])
                        cylinder(r=1, h=1.8, center=true, $fn=8);
                for (x = [0:3])
                    translate([1.27 * 4 + 2.54 * x, 1.27 * 3, 0.8])
                        cylinder(r=1, h=1.8, center=true, $fn=8);
                for (x = [0:1])
                    translate([1.27 * 8 + 2.54 * x, 1.27 * 5, 0.8])
                        cylinder(r=1, h=1.8, center=true, $fn=8);
                for (y = [2:5])
                    translate([1.27 * 29, 1.27 * 8 + 2.54 * y, 0.8])
                        cylinder(r=1, h=1.8, center=true, $fn=8);
                for (y = [0:2])
                    translate([1.27 * 27, 1.27 * 8 + 2.54 * y, 0.8])
                        cylinder(r=1, h=1.8, center=true, $fn=8);
                for (y = [4:7])
                    translate([1.27 * 27, 1.27 * 8 + 2.54 * y, 0.8])
                        cylinder(r=1, h=1.8, center=true, $fn=8);
                for (x = [0:11]) {
                    translate([1.27 * 3 + 2.54 * x, 1.27 * 9, 0.8])
                        cylinder(r=1, h=1.8, center=true, $fn=8);
                    translate([1.27 * 3 + 2.54 * x, 1.27 * 21, 0.8])
                        cylinder(r=1, h=1.8, center=true, $fn=8);
                }
                for (x = [0:1]) {
                    translate([1.27 * 10 + 2.54 * x, 1.27 * 19, 0.8])
                        cylinder(r=1, h=1.8, center=true, $fn=8);
                }
                for (x = [0:5]) for (y = [0:2]) {
                    translate([1.27 * 12 + 2.54 * x, 1.27 * 2.5 + 2.54 * y, 0.8])
                        cylinder(r=1, h=1.8, center=true, $fn=8);
                    translate([1.27 * 12 + 2.54 * x, 1.27 * 23.5 + 2.54 * y, 0.8])
                        cylinder(r=1, h=1.8, center=true, $fn=8);
                }
            }
        }
        color("WhiteSmoke") {
            translate([16.5, 16.5, 0]) cylinder(r=1.2, h=2, center=true, $fn=8);
            translate([-16.5, 16.5, 0]) cylinder(r=1.2, h=2, center=true, $fn=8);
            translate([16.5, -16.5, 0]) cylinder(r=1.2, h=2, center=true, $fn=8);
            translate([-16.5, -16.5, 0]) cylinder(r=1.2, h=2, center=true, $fn=8);
            translate([11.42, 11.43, 0]) cylinder(r=1.2, h=2, center=true, $fn=8);
            translate([-11.42, 11.43, 0]) cylinder(r=1.2, h=2, center=true, $fn=8);
            translate([11.42, -11.43, 0]) cylinder(r=1.2, h=2, center=true, $fn=8);
            translate([-11.42, -11.43, 0]) cylinder(r=1.2, h=2, center=true);
        }
        translate([-19.15, -19.15, -0.8]) {
            color("Gold") {
                for (x = [0:2])
                    translate([1.27 * 6 + 2.54 * x, 1.27 * 1, 0.8])
                        cylinder(r=0.4, h=2, center=true, $fn=8);
                for (x = [0:3])
                    translate([1.27 * 4 + 2.54 * x, 1.27 * 3, 0.8])
                        cylinder(r=0.4, h=2, center=true, $fn=8);
                for (x = [0:1])
                    translate([1.27 * 8 + 2.54 * x, 1.27 * 5, 0.8])
                        cylinder(r=0.4, h=2, center=true, $fn=8);
                for (y = [2:5])
                    translate([1.27 * 29, 1.27 * 8 + 2.54 * y, 0.8])
                        cylinder(r=0.4, h=2, center=true, $fn=8);
                for (y = [0:2])
                    translate([1.27 * 27, 1.27 * 8 + 2.54 * y, 0.8])
                        cylinder(r=0.4, h=2, center=true, $fn=8);
                for (y = [4:7])
                    translate([1.27 * 27, 1.27 * 8 + 2.54 * y, 0.8])
                        cylinder(r=0.4, h=2, center=true, $fn=8);
                for (x = [0:11]) {
                    translate([1.27 * 3 + 2.54 * x, 1.27 * 9, 0.8])
                        cylinder(r=0.4, h=2, center=true, $fn=8);
                    translate([1.27 * 3 + 2.54 * x, 1.27 * 21, 0.8])
                        cylinder(r=0.4, h=2, center=true, $fn=8);
                }
                for (x = [0:1]) {
                    translate([1.27 * 10 + 2.54 * x, 1.27 * 19, 0.8])
                        cylinder(r=0.4, h=2, center=true, $fn=8);
                }
                for (x = [0:5]) for (y = [0:2]) {
                    translate([1.27 * 12 + 2.54 * x, 1.27 * 2.5 + 2.54 * y, 0.8])
                        cylinder(r=0.4, h=2, center=true, $fn=8);
                    translate([1.27 * 12 + 2.54 * x, 1.27 * 23.5 + 2.54 * y, 0.8])
                        cylinder(r=0.4, h=2, center=true, $fn=8);
                }
            }
        }
    }
}

module components(explode) {
    translate([-19.15, -19.15, -0.8]) {
        translate([1.27 * 26, 2.54 * 4, 1.5 + explode]) rotate([0, 0, 90])
            arduino_pro_mini();
        translate([5, 33, 0 - explode]) rotate([0, 180, 0]) capacitor();
        translate([2.54 * 14, 2.54 * 6, 10 + explode]) rotate(180) ir_sensor();
        translate([2.54 * 5.5, 2.54, -5 - explode]) rotate(180) switch();
        for (x = [0:1]) {
            translate([1.27 * 8 + 2.54 * x, 1.27 * 5, 0.8 - explode])
                rotate([0, 180, 0]) goldpin();
        }
        for (x = [0:5]) for (y = [0:2]) {
            translate([1.27 * 12 + 2.54 * x, 1.27 * 2.5 + 2.54 * y, 0.8 - explode])
                rotate([0, 180, 0]) goldpin();
            translate([1.27 * 12 + 2.54 * x, 1.27 * 23.5 + 2.54 * y, 0.8 - explode])
                rotate([0, 180, 0]) goldpin();
        }
        translate([1.27 * 4, 1.27 * 2.5, -1.2]) color("Silver")
            cube([2.54, 1, 1]);
    }
}

module body(explode) {
    board();
    components(explode);
    translate([-19.15, -19.15, -0.8]) {
        rotate([0, 180, 0]) {
            translate([-5.5 * 2.54, 3.75 * 2.54, 1.8 + explode * 2])
                rotate(180) rc_servo_plug();
            translate([-6.5 * 2.54, 3.75 * 2.54, 1.8 + explode * 2])
                rotate(180) rc_servo_plug();
            translate([-7.5 * 2.54, 3.75 * 2.54, 1.8 + explode * 2])
                rotate(180) rc_servo_plug();
            translate([-8.5 * 2.54, 3.75 * 2.54, 1.8 + explode * 2])
                rotate(180) rc_servo_plug();
            translate([-9.5 * 2.54, 3.75 * 2.54, 1.8 + explode * 2])
                rotate(180) rc_servo_plug();
            translate([-10.5 * 2.54, 3.75 * 2.54, 1.8 + explode * 2])
                rotate(180) rc_servo_plug();
            translate([-6.5 * 2.54, 11.25 * 2.54, 1.8 + explode * 2])
                rc_servo_plug();
            translate([-7.5 * 2.54, 11.25 * 2.54, 1.8 + explode * 2])
                rc_servo_plug();
            translate([-8.5 * 2.54, 11.25 * 2.54, 1.8 + explode * 2])
                rc_servo_plug();
            translate([-9.5 * 2.54, 11.25 * 2.54, 1.8 + explode * 2])
                rc_servo_plug();
            translate([-10.5 * 2.54, 11.25 * 2.54, 1.8 + explode * 2])
                rc_servo_plug();
            translate([-11.5 * 2.54, 11.25 * 2.54, 1.8 + explode * 2])
                rc_servo_plug();
       }

    }
}

module robot(explode) {
    translate([20.75, 20.75, -2.1 - explode]) rotate(-135) {
        leg(0, 0, 0, explode);
    }
    translate([-20.75, -20.75, -2.1 - explode]) rotate(45) {
        leg(0, 0, 0, explode);
    }
    translate([20.75, -20.75, -2.1 - explode]) rotate(135) mirror([0, 1, 0]) {
        leg(0, 0, 0, explode);
    }
    translate([-20.75, 20.75, -2.1 - explode]) rotate(-45) mirror([0, 1, 0]) {
        leg(0, 0, 0, explode);
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

robot(0);
