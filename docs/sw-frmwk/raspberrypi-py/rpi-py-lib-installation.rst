.. _rpi-py-lib-installation:

Raspberry Pi Python Library Installation
========================================

Prerequisites
-------------
We assume that you have already set up a compatible Raspberry Pi with the Raspberry Pi OS or a similar OS and that the hardware setup is already done. If this is not the case, please refer to the :ref:`getting started page <rpi-py-getting-started>`.

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

Library Installation
--------------------
This library can be installed easily using :code:`pip`. If you do not have :code:`pip` installed please do so by typing

.. code-block:: bash

    sudo apt-get install python3-pip

into the command line of your Raspberry Pi. Afterwards you can install the Infineon BGT60 Radar Library by typing

.. code-block:: bash

    sudo pip3 install radar-bgt60

The corresponding PyPI package can be found `here <https://pypi.org/project/radar-bgt60/>`__.