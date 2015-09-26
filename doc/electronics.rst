Electronics
===========

The designs of the main printed circuit board are available in the code
repository_. You will need Fritzing software to open them and export as
whatever format is required for fabricating it.

.. _repository: https://bitbucket.org/thesheep/tote

Arduino Pro Mini is used for the brains of the robot. It is connected directly
to the servo signals and to the battery. There is also a 1000µF electrolytic
capacitor connected across the battery to avoid brown-outs. An optional voltage
divider of two 47kΩ resistors, with a 47nF capacitor for noise reduction is
used to monitor the battery voltage and shut down the robot when it drops too
low. The battery is any light 1S, 3.7V LiPo cell. Other kinds of batteries can
be used, as long as they are light enough and provide enough power. Remote
control is done using a VS1838B infra-red sensor, but other sensors can be
used.

Several pins of the Arduino are free, including the I²C pins, allowing for
connecting more sensors.

The prototype also has an optional LiPo charging/protection module attached,
for convenience, although the battery can be charged by any suitable charger.
