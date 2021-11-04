.. _rpi-examples:

Raspberry Pi Examples
=====================

The following examples are provided for the Raspberry Pi:

.. note::
    Before running these examples make sure that all requirements are installed properly as explained :ref:`here <rpi-lib-installation>`.

motionDetection
---------------

Description
"""""""""""
This example shows how to check for motion with the radar sensor. For this we use the simple :code:`getMotion()` function continuously in the loop to check if a motion was detected or not.

Hardware Setup
""""""""""""""
In order to setup the hardware correctly check :ref:`this section <rpi-getting-started>`.

Compile
"""""""
.. note::
    Please open the example source file at :code:`src/framework/raspberrypi/examples/motionDetection.cpp` and read the comments first before compiling it.

Change to the Raspberry Pi framework folder:

.. code-block:: bash
    
    cd src/framework/raspberrypi
    
Clean if any other example was compiled before:

.. code-block:: bash
    
    make clean

Compile the example:

.. code-block:: bash
    
    make examples/motionDetection

Run the example:

.. code-block:: bash
    
    ../../../build/motionDetection

directionDetection
------------------

Description
"""""""""""""
This example shows how to determine the direction of the detected motion in front of the radar sensor. It uses the :code:`getDirection()` function of the library and is calling it continuously in a loop to check the direction relative to the sensor of the detected motion.

Hardware Setup
""""""""""""""
In order to setup the hardware correctly check :ref:`this section <rpi-getting-started>`.

Compile
"""""""
.. note::
    Please open the example source file at :code:`src/framework/raspberrypi/examples/directionDetection.cpp` and read the comments first before compiling it.

Change to the Raspberry Pi framework folder:

.. code-block:: bash
    
    cd src/framework/raspberrypi

Clean if any other example was compiled before:

.. code-block:: bash
    
    make clean

Compile the example:

.. code-block:: bash
    
    make example/directionDetection

Run the example:

.. code-block:: bash
    
    ../../../build/directionDetection

interruptMode
-------------

Description
"""""""""""""
This example shows you how to use the interrupt functionality of the library. Here, you can pass a user defined callback function to the class, which can then be used to check for motion and the direction of the motion.

Hardware Setup
""""""""""""""
In order to setup the hardware correctly check :ref:`this section <rpi-getting-started>`.

Compile
"""""""
.. note::
    Please open the example source file at :code:`src/framework/raspberrypi/examples/directionDetection.cpp` and read the comments first before compiling it.

Change to the Raspberry Pi framework folder:

.. code-block:: bash
    
    cd src/framework/raspberrypi

Clean if any other example was compiled before:

.. code-block:: bash
    
    make clean

Compile the example:

.. code-block:: bash
    
    make examples/interruptMode

Run the example:

.. code-block:: bash
    
    ../../../build/interruptMode