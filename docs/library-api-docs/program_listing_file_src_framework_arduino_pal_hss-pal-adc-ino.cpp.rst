
.. _program_listing_file_src_framework_arduino_pal_hss-pal-adc-ino.cpp:

Program Listing for File hss-pal-adc-ino.cpp
============================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_pal_hss-pal-adc-ino.cpp>` (``src\framework\arduino\pal\hss-pal-adc-ino.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include <Arduino.h>
   #include "hss-pal-adc-ino.hpp"
   
   ADCIno::ADCIno() : pin(0)
   {
   
   }
   
   ADCIno::ADCIno(uint8_t pin) : pin(pin)
   {
   
   }
   
   ADCIno::~ADCIno()
   {
   
   }
   
   Error_t ADCIno::init()
   {
       return OK;
   }
   
   Error_t ADCIno::deinit()
   {
       return OK;
   }
   
   Error_t ADCIno::enable()
   {
       return OK;
   }
   
   
   Error_t ADCIno::disable()
   {
       return OK;
   }
   
   Error_t ADCIno::setReadResolution(uint8_t resolution)
   {
       // analogReadResolution(resolution);
   
       return OK;
   }
   
   Error_t ADCIno::setWriteResolution(uint8_t resolution)
   {
       // analogWriteResolution(resolution);
   
       return OK;
   }
   
   uint16_t ADCIno::ADCRead()
   {
       uint16_t result = 0;
   
       result = analogRead(pin);
   
       return result;
   }
   
   Error_t ADCIno::ADCWrite(uint8_t value)
   {
       analogWrite(pin, value);
   
       return OK;
   }
   
