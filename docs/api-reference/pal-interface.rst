.. _pal-intf:

Platform Abstraction Layer Interface
------------------------------------

The high side switch library requires ADCs, GPIOs and timer resources from the platform.
These are implemented in terms of the following abstract class APIs for each supporteed software framework:

- :ref:`ADC PAL`
- :ref:`GPIO PAL`
- :ref:`Timer PAL`

Their member parameters and functions are described in this section.

.. _ADC PAL:

ADC PAL
"""""""

.. doxygenclass:: hss::ADCPAL
   :members:

.. _GPIO PAL:

GPIO PAL
""""""""
.. doxygenclass:: hss::GPIOPAL
   :members:

.. _Timer PAL:

Timer PAL
"""""""""

.. doxygenclass:: hss::TimerPAL
   :members: