.. _rpi-py-api:

Raspberry Pi Python API
=======================

Basic API Usage
---------------
Full documentation `here <https://infineon.github.io/radar-bgt60/d2/d1d/group__rpiApi.html>`__.

Create An Object From The :code:`Bgt60Rpi` class
""""""""""""""""""""""""""""""""""""""""""""""""
To create an object of the radar class you can use the following line of code, which will call the constructor of the class:

.. code:: python
    
    radar = bgt60_py.Bgt60Rpi(TD, PD)

This is creating an object of the :code:`Bgt60Rpi` class with the name radar. This name is just a proposal. The instance of the class can be named how ever you want it.

Initialize The Radar
""""""""""""""""""""
To initialize all the necessary peripherals of the shield, you can call the init-function of the class as following:

.. code:: python

    radar.init()

Now the hardware is set up and you're able to start sensing.

Detecting Motion
""""""""""""""""
In order to check if the radar sensor detects motion we have the following function:

.. code:: python
    
    radar.getMotion(motion)

This function checks the actual state of the target-detect-pin and returns, depending on its state, the status of the radar, which means either a :code:`MOTION` or :code:`NO_MOTION` was detected. This function has to be called at the time the user wants to get the information.

Determining The Direction
"""""""""""""""""""""""""
In order to determine the direction relative to the sensor of the detected motion the following function can be used:

.. code:: python
    
    radar.getDirection(direction)

This function checks the actual state of the phase-detect-pin and returns, depending on its state, the status of the radar, which means either an :code:`APPROACHING`, a :code:`DEPARTING` or no direction :code:`NO_DIR` was determined. This function has to be called at the time the user wants to get the information.

.. warning::
    The determined direction is only valid if also a motion was detected. Therefore, the function :code:`getDirection()` will always return :code:`NO_DIR` as long as no motion was detected, even though the direction LED on the BGT60LTR11AIP shield is on.

Attach A User Defined Callback-Function
"""""""""""""""""""""""""""""""""""""""
The user has the opportunity to attach user defined callback-function. This can be done with the following function:

.. code:: python

    radar.enableInterrupt(cback)

In this function we attach the callback-function passed as argument to both pins, so the target- and phase-pin. In case the sensor detects motion or stops to detect motion the function will be triggered. Also a change of direction, so a change at the phase-pin will trigger the callback-function. This means you can be sure that either the motion "state" or the direction of the motion has changed and you can perform what ever you like in the callback-function. For example you can set a flag which indicates that something has changed and then depending on this flag check the state of the radar with the corresponding functions.