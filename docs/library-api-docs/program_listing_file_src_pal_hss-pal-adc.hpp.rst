
.. _program_listing_file_src_pal_hss-pal-adc.hpp:

Program Listing for File hss-pal-adc.hpp
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_pal_hss-pal-adc.hpp>` (``src\pal\hss-pal-adc.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_PAL_ADC_HPP_
   #define HSS_PAL_ADC_HPP_
   
   #include <stdint.h>
   #include "hss-types.hpp"
   
   namespace hss
   {
   
   class ADCPAL
   {
       public:
   
           virtual Error_t     init() = 0;
   
           virtual Error_t     deinit() = 0;
   
           virtual Error_t     enable() = 0;
   
           virtual Error_t     disable() = 0;
   
           virtual Error_t     setReadResolution(uint8_t resolution) = 0;
   
           virtual Error_t     setWriteResolution(uint8_t resolution) = 0;
   
           virtual uint16_t    ADCRead() = 0;
   
           virtual Error_t     ADCWrite(uint8_t value) = 0;
   
   };
   
   }
   
   #endif 
