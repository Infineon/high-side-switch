.. _core-lib:

Core library
============

The core library provides 2 base APIs:

- :ref:`Hss API`. Implements a class for high side switch devices.
- :ref:`HssShield API`. Implements an interface for high side switch shields.

The main APIs are derived from the HSS Shield API, as per shield type:

- :ref:`Btt60xxShield API`
- :ref:`Bts5001xShield API`
- :ref:`Bts500xxShield API`
- :ref:`Bts700xShield API`

.. toctree::
    :maxdepth: 3
    :hidden:

    hss-api
    hss-shield-api
    profet-24-api
    power-profet-api
    power-profet-1LUA-api
    profet2-12-api