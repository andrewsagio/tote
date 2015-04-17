use <../tote.scad>

leg(0, 0, 0, 10);
color("LightSkyBlue", 0.5) {
    translate([5, -8, -13]) rotate([0, 90, 0]) cylinder(r=4, h=0.5);
    translate([-5, -13, -13]) rotate([90, 0, 0]) cylinder(r=6, h=0.5);
}
