.. _arduino-examples:

Arduino Examples
================
To run this examples use either the Arduino IDE or something similar like the PlatformIO extension for Visual Code or Atom.

* :code:`examples/directionDetection` - Determining the direction of the detected target in polling mode.
* :code:`examples/directionDetectionInt` - Determining the direction of the detected target with the help of interrupts.
* :code:`examples/motionDetection` - Checking for a motion in the detection range of the radar sensor in polling mode.
* :code:`examples/motionDetectionInt` - Checking for a motion in the detection range of the radar sensor in interrupt mode.

All Arduino sketches are also available for the other included platforms. See below :code:`src/framework/PLATFORM` directory.

Descriptions
------------

directionDetection
""""""""""""""""""
This example shows how you can use the :code:`BGT60` radar shield to determine the direction of the detected movement. Here we just simply call the :code:`getDirection()` function continuously in the loop to check the direction of the motion. Following you can see the different steps of the example:

First we create an object of the :code:`BGT60` class.
Afterwards we call the initialization function of the class :code:`init()`.
Then we create a variable of the internal direction type :code:`Direction_t` where we can store the value of the direction.
Now we call the function to readout the direction pin :code:`getDirection()`.
Depending on the status of the :code:`Direction_t` variable we print a corresponding message in the serial monitor.
The three previous steps are continuously repeated in the loop.

motionDetection
"""""""""""""""
This example shows how you can use the BGT60 radar shield to check if motion is present in front of the sensor. Here we just simply call the :code:`getMotion()` function continuously in the loop to check if a motion was detected or not. Following you can see the different steps of the example:

First we create an object of the :code:`BGT60` class.
Afterwards we call the initialization function of the class :code:`init()`.
Then we create a variable of the internal motion type :code:`Motion_t` where we can store the value of the motion.
Now we call the function to readout the target pin :code:`getMotion()`.
Depending on the status of the :code:`Motion_t` variable we print a corresponding message in the serial monitor.
The three previous steps are continuously repeated in the loop.

interruptMode
"""""""""""""
This example shows how to use the interrupt functionality of the library. In order to use the interrupts you have to call the :code:`enableInterrupt()` function and pass a callback-function to it. Following you can see the different steps of the example:

First we create an object of the :code:`BGT60` class.
Now we create a user-defined callback function which is just setting a flag when one of the interrupts occurred.
Afterwards we call the initialization function of the class :code:`init()`.
Then we create variables of the internal types for motion :code:`Motion_t` and direction :code:`Direction_t` to store their values.
Now we are checking for a set flag. If the flag is set we first read the corresponding pin for the motion detection :code:`getMotion()` and check if motion was detected or not. And then we try to determine the direction of the motion with the :code:`getDirection()` function. Afterwards the flag is reset. In case the flag is not set we do nothing and skip the functions.
The previous step is continuously repeated in the loop.