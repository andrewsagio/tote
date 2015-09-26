use <parts.scad>;

arduino_pro_mini();
translate([-2.54, 0, 0]) for (pin = [0:11]) {
    translate([0, 2.54 * pin, 0]) rotate([0, -90, 0]) goldpin();
}
translate([2.54 * 8, 0, 0]) for (pin = [0:11]) {
    translate([0, 2.54 * pin, 0]) rotate([0, 90, 0]) goldpin();
}
translate([2.54, 2.54 * 14, 0]) for (pin = [0:5]) {
    translate([2.54 * pin, 0, 0]) rotate([-90, 0, 0]) goldpin();
}
