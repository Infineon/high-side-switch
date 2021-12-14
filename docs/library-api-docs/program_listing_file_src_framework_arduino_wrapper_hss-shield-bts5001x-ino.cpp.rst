
.. _program_listing_file_src_framework_arduino_wrapper_hss-shield-bts5001x-ino.cpp:

Program Listing for File hss-shield-bts5001x-ino.cpp
====================================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-shield-bts5001x-ino.cpp>` (``src\framework\arduino\wrapper\hss-shield-bts5001x-ino.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "hss-shield-bts5001x-ino.hpp"
   #include <Arduino.h>
   
   using namespace hss;
   
   Bts5001xShieldIno::Bts5001xShieldIno(BtxVariants_t *variantSel):
   Bts5001xShield(hss1 = new HssIno(BTS5001X_HWCONFIG.in, BTS5001X_HWCONFIG.is, variantSel),
                  led2 = ((BTS5001X_HWCONFIG.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS5001X_HWCONFIG.led2, OUTPUT, GPIOIno::POSITIVE)),
                  led3 = ((BTS5001X_HWCONFIG.led3 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS5001X_HWCONFIG.led3, OUTPUT, GPIOIno::POSITIVE)),
                  pushButton = new ADCIno(BTS5001X_HWCONFIG.pushButtonAnalog),
                  vBat = new ADCIno(BTS5001X_HWCONFIG.vBat))
   {
   
   }
   
   Bts5001xShieldIno::Bts5001xShieldIno(BtxVariants_t *variantSel, BTS5001xHwConfig_t config):
   Bts5001xShield(hss1 = new HssIno(config.in, config.is, variantSel),
                  led2 = ((config.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led2, OUTPUT, GPIOIno::POSITIVE)),
                  led3 = ((config.led3 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led3, OUTPUT, GPIOIno::POSITIVE)),
                  pushButton = new ADCIno(config.pushButtonAnalog),
                  vBat = new ADCIno(config.vBat))
   {
   
   }
   
   
   Bts5001xShieldIno::~Bts5001xShieldIno()
   {
   
   }
   
