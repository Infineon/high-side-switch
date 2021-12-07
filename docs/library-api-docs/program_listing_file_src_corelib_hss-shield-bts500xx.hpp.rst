
.. _program_listing_file_src_corelib_hss-shield-bts500xx.hpp:

Program Listing for File hss-shield-bts500xx.hpp
================================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_hss-shield-bts500xx.hpp>` (``src\corelib\hss-shield-bts500xx.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #ifndef HSS_SHIELD_BTS500XX_HPP_
   #define HSS_SHIELD_BTS500XX_HPP_
   
   #include "hss-shield.hpp"
   #include "hss-variants.hpp"
   #include "hss.hpp"
   
   using namespace hss;
   
   class Bts500xxShield : public HssShield
   {
       public:
   
                           Bts500xxShield(Hss * hsw1, GPIOPAL * led1, GPIOPAL * led2, ADCPAL * pushButton, ADCPAL * vBat);
                           ~Bts500xxShield();
   
           Error_t         init();
           Error_t         deinit();
           Error_t         switchHxOn(uint8_t x = 0);
           Error_t         switchHxOff(uint8_t x = 0);
           DiagStatus_t    readDiagx(uint8_t x = 0);
   
           float           readIsx(uint8_t x=1);
           float           readVss();
           bool            analogReadButton();
   
           void            setVoltageOffset(float offset);
   
       protected:
   
           ExponentialFilter *filterVbat;
   
           Hss      * hss1;
           GPIOPAL  * led1;
           GPIOPAL  * led2;
           ADCPAL   * pushButton;
           ADCPAL   * vBat;
   
       private:
   
           const uint16_t  rSense = 1000;
           float           vBatOffset = 0.0;
   
   };
   
   #endif 
