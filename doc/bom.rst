Bill of Materials
*****************

Required
========
   * Printed Circuit Board, the board design file is in the repository,
   * Arduino Pro Mini, 3.3V/8Mhz version,
   * 12 SG90 micro Servos, with screws and plastic horns,
   * 2.54mm pin headers, with at least 38 pins total,
   * 3.7V 1S LiPo Battery (I used a 300mAh battery),

Optional
========
   * Infra-Red Receiver (I used VS1838B).
   * Ultra Sound distance sensor (I used HC-SR04),
   * 1000µF electrolytic capacitor, for avoiding brown-outs,
   * 2 47kΩ SMD resistors and a 47nF SMD capacitor, for battery monitoring,
   * Power Switch, for convenient on/off without unplugging the battery,
   * Piezoelectric Buzzer, for making noises,
   * Battery Charger Module, for charging the battery without unplugging,
   * Small Rubber Hose, for the feet,
   * Any additional sensors or boards you require.

At the time of writing, the required materials could be bought online for about
$50 total, but it greatly depends on availability, amount, and quality you
require. Also, shipping time.

Arduino Pro Mini
================

The Arduino Pro Mini, or any of the widely available Pro Mini clones, are the
cheapest Arduino boards available, even as cheap as $2 a piece. That price is
achieved by stripping them of anything that isn't necessary -- including the
USB port. You cannot connect this board directly to your computer for
programming, as you can other Arduinos, instead you have to use a device called
``USB2TTL``. But you only need one such device, and you can re-use it for
programming as many Pro Minis, as you want.

You can also use a different small Arduino board, such as Nano or Pro Micro.
They do have an USB port on them, which will stick a little bit out from the
back of the robot.

The Pro Mini usually comes with three unsoldered pin headers, as you can see
here:

.. image:: scad/bom-arduino.png

You will need to solder at least the short, 6-pin one (it may be a little
different version, with pins angled at 90°, but it doesn't matter much).
Remember to make it stick out at the top of the board, on the same side as all
the components, and leave the empty side of the board flat. Those are the pins
that you will use to program and debug your robot.

If you want to use sockets, you can also solder the two longer pin headers --
those come on the bottom of the board, on the empty side. If you don't want the
board to be removable from your robot, you can skip those and use them for the
servo sockets instead.
