
.. _program_listing_file_src_pal_timer.hpp:

Program Listing for File timer.hpp
==================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_pal_timer.hpp>` (``src\pal\timer.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include <stdint.h>
   
   #ifndef TIMER_HPP_
   #define TIMER_HPP_
   
   class Timer
   {
       public:
   
           enum Error_t
           {
               OK          =  0,    
               INTF_ERROR  = -1,    
               CONF_ERROR  = -2,    
           };
   
           virtual  Error_t         init    () = 0;
   
           virtual  Error_t         deinit   () = 0;
   
           virtual  Error_t         start   () = 0;
   
           virtual  Error_t         elapsed (uint32_t &elapsed) = 0;
           
           virtual  Error_t         stop    () = 0;
           
           virtual  Error_t        delayMilli (uint32_t timeout) = 0;
           
           virtual  Error_t        delayMicro  (uint32_t timeout) = 0;
   };
   
   #endif 
