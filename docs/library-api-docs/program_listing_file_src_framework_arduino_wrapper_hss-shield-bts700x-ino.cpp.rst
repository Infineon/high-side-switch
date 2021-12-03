
.. _program_listing_file_src_framework_arduino_wrapper_hss-shield-bts700x-ino.cpp:

Program Listing for File hss-shield-bts700x-ino.cpp
===================================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-shield-bts700x-ino.cpp>` (``src\framework\arduino\wrapper\hss-shield-bts700x-ino.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "hss-shield-bts700x-ino.hpp"
   #include <Arduino.h>
   
   using namespace hss;
   
   Bts700xShieldIno::Bts700xShieldIno(BtxVariants_t *variantSel):
   Bts700xShield   (   led1 = ((BTS700X_HWCONFIG.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS700X_HWCONFIG.led1, OUTPUT, GPIOIno::POSITIVE)),
                       led2 = ((BTS700X_HWCONFIG.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS700X_HWCONFIG.led2, OUTPUT, GPIOIno::POSITIVE)),
                       led3 = ((BTS700X_HWCONFIG.led3 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS700X_HWCONFIG.led3, OUTPUT, GPIOIno::POSITIVE)),
                       led4 = ((BTS700X_HWCONFIG.led4 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS700X_HWCONFIG.led4, OUTPUT, GPIOIno::POSITIVE)),
                       hss1 = new HssIno(BTS700X_HWCONFIG.den1_den3, BTS700X_HWCONFIG.in1, BTS700X_HWCONFIG.is1_is2, variantSel),
                       hss2 = new HssIno(BTS700X_HWCONFIG.den2_den4, BTS700X_HWCONFIG.in2, BTS700X_HWCONFIG.is1_is2, variantSel),
                       hss3 = new HssIno(BTS700X_HWCONFIG.den1_den3, BTS700X_HWCONFIG.in3, BTS700X_HWCONFIG.is3_is4, variantSel),
                       hss4 = new HssIno(BTS700X_HWCONFIG.den2_den4, BTS700X_HWCONFIG.in4, BTS700X_HWCONFIG.is3_is4, variantSel),
                       timer = new TimerIno(),
                       oloff = new GPIOIno(BTS700X_HWCONFIG.oloff, OUTPUT, GPIOIno::POSITIVE),
                       pushButtonDigital = new GPIOIno(BTS700X_HWCONFIG.pushButtonDigital, INPUT_PULLUP, GPIOIno::POSITIVE),
                       pushButtonAnalog = new ADCIno(BTS700X_HWCONFIG.pushButtonAnalog),
                       vBat = new ADCIno(BTS700X_HWCONFIG.vBat),
                       btxVariant = variantSel
                   )
   {
   
   }
   
   Bts700xShieldIno::Bts700xShieldIno(BtxVariants_t *variantSel, Bts700xHwConfig_t config):
   Bts700xShield   (   led1 = ((config.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led1, OUTPUT, GPIOIno::POSITIVE)),
                       led2 = ((config.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led2, OUTPUT, GPIOIno::POSITIVE)),
                       led3 = ((config.led3 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led3, OUTPUT, GPIOIno::POSITIVE)),
                       led4 = ((config.led4 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led4, OUTPUT, GPIOIno::POSITIVE)),
                       hss1 = new HssIno(config.den1_den3, config.in1, config.is1_is2, variantSel),
                       hss2 = new HssIno(config.den2_den4, config.in2, config.is1_is2, variantSel),
                       hss3 = new HssIno(config.den1_den3, config.in3, config.is3_is4, variantSel),
                       hss4 = new HssIno(config.den2_den4, config.in4, config.is3_is4, variantSel),
                       timer = new TimerIno(),
                       oloff = new GPIOIno(config.oloff, OUTPUT, GPIOIno::POSITIVE),
                       pushButtonDigital = new GPIOIno(config.pushButtonDigital, INPUT_PULLUP, GPIOIno::POSITIVE),
                       pushButtonAnalog = new ADCIno(config.pushButtonAnalog),
                       vBat = new ADCIno(config.vBat),
                       btxVariant = variantSel
                   )
   {
   
   }
   
   Bts700xShieldIno::~Bts700xShieldIno()
   {
   
   }
