TODO: content needs to be updated

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
         - MKR1000
         - Arduino IDE or PlatformIO
         - \*.ino
         - yes
       * - Infineon XMC
         - XMC1100 Boot Kit
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
    
    Supported MCU Platforms
    -----------------------
    
    Verified MCU Platforms
    """"""""""""""""""""""
    
    The library examples have been built and successfully executed on the following platforms:
    
    * `XMC1100 Boot Kit`_
    * `XMC4700 Relax Kit`_
    * `Arduino Uno Rev3`_
    * `Arduino MKR1000`_
    
    .. _`XMC1100 Boot Kit`: https://www.infineon.com/cms/en/product/evaluation-boards/kit_xmc11_boot_001/#ispnTab1
    .. _`XMC4700 Relax Kit`: https://www.infineon.com/cms/en/product/evaluation-boards/kit_xmc47_relax_5v_ad_v1/
    .. _`Arduino Uno Rev3`: https://store.arduino.cc/arduino-uno-rev3
    .. _`Arduino MKR1000`: https://store.arduino.cc/arduino-mkr1000-wifi-with-headers-mounted
    
    Other MCU platforms
    """""""""""""""""""