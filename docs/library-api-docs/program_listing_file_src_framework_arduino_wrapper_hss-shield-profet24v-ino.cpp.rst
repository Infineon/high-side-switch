
.. _program_listing_file_src_framework_arduino_wrapper_hss-shield-profet24v-ino.cpp:

Program Listing for File hss-shield-profet24v-ino.cpp
=====================================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-shield-profet24v-ino.cpp>` (``src\framework\arduino\wrapper\hss-shield-profet24v-ino.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "hss-shield-profet24v-ino.hpp"
   #include <Arduino.h>
   
   using namespace hss;
   
   Profet24VBTTShieldIno::Profet24VBTTShieldIno():
   Profet24VBTTShield  (
                           switches[0] = new HssIno(PROFET24VBTT_HWCONFIG.den_0, PROFET24VBTT_HWCONFIG.in0_0, PROFET24VBTT_HWCONFIG.in1_0, PROFET24VBTT_HWCONFIG.dsel_0, PROFET24VBTT_HWCONFIG.is_0, &BTT6030),
                           switches[1] = new HssIno(PROFET24VBTT_HWCONFIG.den_1, PROFET24VBTT_HWCONFIG.in0_1, PROFET24VBTT_HWCONFIG.in1_1, PROFET24VBTT_HWCONFIG.dsel_1, PROFET24VBTT_HWCONFIG.is_1, &BTT6030),
                           switches[2] = new HssIno(PROFET24VBTT_HWCONFIG.den_2, PROFET24VBTT_HWCONFIG.in0_2, PROFET24VBTT_HWCONFIG.is_2, &BTT6020)
                       )
   {
   
   }
   
   Profet24VBTTShieldIno::Profet24VBTTShieldIno(Profet24VBTTHwConfig_t config):
   Profet24VBTTShield  (
                           switches[0] = new HssIno(config.den_0, config.in0_0, config.in1_0, config.dsel_0, config.is_0, &BTT6030),
                           switches[1] = new HssIno(config.den_1, config.in0_1, config.in1_1, config.dsel_1, config.is_1, &BTT6030),
                           switches[2] = new HssIno(config.den_2, config.in0_2, config.is_2, &BTT6020)
                       )
   {
   
   }
   
   Profet24VBTTShieldIno::~Profet24VBTTShieldIno()
   {
   
   }
