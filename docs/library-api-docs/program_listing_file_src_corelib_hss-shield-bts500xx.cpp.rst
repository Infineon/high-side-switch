
.. _program_listing_file_src_corelib_hss-shield-bts500xx.cpp:

Program Listing for File hss-shield-bts500xx.cpp
================================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_hss-shield-bts500xx.cpp>` (``src\corelib\hss-shield-bts500xx.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "hss-shield-bts500xx.hpp"
   
   using namespace hss;
   
   Bts500xxShield::Bts500xxShield(Hss * hsw1, GPIOPAL * led1, GPIOPAL * led2, ADCPAL * pushButton, ADCPAL * vBat)
   :
   hss1(hsw1),
   led1(led1),
   led2(led2),
   pushButton(pushButton),
   vBat(vBat)
   {
   
   }
   
   Bts500xxShield::~Bts500xxShield()
   {
   
   }
   
   Error_t Bts500xxShield::init()
   {
       Error_t err= OK;
   
       HSS_ASSERT_NULLPTR(hss1);
       err= hss1->init();
       HSS_ASSERT_RET(err);
   
       if(nullptr != led1)
       {
           err = led1->init();
           HSS_ASSERT_RET(err);
       }
   
       if(nullptr != led2)
       {
           err = led2->init();
           HSS_ASSERT_RET(err);
       }
   
       if(nullptr != pushButton)
       {
           err = pushButton->init();
           HSS_ASSERT_RET(err);
       }
   
       if(nullptr != vBat)
       {
           err = vBat->init();
           HSS_ASSERT_RET(err);
       }
   
       filterVbat = new ExponentialFilter(0.0, 0.3);
   
       return OK;
   }
   
   Error_t Bts500xxShield::deinit()
   {
       Error_t err= OK;
   
       HSS_ASSERT_NULLPTR(hss1);
       err= hss1->deinit();
       HSS_ASSERT_RET(err);
   
       if(nullptr != led1)
       {
           err = led1->deinit();
           HSS_ASSERT_RET(err);
       }
   
       if(nullptr != led2)
       {
           err = led2->deinit();
           HSS_ASSERT_RET(err);
       }
   
       if(nullptr != pushButton)
       {
           err = pushButton->deinit();
           HSS_ASSERT_RET(err);
       }
   
       if(nullptr != vBat)
       {
           err = vBat->deinit();
           HSS_ASSERT_RET(err);
       }
   
       return OK;
   }
   
   Error_t Bts500xxShield::switchHxOn(uint8_t x)
   {
       (void)x;  
       Error_t err= OK;
   
       err = hss1->enable();
       HSS_ASSERT_RET(err);
   
       if (nullptr != led1)
       {
           err = led1->enable();
           HSS_ASSERT_RET(err);
       }
   
       return err;
   }
   
   Error_t Bts500xxShield::switchHxOff(uint8_t x)
   {
       (void)x;  
       Error_t err= OK;
   
       err= hss1->disable();
       HSS_ASSERT_RET(err);
   
       if (nullptr != led1)
       {
           err = led1->disable();
           HSS_ASSERT_RET(err);
       }
   
       return err;
   }
   
   
   float Bts500xxShield::readIsx(uint8_t x)
   {
       (void)x;  
       float isVal;
   
       hss1->enableDiag();
       isVal = hss1->readIs(rSense);
       hss1->disableDiag();
   
       return isVal;
   }
   
   DiagStatus_t Bts500xxShield::readDiagx(uint8_t x)
   {
       (void)x;  
       DiagStatus_t diagStatus = NORMAL;
       float currentOn = 0.0;
   
       if(hss1->getSwitchStatus() == POWER_ON)
       {
           currentOn = hss1->readIs(rSense);
           diagStatus = hss1->diagRead(currentOn);
       }
   
       return diagStatus;
   }
   
   
   float Bts500xxShield::readVss()
   {
       uint16_t adcResult = 0;
       float voltage = 0.0;
   
       adcResult = vBat->ADCRead();
       voltage = adcResult * ((float)5/(float)1024);   // Vmax/1024 LSB = Resolution of the ADC,
       voltage = (voltage - vBatOffset);
       voltage = voltage * ((float)57/(float)10);      // 57/10 = Reverse Voltage devider to get the Supplyvoltage
   
       filterVbat->input(voltage);
   
       return filterVbat->output();
   }
   
   bool Bts500xxShield::analogReadButton()
   {
       uint16_t result = 0;
   
       result = pushButton->ADCRead();
       if(result < 20){
           return true;
       }
       else{
           return false;
       }
   }
   
   void Bts500xxShield::setVoltageOffset(float offset)
   {
       vBatOffset = offset;
   }
