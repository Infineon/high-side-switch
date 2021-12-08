
.. _program_listing_file_src_framework_arduino_wrapper_hss-shield-platf.hpp:

Program Listing for File hss-shield-platf.hpp
=============================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-shield-platf.hpp>` (``src\framework\arduino\wrapper\hss-shield-platf.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_SHIELD_PLATF_HPP_
   #define HSS_SHIELD_PLATF_HPP_
   
   #include <stdint.h>
   
   struct Bts700xHwConfig_t
   {
       uint8_t led1;
       uint8_t led2;
       uint8_t led3;
       uint8_t led4;
   
       uint8_t in1;
       uint8_t in2;
       uint8_t in3;
       uint8_t in4;
   
       uint8_t oloff;
   
       uint8_t den1_den3;
       uint8_t den2_den4;
   
       uint8_t pushButtonDigital;
   
       uint8_t pushButtonAnalog;
       uint8_t vBat;
       uint8_t is1_is2;
       uint8_t is3_is4;
   };
   
   struct Profet24VBTTHwConfig_t
   {
       //Profet0 - BTT6030 (2 channel) pin config
       uint8_t in0_0;
       uint8_t den_0;
       uint8_t dsel_0;
       uint8_t in1_0;
       uint8_t is_0;
   
       //Profet1 - BTT6030 (2 channel) pin config
       uint8_t in0_1;
       uint8_t den_1;
       uint8_t dsel_1;
       uint8_t in1_1;
       uint8_t is_1;
   
       //Profet2 - BTT6020 (1 channel) pin config
       uint8_t in0_2;
       uint8_t den_2;
       uint8_t is_2;
   
   };
   
   extern Bts700xHwConfig_t BTS700X_HWCONFIG;
   extern Profet24VBTTHwConfig_t PROFET24VBTT_HWCONFIG;
   
   struct BTS500xxHwConfig_t
   {
       uint8_t led1;
       uint8_t led2;
   
       uint8_t in;
   
       uint8_t pushButtonAnalog;
   
       uint8_t vBat;
      
       uint8_t is;
   };
   
   extern BTS500xxHwConfig_t BTS500XX_HWCONFIG;
   #endif 
