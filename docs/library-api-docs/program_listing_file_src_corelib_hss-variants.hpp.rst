
.. _program_listing_file_src_corelib_hss-variants.hpp:

Program Listing for File hss-variants.hpp
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_hss-variants.hpp>` (``src\corelib\hss-variants.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_VARIANTS_HPP_
   #define HSS_VARIANTS_HPP_
   
   #include <stdint.h>
   
   enum HssType_t
   {
       BTS700X,
       BTS5001X,
       BTT60X0
   };
   
   struct BtxVariants_t
   {
       HssType_t       type;           
       const uint16_t  kilis;          
       float           iisFault;       
       float           iisOl;          
       float           iisEn;          
       float           iisO;           
   };
   
   extern BtxVariants_t BTS7002;
   extern BtxVariants_t BTS7004;
   extern BtxVariants_t BTS7006;
   extern BtxVariants_t BTS7008;
   
   extern BtxVariants_t BTT6030;
   extern BtxVariants_t BTT6020;
   
   extern BtxVariants_t BTS50015;
   extern BtxVariants_t BTS50010;
   
   #endif 
