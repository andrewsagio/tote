use <parts.scad>;

arduino_pro_mini();
translate([2.54, 2.54 * 12.5, 0]) for (pin = [0:5]) {
    translate([2.54 * pin, 0, 0]) goldpin();
}

