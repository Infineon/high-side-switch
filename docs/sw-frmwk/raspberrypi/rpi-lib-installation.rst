.. _rpi-lib-installation:

Raspberry Pi C++ Library Installation
=====================================

Prerequisites
-------------
We assume that you have already set up a compatible Raspberry Pi with the Raspberry Pi OS or a similar OS and that the hardware setup is already done. If this is not the case, please refer to the `getting started page <rpi-getting-started>`.

Required Software
-----------------
* `Raspberry Pi OS <https://www.raspberrypi.com/software/>`__ or similar
* Git
* build-essential
* Infineon's radar-bgt60 library (this library)

Library Installation
--------------------
The library itself doest not have to be installed. It is sufficient to clone it from GitHub to compile the example code. However, beforehand the required packages have to be installed:

Install required packages

.. code-block:: bash

    sudo apt-get install git build-essential

Clone this library from GitHub

.. code-block:: bash

    git clone https://github.com/Infineon/radar-bgt60

Now the library is ready to go! Continue :ref:`here <rpi-examples>` to find out how the example codes can be compiled and tested.