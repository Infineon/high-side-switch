
.. _program_listing_file_src_framework_arduino_pal_timer-arduino.cpp:

Program Listing for File timer-arduino.cpp
==========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_pal_timer-arduino.cpp>` (``src\framework\arduino\pal\timer-arduino.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include <Arduino.h>
   #include "timer-arduino.hpp"
   
   TimerIno::TimerIno()
   {
   
   }
   
   TimerIno::~TimerIno()
   {
   
   }
   
   TimerIno::Error_t TimerIno::init()
   {
       startTime = 0;
       return OK;
   }
   
   TimerIno::Error_t TimerIno::deinit()
   {
       startTime = 0;
       return OK;
   }
   
   TimerIno::Error_t TimerIno::start()
   {
       startTime = millis();
       return OK;
   }
   
   TimerIno::Error_t TimerIno::elapsed(uint32_t &elapsed)
   {
       elapsed = millis() - startTime;
       return OK;
   }
   
   TimerIno::Error_t TimerIno::stop()
   {
       startTime = 0;
       return OK;
   }
   
   TimerIno::Error_t TimerIno::delayMilli(uint32_t timeout)
   {
       delay(timeout);
       return OK;
   }
   
   TimerIno::Error_t TimerIno::delayMicro(uint32_t timeout)
   {
       delayMicroseconds(timeout);
       return OK;
   }
   
