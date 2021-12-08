
.. _program_listing_file_src_framework_arduino_pal_gpio-arduino.cpp:

Program Listing for File gpio-arduino.cpp
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_pal_gpio-arduino.cpp>` (``src\framework\arduino\pal\gpio-arduino.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include <Arduino.h>
   #include "gpio-arduino.hpp"
   
   GPIOIno::GPIOIno() : pin(0), mode(OUTPUT), logic(POSITIVE)
   {
   
   }
   
   GPIOIno::GPIOIno(uint8_t pin, uint8_t mode, VLogic_t logic)
   : pin(pin), mode(mode), logic(logic)
   {
   
   }
   
   GPIOIno::Error_t GPIOIno::init()
   {
       pinMode(this->pin, this->mode);
       return OK;
   }
   
   GPIOIno::Error_t GPIOIno::deinit()
   {
       return OK;
   }
   
   GPIOIno::VLevel_t GPIOIno::read()
   {
       return (VLevel_t) digitalRead(this->pin);
   }
   
   GPIOIno::Error_t GPIOIno::write(VLevel_t level)
   {   
       digitalWrite(this->pin, level);    
       return OK;
   }
   
   GPIOIno::Error_t GPIOIno::enable()
   {
       if(this->logic == POSITIVE){
           digitalWrite(this->pin, GPIO_HIGH);
       }
       else if(this->logic == NEGATIVE){
           digitalWrite(this->pin, GPIO_LOW);;
       }
       return OK;
   }
   
   GPIOIno::Error_t GPIOIno::disable()
   {
       if(this->logic == POSITIVE){
           digitalWrite(this->pin, GPIO_LOW);
       }
       else if(this->logic == NEGATIVE){
           digitalWrite(this->pin, GPIO_HIGH);
       }
       return OK;
   }
   
   
   
   
   
