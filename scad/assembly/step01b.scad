use <../tote.scad>;
use <../parts.scad>;


module components(explode) {
    translate([-19.15, -19.15, -0.8]) {
        translate([1.27 * 26, 2.54 * 4, 9.5 + explode]) rotate([0, 0, 90]) {
            translate([0, 0, explode]) {
                arduino_pro_mini();
                arduino_pro_mini_pins();
            }
            translate([0, 0, 0]) pin_socket(12);
            translate([2.54 * 6, 0, 0]) pin_socket(12);
            translate([2.54 * 5, 2.54 * 6.5, 0]) pin_socket(2);
        }
        translate([5, 33, 2 + explode]) rotate([0, 0, 0]) capacitor();
        translate([2.54 * 14, 2.54 * 6, 10 + explode]) rotate(180) ir_sensor();
        translate([2.54 * 2.5, 2.54, 7 + explode]) rotate([180, 0, 0]) switch();
        for (x = [0:1]) {
            translate([1.27 * 8 + 2.54 * x, 1.27 * 5, 0.8 + explode * 2])
                goldpin();
        }
        for (x = [0:5]) for (y = [0:2]) {
            translate([1.27 * 12 + 2.54 * x, 1.27 * 2.5 + 2.54 * y, 0.8 + explode])
                goldpin();
            translate([1.27 * 12 + 2.54 * x, 1.27 * 23.5 + 2.54 * y, 0.8 + explode])
                goldpin();
        }
        translate([1.27 * 4, 1.27 * 2.5, 1.2]) color("Silver")
            cube([2.54, 1, 1]);
    }
}


board();
components(7);
