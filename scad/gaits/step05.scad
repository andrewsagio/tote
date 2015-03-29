use <../parts.scad>

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

module body() {
    color("Chocolate") translate([0, 0, 0]) difference() {
        translate([-19.15, -19.15, -0.8]) cube([38.3 + 2.54, 38.3, 1.6]);
        translate([16.5, 16.5, 0]) cylinder(r=1.2, h=2, center=true);
        translate([-16.5, 16.5, 0]) cylinder(r=1.2, h=2, center=true);
        translate([16.5, -16.5, 0]) cylinder(r=1.2, h=2, center=true);
        translate([-16.5, -16.5, 0]) cylinder(r=1.2, h=2, center=true);
        translate([11.42, 11.43, 0]) cylinder(r=1.2, h=2, center=true);
        translate([-11.42, 11.43, 0]) cylinder(r=1.2, h=2, center=true);
        translate([11.42, -11.43, 0]) cylinder(r=1.2, h=2, center=true);
        translate([-11.42, -11.43, 0]) cylinder(r=1.2, h=2, center=true);
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
    body();
    translate([16.5, 16.5, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([-16.5, 16.5, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([16.5, -16.5, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([-16.5, -16.5, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([11.2, 11.2, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([-11.2, 11.2, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([11.2, -11.2, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
    translate([-11.2, -11.2, 2.5]) rotate([0, 180, 0]) SG90_horn_screw();
}


module arrow() {
    color("red") {
        intersection() {
            difference() {
                cylinder(r=100, h=5);
                translate([0, 0, -1]) cylinder(r=95, h=7);
            }
            translate([10, -10, -1]) cube([100, 100, 7]);
        }
        translate([94, 0, -14.14 + 2.5]) difference() {
            rotate([45, 0, 0]) cube([7, 20, 20]);
            translate([-1, 0, 0]) cube([9, 20, 30]);
        }
    }
}

translate([0, 0, 61]) rotate(90) robot(0);
translate([0, 0, 40]) rotate([0, 180, -60]) arrow();
translate([0, 0, 40]) rotate(180 + 60) arrow();
rotate(45) rotate([30, 0, 0]) rotate([0, -90, 0]) arrow();
rotate(90 + 45) rotate([30, 0, 0]) rotate([0, -90, 0]) arrow();
