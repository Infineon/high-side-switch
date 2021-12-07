
.. _program_listing_file_src_framework_arduino_pal_adc-arduino.cpp:

Program Listing for File adc-arduino.cpp
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_pal_adc-arduino.cpp>` (``src\framework\arduino\pal\adc-arduino.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include <Arduino.h>
   #include "adc-arduino.hpp"
   
   ADCIno::ADCIno() : pin(0)
   {
   
   }
   
   ADCIno::ADCIno(uint8_t pin) : pin(pin)
   {
       
   }
   
   ADCIno::~ADCIno()
   {
   
   }
   
   ADCIno::Error_t ADCIno::init()
   {
       return OK;
   }
   
   ADCIno::Error_t ADCIno::deinit()
   {
       return OK;
   }
   
   ADCIno::Error_t ADCIno::enable()
   {
       return OK;
   }
   
   
   ADCIno::Error_t ADCIno::disable()
   {
       return OK;
   }
   
   ADCIno::Error_t ADCIno::setReadResolution(uint8_t resolution)
   {
       // analogReadResolution(resolution);
       
       return OK;
   }
   
   ADCIno::Error_t ADCIno::setWriteResolution(uint8_t resolution)
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
   
   ADCIno::Error_t ADCIno::ADCWrite(uint8_t value)
   {
       analogWrite(pin, value);
       
       return OK;
   }
   
