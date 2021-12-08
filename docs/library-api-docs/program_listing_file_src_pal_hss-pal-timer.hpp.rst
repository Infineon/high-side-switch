
.. _program_listing_file_src_pal_hss-pal-timer.hpp:

Program Listing for File hss-pal-timer.hpp
==========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_pal_hss-pal-timer.hpp>` (``src\pal\hss-pal-timer.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include <stdint.h>
   #include "hss-types.hpp"
   
   #ifndef HSS_PAL_TIMER_HPP_
   #define HSS_PAL_TIMER_HPP_
   
   namespace hss
   {
   
   class TimerPAL
   {
       public:
   
           virtual  Error_t         init    () = 0;
   
           virtual  Error_t         deinit   () = 0;
   
           virtual  Error_t         start   () = 0;
   
           virtual  Error_t         elapsed (uint32_t &elapsed) = 0;
   
           virtual  Error_t         stop    () = 0;
   
           virtual  Error_t        delayMilli (uint32_t timeout) = 0;
   
           virtual  Error_t        delayMicro  (uint32_t timeout) = 0;
   
   };
   
   }
   
   #endif 
