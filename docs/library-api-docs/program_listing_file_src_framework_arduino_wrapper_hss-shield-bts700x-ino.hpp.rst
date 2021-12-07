
.. _program_listing_file_src_framework_arduino_wrapper_hss-shield-bts700x-ino.hpp:

Program Listing for File hss-shield-bts700x-ino.hpp
===================================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-shield-bts700x-ino.hpp>` (``src\framework\arduino\wrapper\hss-shield-bts700x-ino.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_SHIELD_BTS700X_INO_HPP_
   #define HSS_SHIELD_BTS700X_INO_HPP_
   
   #include "hss-arduino.hpp"
   #include "hss-shield-bts700x.hpp"
   #include "hss-variants.hpp"
   #include "hss-shield-platf.hpp"
   
   using namespace hss;
   
   class Bts700xShieldIno : public Bts700xShield
   {
       public:
                           Bts700xShieldIno(BtxVariants_t *variantSel);
                           Bts700xShieldIno(BtxVariants_t *variantSel, Bts700xHwConfig_t config);
                           ~Bts700xShieldIno();
   };
   
   #endif 
