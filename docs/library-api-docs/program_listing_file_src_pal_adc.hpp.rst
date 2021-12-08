
.. _program_listing_file_src_pal_adc.hpp:

Program Listing for File adc.hpp
================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_pal_adc.hpp>` (``src\pal\adc.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef AnalogDigitalConverter_HPP_
   #define AnalogDigitalConverter_HPP_
   
   #include <stdint.h>
   
   class AnalogDigitalConverter
   {
       public:
   
           enum Error_t
           {
               OK          =  0,    
               INTF_ERROR  = -1,    
               CONF_ERROR  = -2,    
               READ_ERROR  = -3,    
               WRITE_ERROR = -4,    
           };
   
           virtual Error_t     init() = 0;
           virtual Error_t     deinit() = 0;
           virtual Error_t     enable() = 0;
           virtual Error_t     disable() = 0;
           virtual Error_t     setReadResolution(uint8_t resolution) = 0;
           virtual Error_t     setWriteResolution(uint8_t resolution) = 0;
           virtual uint16_t    ADCRead() = 0;
           virtual Error_t     ADCWrite(uint8_t value) = 0;
           Error_t             checkErrorStatus();
   
           private:
   
           Error_t errorStatus;
   };
   #endif 
