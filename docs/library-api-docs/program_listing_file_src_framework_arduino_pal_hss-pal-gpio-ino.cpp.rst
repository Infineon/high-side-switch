
.. _program_listing_file_src_framework_arduino_pal_hss-pal-gpio-ino.cpp:

Program Listing for File hss-pal-gpio-ino.cpp
=============================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_pal_hss-pal-gpio-ino.cpp>` (``src\framework\arduino\pal\hss-pal-gpio-ino.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include <Arduino.h>
   #include "hss-pal-gpio-ino.hpp"
   
   GPIOIno::GPIOIno() : pin(0), mode(OUTPUT), logic(POSITIVE)
   {
   
   }
   
   GPIOIno::GPIOIno(uint8_t pin, uint8_t mode, VLogic_t logic)
   : pin(pin), mode(mode), logic(logic)
   {
   
   }
   
   Error_t GPIOIno::init()
   {
       pinMode(this->pin, this->mode);
       return OK;
   }
   
   Error_t GPIOIno::deinit()
   {
       return OK;
   }
   
   GPIOIno::VLevel_t GPIOIno::read()
   {
       return (VLevel_t) digitalRead(this->pin);
   }
   
   Error_t GPIOIno::write(VLevel_t level)
   {
       digitalWrite(this->pin, level);
       return OK;
   }
   
   Error_t GPIOIno::enable()
   {
       if(this->logic == POSITIVE){
           digitalWrite(this->pin, GPIO_HIGH);
       }
       else if(this->logic == NEGATIVE){
           digitalWrite(this->pin, GPIO_LOW);;
       }
       return OK;
   }
   
   Error_t GPIOIno::disable()
   {
       if(this->logic == POSITIVE){
           digitalWrite(this->pin, GPIO_LOW);
       }
       else if(this->logic == NEGATIVE){
           digitalWrite(this->pin, GPIO_HIGH);
       }
       return OK;
   }
   
   
   
   
   
