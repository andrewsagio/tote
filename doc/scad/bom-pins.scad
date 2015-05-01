use <parts.scad>;

for (pin = [-6:5]) {
    translate([0, 2.54 * pin, 0]) goldpin();
}

