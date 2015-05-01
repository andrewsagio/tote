use <parts.scad>;

rotate([0, 180, 0]) {
    arduino_pro_mini();
    translate([2.54, 2.54 * 12.5, 0]) for (pin = [0:5]) {
        translate([2.54 * pin, 0, 0]) goldpin();
    }

    translate([2.54, 2.54 * 12.5, 0]) color("Silver") sphere(r=0.75, $fn=12);
    translate([2.54 * 2, 2.54 * 12.5, -1]) color("Silver") rotate([30, 210, 0])
        cylinder(r=0.5, h=100, $fn=12);
    translate([2.54 * 2 + 2, 2.54 * 12.5 + 1, -3]) color("AliceBlue")
        rotate([-30, 150, 0]) {
            cylinder(r1=0.5, r2=10, h=100, $fn=16);
            sphere(r=0.5, $fn=16);
        }
}
