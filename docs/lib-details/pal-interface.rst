PAL Interface
=============

The interaction with the hardware and platform resources is abstracted from the core library by the definition of a platform abstraction interface.

For this shield, the platform resources that need to be provided are the following:

* **GPIO**: Digital input and output ports.
* **Timer**: A timer for speed calculation related functionalities.

The PAL interfaces are implemented as C++ pure virtual classes.

GPIO PAL API
""""""""""""

* init()
* deinit()
* enableInt()
* disableInt()
* intEvent()
* read()
* write()
* enable()
* disable()

Find the complete specification for each function of the Timer PAL interface in the `PAL Interface`_ Doxygen docs section.

Timer PAL API
"""""""""""""

* init()
* deinit()
* start()
* elapsed()
* stop()
* delay()
* delayMilli()
* delayMicro()

Find the complete specification for each function of the Timer PAL interface in the `PAL Interface`_ Doxygen docs section.

.. _`PAL Interface`: https://infineon.github.io/radar-bgt60/d3/d5d/group__pal.html