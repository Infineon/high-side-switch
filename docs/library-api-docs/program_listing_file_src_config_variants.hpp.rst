
.. _program_listing_file_src_config_variants.hpp:

Program Listing for File variants.hpp
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_config_variants.hpp>` (``src\config\variants.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef VARIANTS_HPP_
   #define VARIANTS_HPP_
   
   #include <stdint.h>
   
   typedef struct BtsVariants_t
   {
       const uint16_t kilis;       
       float ampsGain;             
       float ampsOffset;           
       float vBatGain;             
       float vBatOffset;           
   };
   
   extern BtsVariants_t BTS7002;
   extern BtsVariants_t BTS7004;
   extern BtsVariants_t BTS7006;
   extern BtsVariants_t BTS7008;
   #endif 
