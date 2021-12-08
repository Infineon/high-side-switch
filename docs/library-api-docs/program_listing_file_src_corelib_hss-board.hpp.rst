
.. _program_listing_file_src_corelib_hss-board.hpp:

Program Listing for File hss-board.hpp
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_hss-board.hpp>` (``src\corelib\hss-board.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_BOARD_HPP_
   #define HSS_BOARD_HPP_
   
   #include <Arduino.h>
   #include "hss.hpp"
   #include "filter.hpp"
   
   class HssBoard : Hss
   {
       public:
   
       HssBoard();
       ~HssBoard();
       Error_t init();
       Error_t deinit();
   
       Error_t switchHxOn(uint8_t x);
       Error_t switchHxOff(uint8_t x);
       Error_t switchesHxOn(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL);
       Error_t switchesHxOff(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL);
       DiagStatus_t readDiagx(uint8_t x);
       DiagStatus_t diagnosisOff(float currentOn, float currentOff);
   
       float readIsx(uint8_t x);
   
       float readVss();
   
       bool digitalReadButton();
       bool analogReadButton();
   
       protected:
   
       ExponentialFilter *filterVbat;
   
       GPIO *led1;
       GPIO *led2;
       GPIO *led3;
       GPIO *led4;
   
       Hss *hss1;
       Hss *hss2;
       Hss *hss3;
       Hss *hss4;
   
       Timer *timer;
   
       GPIO *oloff;
       GPIO *pushButtonDigital;
   
       AnalogDigitalConverter *pushButtonAnalog;
       AnalogDigitalConverter *vBat;
   
       const float vBatGain = 1.0;
       const float vBatOffset = 0.0;
   };
   
   #endif 
