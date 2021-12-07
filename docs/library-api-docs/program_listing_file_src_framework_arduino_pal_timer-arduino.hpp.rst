
.. _program_listing_file_src_framework_arduino_pal_timer-arduino.hpp:

Program Listing for File timer-arduino.hpp
==========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_pal_timer-arduino.hpp>` (``src\framework\arduino\pal\timer-arduino.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef TIMER_ARDUINO_HPP_
   #define TIMER_ARDUINO_HPP_
   
   #include "timer.hpp"
   
   class TimerIno: virtual public Timer
   {
       public:
           TimerIno();
           ~TimerIno();
           Error_t init();
           Error_t deinit();
           Error_t start();
           Error_t elapsed(uint32_t &elapsed);
           Error_t stop();
           Error_t delayMilli(uint32_t timeout);
           Error_t delayMicro(uint32_t timeout);
   
       private:
           uint32_t startTime;
   };
   #endif 
