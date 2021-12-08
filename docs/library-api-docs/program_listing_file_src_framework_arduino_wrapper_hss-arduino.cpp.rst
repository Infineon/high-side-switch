
.. _program_listing_file_src_framework_arduino_wrapper_hss-arduino.cpp:

Program Listing for File hss-arduino.cpp
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-arduino.cpp>` (``src\framework\arduino\wrapper\hss-arduino.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "hss-arduino.hpp"
   #include <Arduino.h>
   
   HssIno::HssIno(uint8_t in, uint8_t is, BtxVariants_t * btxVariant)
   : Hss(nullptr,
         new GPIOIno(in,  OUTPUT, GPIOIno::POSITIVE),
         nullptr,
         nullptr,
         new ADCIno(is),
         new TimerIno(),
         btxVariant)
   {
   
   }
   
   HssIno::HssIno(uint8_t den, uint8_t in, uint8_t is, BtxVariants_t * btxVariant)
   : Hss(new GPIOIno(den, OUTPUT, GPIOIno::POSITIVE),
         new GPIOIno(in,  OUTPUT, GPIOIno::POSITIVE),
         nullptr,
         nullptr,
         new ADCIno(is),
         new TimerIno(),
         btxVariant)
   {
   
   }
   
   HssIno::HssIno(uint8_t den, uint8_t in0, uint8_t in1, uint8_t dsel, uint8_t is, BtxVariants_t * btxVariant)
   : Hss(new GPIOIno(den, OUTPUT, GPIOIno::POSITIVE),
         new GPIOIno(in0,  OUTPUT, GPIOIno::POSITIVE),
         new GPIOIno(in1,  OUTPUT, GPIOIno::POSITIVE),
         new GPIOIno(dsel,  OUTPUT, GPIOIno::POSITIVE),
         new ADCIno(is),
         new TimerIno(),
         btxVariant)
   {
   
   }
   
   HssIno::~HssIno()
   {
       delete den;
       delete in0;
       delete in1;
       delete dsel;
       delete is;
       delete timer;
   }
