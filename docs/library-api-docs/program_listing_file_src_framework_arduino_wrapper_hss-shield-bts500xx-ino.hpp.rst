
.. _program_listing_file_src_framework_arduino_wrapper_hss-shield-bts500xx-ino.hpp:

Program Listing for File hss-shield-bts500xx-ino.hpp
====================================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-shield-bts500xx-ino.hpp>` (``src\framework\arduino\wrapper\hss-shield-bts500xx-ino.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_SHIELD_BTS500XX_INO_HPP_
   #define HSS_SHIELD_BTS500XX_INO_HPP_
   
   #include "hss-arduino.hpp"
   #include "hss-shield-bts500xx.hpp"
   #include "hss-variants.hpp"
   #include "hss-shield-platf.hpp"
   
   using namespace hss;
   
   class Bts500xxShieldIno : public Bts500xxShield
   {
       public:
                           Bts500xxShieldIno(BtxVariants_t *variantSel);
                           Bts500xxShieldIno(BtxVariants_t *variantSel, BTS500xxHwConfig_t config);
                           ~Bts500xxShieldIno();
   
   };
   
   #endif 
