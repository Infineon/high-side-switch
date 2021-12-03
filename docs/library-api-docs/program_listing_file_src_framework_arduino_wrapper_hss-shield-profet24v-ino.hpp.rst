
.. _program_listing_file_src_framework_arduino_wrapper_hss-shield-profet24v-ino.hpp:

Program Listing for File hss-shield-profet24v-ino.hpp
=====================================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-shield-profet24v-ino.hpp>` (``src\framework\arduino\wrapper\hss-shield-profet24v-ino.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_SHIELD_PROFET24V_INO_HPP_
   #define HSS_SHIELD_PROFET24V_INO_HPP_
   
   #include "hss-arduino.hpp"
   #include "hss-shield-profet24v.hpp"
   #include "hss-variants.hpp"
   #include "hss-shield-platf.hpp"
   
   using namespace hss;
   
   class Profet24VBTTShieldIno : public Profet24VBTTShield
   {
       public:
                           Profet24VBTTShieldIno();
                           Profet24VBTTShieldIno(Profet24VBTTHwConfig_t config);
                           ~Profet24VBTTShieldIno();
   };
   
   #endif 
