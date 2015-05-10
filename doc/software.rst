Software
********

Tote comes with example program, that makes it walk forward, and lets you
control it with a TV remote. If you want to control it from a PC or a different
board, then you will have to write your own software.

All the required code is included in the repository_. You will need an Arduino
IDE and a TTL2USB programmer for the Pro Mini to compile and upload the
software into the robot. Connect the programmer, open ``start.ino`` in the
Arduino IDE, and click "Upload". That's all.

.. _repository: https://bitbucket.org/thesheep/tote

For the infra-red communication, I'm using the excellent IRLRemote library,
written by NicoHood. You may want to adjust the ``ir.ino`` file to modify the
button commands and the protocol, so that they match your TV remote.


Features
========

Creep Gait
----------

Right after switching on, the robot will start walking forward using the creep
gait. This is so that you can see that it works properly even when you don't
have a TV remote at hand.


Remote Control
--------------

You can use a TV remote to control the robot. Direction keys will make it speed
up/slow down, go backwards or turn. You can also raise and lower its body,
spread the legs more, make it go sideways, etc.


Power Off
---------

The power button on the TV remote will make it fold and shut down -- the servos
will be powered down and the board will enter a sleep mode. You should switch
it off with the power switch manually anyways, because it will still consume
some power in that state.


Battery Monitoring
------------------

If the battery voltage drops too low (and you have soldered the optional two
resistors and a capacitor required for monitoring it), it will also fold and
switch off when the battery voltage runs too low. Note, that it will probably
not have enough power to finish folding in this situation, so it may end up in
an awkward position, or even in a restart loop. You should switch it off and
charge the battery as soon as possible.


Trot Gait
---------

Pressing the direction buttons multiple times makes it walk faster by making
longer steps, until it can't go faster anymore, and then it will switch to a
trot gait, which is about two times faster, but unstable.


Automatic Leg Order
-------------------

The order in which the legs make steps is important for stability. The robot
will automatically select the optimal leg order depending on the direction in
which it is moving.


Beeper
------

If you connect a piezo buzzer to pin 3 and ground, you can make this robot
beep with every step and when it receives a command. This is muted by default
and has to be enabled with a button on the remote, because it's so annoying.


Modes
-----

You switch the modes of operation of the robot with a button on the remote.
Initially there are only two modes: walking and doing nothing. You can easily
add your own modes for additional functions that you program.
