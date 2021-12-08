
.. _program_listing_file_src_framework_arduino_wrapper_hss-arduino.hpp:

Program Listing for File hss-arduino.hpp
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-arduino.hpp>` (``src\framework\arduino\wrapper\hss-arduino.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_ARDUINO_HPP_
   #define HSS_ARDUINO_HPP_
   
   #include "hss.hpp"
   #include "hss-pal-gpio-ino.hpp"
   #include "hss-pal-adc-ino.hpp"
   #include "hss-pal-timer-ino.hpp"
   
   class HssIno : public Hss
   {
       public:
           HssIno(uint8_t in, uint8_t is, BtxVariants_t * btxVariant);
           HssIno(uint8_t den, uint8_t in, uint8_t is, BtxVariants_t * btxVariant);
           HssIno(uint8_t den, uint8_t in0, uint8_t in1, uint8_t dsel, uint8_t is, BtxVariants_t * btxVariant);
           ~HssIno();
   };
   
   #endif 
