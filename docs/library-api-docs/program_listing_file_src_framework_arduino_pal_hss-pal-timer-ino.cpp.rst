
.. _program_listing_file_src_framework_arduino_pal_hss-pal-timer-ino.cpp:

Program Listing for File hss-pal-timer-ino.cpp
==============================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_pal_hss-pal-timer-ino.cpp>` (``src\framework\arduino\pal\hss-pal-timer-ino.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include <Arduino.h>
   #include "hss-pal-timer-ino.hpp"
   
   TimerIno::TimerIno()
   {
   
   }
   
   TimerIno::~TimerIno()
   {
   
   }
   
   Error_t TimerIno::init()
   {
       startTime = 0;
       return OK;
   }
   
   Error_t TimerIno::deinit()
   {
       startTime = 0;
       return OK;
   }
   
   Error_t TimerIno::start()
   {
       startTime = millis();
       return OK;
   }
   
   Error_t TimerIno::elapsed(uint32_t &elapsed)
   {
       elapsed = millis() - startTime;
       return OK;
   }
   
   Error_t TimerIno::stop()
   {
       startTime = 0;
       return OK;
   }
   
   Error_t TimerIno::delayMilli(uint32_t timeout)
   {
       delay(timeout);
       return OK;
   }
   
   Error_t TimerIno::delayMicro(uint32_t timeout)
   {
       delayMicroseconds(timeout);
       return OK;
   }
   
