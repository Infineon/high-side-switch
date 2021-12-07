
.. _program_listing_file_src_corelib_hss-shield.hpp:

Program Listing for File hss-shield.hpp
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_hss-shield.hpp>` (``src\corelib\hss-shield.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_SHIELD_HPP_
   #define HSS_SHIELD_HPP_
   
   #include "hss-types.hpp"
   #include <stdint.h>
   
   using namespace hss;
   
   class HssShield
   {
       public:
           
           virtual             ~HssShield(){};
           virtual Error_t      init()   = 0;
           virtual Error_t      deinit() = 0;
           virtual Error_t      switchHxOn (uint8_t x) = 0;
           virtual Error_t      switchHxOff(uint8_t x) = 0;
           virtual DiagStatus_t readDiagx  (uint8_t x) = 0;
           virtual float        readIsx    (uint8_t x) = 0;
   };
   
   #endif 
