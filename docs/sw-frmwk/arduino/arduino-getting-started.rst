.. _arduino-examples:

Arduino Getting Started
=======================

Overview
--------

In this quick tutorial we will go through the installation of the Radar BGT60 library for the Arduino IDE step by step and show you how to run our examples on an Arduino compatible board.

Required Experience
-------------------

* Experience level: beginner
* Basic computer user level
* Basic programming skills (C/C++)
* Basic soldering skills (recommended)

Required Hardware
-----------------

Microcontroller
"""""""""""""""
Arduino MKR1000 or other MKR-boards from Arduino:

.. image:: ../../img/MKR1000.jpg
    :width: 300

or
XMC1100 Boot Kit or other Arduino compatible XMC boards from Infineon:

.. image:: ../../img/XMC1100.jpg
    :width: 300

Radar Shield
""""""""""""

60 GHz Radar Shield

.. image:: ../../img/bgt60-without-background.png
    :width: 300

Accessories
"""""""""""

* Pin headers
* Micro-USB to USB A cable
* For boards which do not have Arduino MKR form-factor: male-female jumper wires

Required Software
-----------------

* `Segger J-Link`_ either for Windows or Linux
* `Arduino IDE`_ either for Windows or Linux
* Installed XMC-for-Arduino for your Arduino IDE (in case you want to use a XMC-Board), for instructions see `here <https://github.com/Infineon/XMC-for-Arduino#installation-instructions>`__
* This library installed in the Arduino IDE, the instructions can be found `here <https://www.arduino.cc/en/guide/libraries>`__

Tutorial
--------

Software Installation
"""""""""""""""""""""

0. **Install the Arduino IDE**. If you are new to Arduino, please `download <https://www.arduino.cc/en/Main/Software>`__ the program and install it first.

1. **Include the XMC boards in the IDE (if a XMC is used)**. The official Arduino boards are already available in the Arduino software, but other third party boards as the Infineon XMC MCU based, need to be explicitly included. Follow the instructions in the `link <https://github.com/Infineon/XMC-for-Arduino#installation-instructions>`__ to add the XMC board family to the Arduino IDE.

2. **Install the library**. In the Arduino IDE, go to the menu *Sketch > Include library > Library Manager*. Type **radar-bgt60** and install the library.

3. **Additional**. Install additionally the Segger J-Link if you use an Infineon XMC1100 BootKit, XMC4700 RelaxKit or any other Arduino compatible XMC-Board.

Hardware Setup
""""""""""""""

The *BGT60* shield needs to be plugged into the right pin-headers in case you're using a MKR-Board from Arduino. In case you want to use the shield with another MCU, like the XMC1100 BootKit, use jumper cables to connect the shield to board.

.. image:: ../../img/Stack_without_background.png
    :width: 400

As soon as you connected the radar to the controller board you can plug in the microUSB-cable into the controller and connect everything to your computer.

Ready To Go!
""""""""""""

With everything ready, we are now going to upload and run one of the library examples.

1. **Example detectMotion**

Take the *detectMotion* example from the *File -> Example -> radar-bgt60 -> detectMotion* menu and compile the example.

Before you can upload the sketch to your desired MCU board you have to chose the right platform. This can be done under *Tools -> Board -> desiredPlatform -> desiredBoard*.

In order to upload the sketch now, you also have chose the right COM-Port. There is really easy way to do this. Unplug your connected MCU and then check the available COM-Ports under *Tool -> Port*. Now connect your MCU again and check the ports again. Now you should see a new one that was not there before. This is the right one.

If everything is set correctly you should be able to upload the code to the board. This can be done in the taskbar via *Sketch -> Upload* or with the arrow symbol in the upper left corner. These both options should upload the sketch to the board.

Now you can open the terminal from the IDE in the upper right corner (symbol of a magnifier). The serial monitor should tell you that the radar shield is initialized after a short time. Now you can move a object in front of the sensor and the monitor should tell you : "Target in motion detected".

2. **Developing you own Sketch**

In case you want to write your own sketch, you can include the library of the 60 GHz radar quite easily. The first option would be to take the one of the already existing examples and change the code as desired. Or you create a completely new sketch.

If you choose the second option you have to include the library first. This can be done via *Sketch -> Include Library -> radar-bgt60*. Now you should see :code:`#include <bgt60-ino.hpp>` in your file. This means the header-file of the library is included and you can use it from now on. You can also just write the same line of code yourself. It is not mandatory to use the taskbar for this.

Now you can create an object of the class with the following line of code:

.. code-block:: cpp

    Bgt60Ino radar(TD, PD);

The first argument is the tDet pin, and the second the pDet pin. If you are using one of the default platform configurations, these will be already set in the :code:`btg60-platf-ino.hpp` file. You just need include it in your sketch.

With this class you now have access to all the public functions of Arduino API. For more information take a look into the :ref:`Arduino API <arduino-api>` section.


.. _`Segger J-Link`: https://www.segger.com/downloads/jlink
.. _`Arduino IDE`: https://www.arduino.cc/en/main/software