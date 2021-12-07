
.. _program_listing_file_src_framework_arduino_wrapper_hss-board-arduino.hpp:

Program Listing for File hss-board-arduino.hpp
==============================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_framework_arduino_wrapper_hss-board-arduino.hpp>` (``src\framework\arduino\wrapper\hss-board-arduino.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_BOARD_ARDUINO_HPP_
   #define HSS_BOARD_ARDUINO_HPP_
   
   #include "hss-board.hpp"
   #include "hss-arduino.hpp"
   #include "config.hpp"
   
   class HssBoardIno : public HssBoard
   {
       public:
   
       HssBoardIno(BtsVariants_t *variantSel);
       HssBoardIno(BtsVariants_t *variantSel, hardwareconfig_t config);
       ~HssBoardIno();
   };
   
   #endif 
