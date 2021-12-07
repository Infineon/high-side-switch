
.. _program_listing_file_src_framework_arduino_pal_hss-pal-timer-ino.hpp:

Program Listing for File hss-pal-timer-ino.hpp
==============================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_pal_hss-pal-timer-ino.hpp>` (``src\framework\arduino\pal\hss-pal-timer-ino.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_PAL_TIMER_INO_HPP_
   #define HSS_PAL_TIMER_INO_HPP_
   
   #include "hss-pal-timer.hpp"
   
   using namespace hss;
   
   class TimerIno: virtual public TimerPAL
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
