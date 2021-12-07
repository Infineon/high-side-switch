
.. _program_listing_file_src_framework_arduino_wrapper_hss-board-arduino.cpp:

Program Listing for File hss-board-arduino.cpp
==============================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-board-arduino.cpp>` (``src\framework\arduino\wrapper\hss-board-arduino.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "Arduino.h"
   #include "hss-board-arduino.hpp"
   
   HssBoardIno::HssBoardIno(BtsVariants_t *variantSel)
   {
       led1 = ((ARDUINO_UNO.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(ARDUINO_UNO.led1, OUTPUT, GPIOIno::POSITIVE));
       led2 = ((ARDUINO_UNO.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(ARDUINO_UNO.led2, OUTPUT, GPIOIno::POSITIVE));
       led3 = ((ARDUINO_UNO.led3 == GPIOIno::unusedPin) ? NULL : new GPIOIno(ARDUINO_UNO.led3, OUTPUT, GPIOIno::POSITIVE));
       led4 = ((ARDUINO_UNO.led4 == GPIOIno::unusedPin) ? NULL : new GPIOIno(ARDUINO_UNO.led4, OUTPUT, GPIOIno::POSITIVE));
   
       hss1 = new HssIno(ARDUINO_UNO.den1_den3, ARDUINO_UNO.in1, ARDUINO_UNO.is1_is2, variantSel);
       hss2 = new HssIno(ARDUINO_UNO.den2_den4, ARDUINO_UNO.in2, ARDUINO_UNO.is1_is2, variantSel);
       hss3 = new HssIno(ARDUINO_UNO.den1_den3, ARDUINO_UNO.in3, ARDUINO_UNO.is3_is4, variantSel);
       hss4 = new HssIno(ARDUINO_UNO.den2_den4, ARDUINO_UNO.in4, ARDUINO_UNO.is3_is4, variantSel);
   
       timer = new TimerIno();
       
       oloff = new GPIOIno(ARDUINO_UNO.oloff, OUTPUT, GPIOIno::POSITIVE);
       pushButtonDigital = new GPIOIno(ARDUINO_UNO.pushButtonDigital, INPUT_PULLUP, GPIOIno::POSITIVE);
   
       pushButtonAnalog = new ADCIno(ARDUINO_UNO.pushButtonAnalog);
       vBat = new ADCIno(ARDUINO_UNO.vBat);
   }
   
   HssBoardIno::HssBoardIno(BtsVariants_t *variantSel, hardwareconfig_t config)
   {
       led1 = ((config.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led1, OUTPUT, GPIOIno::POSITIVE));
       led2 = ((config.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led2, OUTPUT, GPIOIno::POSITIVE));
       led3 = ((config.led3 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led3, OUTPUT, GPIOIno::POSITIVE));
       led4 = ((config.led4 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led4, OUTPUT, GPIOIno::POSITIVE));
   
       hss1 = new HssIno(config.den1_den3, config.in1, config.is1_is2, variantSel);
       hss2 = new HssIno(config.den2_den4, config.in2, config.is1_is2, variantSel);
       hss3 = new HssIno(config.den1_den3, config.in3, config.is3_is4, variantSel);
       hss4 = new HssIno(config.den2_den4, config.in4, config.is3_is4, variantSel);
   
       timer = new TimerIno();
   
       oloff = new GPIOIno(config.oloff, OUTPUT, GPIOIno::POSITIVE);
       pushButtonDigital = new GPIOIno(config.pushButtonDigital, INPUT_PULLUP, GPIOIno::POSITIVE);
       
       pushButtonAnalog = new ADCIno(config.pushButtonAnalog);
       vBat =  new ADCIno(config.vBat);
   }
   
   HssBoardIno::~HssBoardIno()
   {
   
   }
   
   
   
