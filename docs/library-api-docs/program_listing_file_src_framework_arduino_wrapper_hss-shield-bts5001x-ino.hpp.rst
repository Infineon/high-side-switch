
.. _program_listing_file_src_framework_arduino_wrapper_hss-shield-bts5001x-ino.hpp:

Program Listing for File hss-shield-bts5001x-ino.hpp
====================================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-shield-bts5001x-ino.hpp>` (``src\framework\arduino\wrapper\hss-shield-bts5001x-ino.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_SHIELD_BTS5001X_INO_HPP_
   #define HSS_SHIELD_BTS5001X_INO_HPP_
   
   #include "hss-arduino.hpp"
   #include "hss-shield-bts5001x.hpp"
   #include "hss-variants.hpp"
   #include "hss-shield-platf.hpp"
   
   namespace hss
   {
   
   class Bts5001xShieldIno : public Bts5001xShield
   {
       public:
                           Bts5001xShieldIno(BtxVariants_t *variantSel);
                           Bts5001xShieldIno(BtxVariants_t *variantSel, BTS5001xHwConfig_t config);
                           ~Bts5001xShieldIno();
   
   };
   
   }
   
   #endif 
