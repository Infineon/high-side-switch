
.. _program_listing_file_src_framework_arduino_pal_adc-arduino.hpp:

Program Listing for File adc-arduino.hpp
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_pal_adc-arduino.hpp>` (``src\framework\arduino\pal\adc-arduino.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef ADC_ARDUINO_H_
   #define ADC_ARDUINO_H_
   
   #include "hss.hpp"
   
   class ADCIno : virtual public AnalogDigitalConverter
   {
       private:
       uint8_t pin;
   
       public:
                   ADCIno();
                   ADCIno(uint8_t pin);
                   ~ADCIno();
       Error_t     init();
       Error_t     deinit();
       Error_t     enable();
       Error_t     disable();
       Error_t     setReadResolution(uint8_t resolution);
       Error_t     setWriteResolution(uint8_t resolution);
       uint16_t    ADCRead();
       Error_t     ADCWrite(uint8_t value);
   };
   #endif 
