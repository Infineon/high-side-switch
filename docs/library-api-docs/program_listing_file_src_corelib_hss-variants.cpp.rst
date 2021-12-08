
.. _program_listing_file_src_corelib_hss-variants.cpp:

Program Listing for File hss-variants.cpp
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_hss-variants.cpp>` (``src\corelib\hss-variants.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "hss-variants.hpp"
   
   BtxVariants_t BTS7002 {
       .type = BTS700X,
       .kilis = 22700,
       .iisFault = 0.0044,
       .iisOl = 0.0018,
       .iisEn = 0.000002
   };
   
   BtxVariants_t BTS7004 {
       .type = BTS700X,
       .kilis = 20000,
       .iisFault = 0.0044,
       .iisOl = 0.0018,
       .iisEn = 0.000002
   };
   
   BtxVariants_t BTS7006 {
       .type = BTS700X,
       .kilis = 17700,
       .iisFault = 0.0044,
       .iisOl = 0.0018,
       .iisEn = 0.000002
   };
   
   BtxVariants_t BTS7008 {
       .type = BTS700X,
       .kilis = 14500,
       .iisFault = 0.0044,
       .iisOl = 0.0018,
       .iisEn = 0.000002
   };
   
   BtxVariants_t BTS50010 {
       .type = BTS5001X,
       .kilis = 52100,
       .iisFault = 0.0035,
       .iisOl = 0.0,
       .iisEn = 0.0,
       .iisO = 0.00018
   };
   
   BtxVariants_t BTS50015 {
       .type = BTS5001X,
       .kilis = 51500,
       .iisFault = 0.0035,
       .iisOl = 0.0,
       .iisEn = 0.0,
       .iisO = 0.000125
   };
   
   BtxVariants_t BTT6020 {
       .type = BTT60X0,
       .kilis = 2950,
       .iisFault = 0.006,
       .iisOl = 0.000004
   };
   
   BtxVariants_t BTT6030 {
       .type = BTT60X0,
       .kilis = 2240,
       .iisFault = 0.006,
       .iisOl = 0.000005
   };
