Design Decisions
****************


Design Goals and Constraints
============================

The main goal is to have a walking robot that is interesting to program and at
the same time easy to build. From that, we get a number of constraints:

    * The robot has to fit on the desk, because not everyone has a garage.
    * It has to have inverse kinematics, otherwise we are limited to replaying
      pre-recorded movements.
    * It should avoid parts that are custom-made using tools and materials that
      are not widely available. In particular, no laser-cutting or 3D-printing.
    * The parts should be common, cheap and easy to get, also in bulk.
    * It should be possible to easily extend or modify the robot.
    * In the basic version it should have enough functionality to be fun to
      play with.


Hacks and Workarounds
=====================

Because of the above constraints and the desire to make it all as cheap as
possible, I've made some design decisions that are not exactly good
engineering.  I figured out that it's better to have a crappy but working
robot, than a beautifully designed plan. So here are some corners that I've
cut:


Mechanical Design
-----------------

The way this robot is assembled together only works because it's so
lightweight. Would the robot be heavier, there would be significant problems:

    * Servomotors are used as structural elements.
    * The printed circuit board is also used as a structural element.
    * The whole robot weight rests sideways on the servo shafts.
    * The servo horns used for legs are elastic.
    * The screws that come with the servos are too big for what they used for.
    * The servo cables are all over the place.
    * The power switch is in an awkward place.
    * There is no good way to attach the battery.
    * The legs need some rubber at their ends, or they will slip.

Most of those problems can be solved by using better materials and adding some
structural support elements, but that affects the price and complexity.


Electrical Design
-----------------

The desire to cut costs and minimise the number of parts also made me make some
not-entirely-kosher decisions on the electrical side of things:

    * The servomechanisms are under-powered. The specification asks for 4.6V,
      and they get from 3.6V to 4.2V depending on the charge level of the LiPo
      battery.
    * The servomechanisms are powered directly from the battery, without any
      kind of voltage regulator.
    * The undercharge battery protection is software-based, which means it can
      easily fail.
    * There is no battery charger build in. You have to disconnect the battery
      to charge it.
    * The Pro Mini is soldered directly onto the printed circuit board.

Those problems can be easily solved by adding the missing parts to the design.
There is even some room left for them, in the form of additional holes and
pins.
