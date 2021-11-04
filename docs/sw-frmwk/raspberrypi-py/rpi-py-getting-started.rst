.. _rpi-py-getting-started:

Raspberry Pi Getting Started (Python)
=====================================

Overview
--------

In this quick tutorial we will go through one of the BGT60 Python library examples available for the BGT60LTR11AIP shield and the Raspberry Pi.

Required Experience
-------------------

* Experience level: moderate
* Basic Linux user level
* Basic programming skills (Python)
* Basic soldering skills (recommended)

Required Hardware
-----------------

Raspberry Pi
"""""""""""""""
For example `Raspberry Pi 4 <https://www.raspberrypi.org/products/raspberry-pi-4-model-b/>`__ or any other Raspberry Pi.

.. image:: ../../img/raspberry_pi_4.png
    :width: 300

Radar Shield
""""""""""""
`BGT60LTR11AIP  <https://www.infineon.com/cms/en/product/evaluation-boards/demo-bgt60ltr11aip/>`__ 60 GHz Radar Shield from Infineon.

.. image:: ../../img/bgt60-without-background.png
    :width: 300

Accessories
"""""""""""

* Pin headers
* 8 GB or larger microSD card for the Raspberry Pi
* female-female jumper wires

Required Software
-----------------

* Raspberry Pi OS or similar
* Git
* build-essential
* `bcm2835 library <https://www.airspayce.com/mikem/bcm2835/>`__
* `pybind11 library <https://pybind11.readthedocs.io/en/stable/basics.html>`__
* Python 3 (tested with :code:`python3.7`)
* pip (for easy installation)
* Infineon's radar-bgt60 library (this library)

Tutorial
--------

Hardware Setup
""""""""""""""

The BGT60 needs to be connected with wires to a Raspberry Pi (we recommend Raspberry Pi 4). One wiring example is depicted below. If you want to use different pins, you have have to change the desired pins in the constructor of the :code:`Bgt60` class.

.. image:: ../../img/rpi_wiring.png
    :width: 600

.. warning::
    Make sure to connect the GND-Pin and the VIN-Pin of the radar shield to the right pins of the Raspberry Pi (GND and 3.3V, respectively). Otherwise the board can be damaged.

Raspberry Pi Setup
""""""""""""""""""
Set up the Raspberry Pi with the Raspberry Pi OS or a similar OS. Check `this page <https://www.raspberrypi.org/downloads/>`__ for instructions.
You can access your Raspberry Pi either using a monitor and a keyboard or using SSH in a headless setup as described `here <https://www.raspberrypi.org/documentation/configuration/wireless/headless.md>`__.
Now insert the microSD card into your Raspberry Pi and turn on the power supply to boot it up.

Software Installation
"""""""""""""""""""""

Check out :ref:`this section <rpi-py-lib-installation>` for details on the installation of the radar-bgt60 library.

Ready to Go!
""""""""""""

With everything ready and set up, we can now run one the library examples.

Clone the repository

.. code-block:: bash
    
    git clone https://github.com/Infineon/radar-bgt60.git

Navigate to the example folder

.. code-block:: bash

    cd radar-bgt60/src/framework/raspberrypi/examples_py

Change into the Raspberry Pi framework folder

.. code-block:: bash

    cd radar-bgt60/src/framework/raspberrypi

and execute the examples from the terminal:

.. code-block:: bash

    python3 detectMotion.py

Run the example code

.. code-block:: bash

    ../../../build/detectMotion

You setup is now able to detect motions in front of the radar board. Check out :ref:`this section <rpi-py-examples>` for more examples.