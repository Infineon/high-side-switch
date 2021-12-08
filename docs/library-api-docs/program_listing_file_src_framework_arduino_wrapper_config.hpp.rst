
.. _program_listing_file_src_framework_arduino_wrapper_config.hpp:

Program Listing for File config.hpp
===================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_config.hpp>` (``src\framework\arduino\wrapper\config.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef CONFIG_HPP_
   #define CONFIG_HPP_
   
   #include <stdint.h>
   
   struct hardwareconfig_t
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
   
   extern hardwareconfig_t ARDUINO_UNO;
   #endif 
