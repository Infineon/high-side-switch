.. _rpi-py-examples:

Raspberry Pi Examples (Python)
==============================

The following Python examples are provided for the Raspberry Pi:

.. note::
    Before running these examples make sure that all requirements are installed properly as explained :ref:`here <rpi-py-lib-installation>`.

motionDetection
---------------

Description
"""""""""""
This example shows how to check for motion with the radar sensor. For this we use the simple :code:`getMotion()` function continuously in the loop to check if a motion was detected or not.

Hardware Setup
""""""""""""""
In order to setup the hardware correctly check :ref:`this section <rpi-py-getting-started>`.

Run
"""
.. note::
    Please open the example source file at :code:`src/framework/raspberrypi/examples/motionDetection.py` and read the comments first before compiling it.

Change to the Python examples folder:

.. code-block:: bash
    
    cd src/framework/raspberrypi/examples_py
    
Now you can run the examples code:

.. code-block:: bash
    
    python3 motionDetection.py

directionDetection
------------------

Description
"""""""""""
This example shows how to determine the direction of the detected motion in front of the radar sensor. It uses the :code:`getDirection()` function of the library and is calling it continuously in a loop to check the direction relative to the sensor of the detected motion.

Hardware Setup
""""""""""""""
In order to setup the hardware correctly check :ref:`this section <rpi-py-getting-started>`.

Run
"""
.. note::
    Please open the example source file at :code:`src/framework/raspberrypi/examples/directionDetection.py` and read the comments first before compiling it.

Change to the Python examples folder:

.. code-block:: bash
    
    cd src/framework/raspberrypi/examples_py

Now you can run the examples code:

.. code-block:: bash
    
    python3 motionDetection.py

interruptMode
-------------

Description
"""""""""""
This example shows you how to use the interrupt functionality of the library. Here, you can pass a user defined callback function to the class, which can then be used to check for motion and the direction of the motion.

Hardware Setup
""""""""""""""
In order to setup the hardware correctly check :ref:`this section <rpi-py-getting-started>`.

Run
"""
.. note::
    Please open the example source file at :code:`src/framework/raspberrypi/examples/directionDetection.py` and read the comments first before compiling it.

Change to the Python examples folder:

.. code-block:: bash
    
    cd src/framework/raspberrypi/examples_py

Now you can run the examples code:

.. code-block:: bash
    
    python3 motionDetection.py