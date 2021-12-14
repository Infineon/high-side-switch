
.. _program_listing_file_src_framework_arduino_wrapper_hss-shield-btt60xx-ino.hpp:

Program Listing for File hss-shield-btt60xx-ino.hpp
===================================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-shield-btt60xx-ino.hpp>` (``src\framework\arduino\wrapper\hss-shield-btt60xx-ino.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_SHIELD_BTT60XX_INO_HPP_
   #define HSS_SHIELD_BTT60XX_INO_HPP_
   
   #include "hss-arduino.hpp"
   #include "hss-shield-btt60xx.hpp"
   #include "hss-variants.hpp"
   #include "hss-shield-platf.hpp"
   
   namespace hss
   {
   
   class Btt60xxShieldIno : public Btt60xxShield
   {
       public:
                           Btt60xxShieldIno();
                           Btt60xxShieldIno(Btt60xxHwConfig_t config);
                           ~Btt60xxShieldIno();
   };
   
   }
   
   #endif 
