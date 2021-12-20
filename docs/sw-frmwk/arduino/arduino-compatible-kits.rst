.. _arduino-compatible-kits:

Arduino Compatible Kits
=======================

This library is designed for multiple platforms with Arduino Uno compatible headers and different SDKs. The following hardware platforms are compatible and tested:

.. list-table::
    :header-rows: 1

    * - Hardware Platform
      - Type
      - SDK
      - File Marker
      - Checked
    * - Arduino
      - Uno
      - Arduino IDE or PlatformIO
      - \*.ino
      - yes
    * - Arduino
      - Mega
      - Arduino IDE or PlatformIO
      - \*.ino
      - yes
    * - Infineon XMC
      - XMC4700 Relax Kit
      - Arduino IDE or PlatformIO
      - \*.ino
      - yes
    
Any MCU platform which has an Arduino port like the `XMC for Arduino`_ should work (this is not tested) with this shield by using the default Arduino platform.

.. _`XMC for Arduino`: https://github.com/Infineon/XMC-for-Arduino