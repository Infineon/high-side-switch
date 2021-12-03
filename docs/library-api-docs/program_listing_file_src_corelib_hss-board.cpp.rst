
.. _program_listing_file_src_corelib_hss-board.cpp:

Program Listing for File hss-board.cpp
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_hss-board.cpp>` (``src\corelib\hss-board.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "hss-board.hpp"
   
   HssBoard::HssBoard()
   {
       filterVbat = NULL;
   
       led1 = NULL;
       led2 = NULL;
       led3 = NULL;
       led4 = NULL;
   
       hss1 = NULL;
       hss2 = NULL;
       hss3 = NULL;
       hss4 = NULL;
   
       timer = NULL;
   
       oloff = NULL;
       pushButtonDigital = NULL;
       
       pushButtonAnalog = NULL;
       vBat = NULL;
   }
   
   HssBoard::~HssBoard()
   {
   
   }
   
   HssBoard::Error_t HssBoard::init()
   {
       filterVbat = new ExponentialFilter(0.0, 0.3);
   
       if (NULL != led1)
           led1->init();
       if (NULL != led2)
           led2->init();
       if (NULL != led3)
           led3->init();
       if (NULL != led4)
           led4->init();
   
       hss1->init();
       hss2->init();
       hss3->init();
       hss4->init();
   
       timer->init();
       
       oloff->init();
       pushButtonDigital->init();
   
       pushButtonAnalog->init();
       vBat->init();
   
       return OK;
   }
   
   HssBoard::Error_t HssBoard::deinit()
   {
   
       if (NULL != led1)
           led1->deinit();
       if (NULL != led2)
           led2->deinit();
       if (NULL != led3)
           led3->deinit();
       if (NULL != led4)
           led4->deinit();
   
       hss1->deinit();
       hss2->deinit();
       hss3->deinit();
       hss4->deinit();
   
       timer->deinit();
   
       oloff->deinit();
       pushButtonDigital->deinit();
       
       pushButtonAnalog->deinit();
       vBat->deinit();
   
       return OK;
   }
   
   HssBoard::Error_t HssBoard::switchHxOn(uint8_t x)
   {
       switch(x)
       {
           case 1:
               hss1->enable();
               if (NULL != led1)
                   led1->enable();
               break;
           
           case 2:
               hss2->enable();
               if (NULL != led2)
                   led2->enable();
               break;
           
           case 3:
               hss3->enable();
               if (NULL != led3)
                   led3->enable();
               break;
           
           case 4:
               hss4->enable();
               if (NULL != led4)
                   led4->enable();
               break;
       }
       return OK;
   }
   
   HssBoard::Error_t HssBoard::switchHxOff(uint8_t x)
   {
       switch(x)
       {
           case 1:
               hss1->disable();
               if (NULL != led1)
                   led1->disable();
               break;
           
           case 2:
               hss2->disable();
               if (NULL != led2)
                   led2->disable();
               break;
           
           case 3:
               hss3->disable();
               if (NULL != led3)
                   led3->disable();
               break;
           
           case 4:
               hss4->disable();
               if (NULL != led4) 
                   led4->disable();
               break;
       }
       return OK;
   }
   
   HssBoard::Error_t HssBoard::switchesHxOn(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL)
   {
       if(h1 == true){
           hss1->enable();
           if (NULL != led1)
               led1->enable();
       }
   
       if(h2 == true){
           hss2->enable();
           if (NULL != led2)
               led2->enable();
       }
   
       if(h3 == true){
           hss3->enable();
           if (NULL != led3)
               led3->enable();
       }
   
       if(h4 == true){
           hss4->enable();
           if (NULL != led4)
               led4->enable();
       }
   
       return OK;
   }
   
   HssBoard::Error_t HssBoard::switchesHxOff(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL)
   {
       if(h1 == true){
           hss1->disable();
           if (NULL != led1)
               led1->disable();
       }
   
       if(h2 == true){
           hss2->disable();
           if (NULL != led2)
               led2->disable();
       }
   
       if(h3 == true){
           hss3->disable();
           if (NULL != led3)
               led3->disable();
       }
   
       if(h4 == true){
           hss4->disable();
           if (NULL != led4)
               led4->disable();
       }
   
       return OK;
   }
   
   float HssBoard::readIsx(uint8_t x)
   {
       float result;
       switch (x)
       {
           case 1:
               hss1->enableDiag();
               result = hss1->readIs();
               hss1->disableDiag();
               break;
           
           case 2:
               hss2->enableDiag();
               result = hss2->readIs();
               hss2->disableDiag();
               break;
           
           case 3:
               hss3->enableDiag();
               result = hss3->readIs();
               hss3->disableDiag();
               break;
   
           case 4:
               hss4->enableDiag();
               result = hss4->readIs();
               hss4->disableDiag();
               break;
       }
       return result;
   }
   
   HssBoard::DiagStatus_t HssBoard::readDiagx(uint8_t x)
   {
       DiagStatus_t diagStatus = NORMAL;
   
       float currentOn = 0.0;
       float currentOff = 0.0;
   
       switch(x)
       {
           case 1:
               hss1->enableDiag();
               if(hss1->getSwitchStatus() == Hss::Status_t::POWER_ON){
                  diagStatus = hss1->diagRead();
               }
               else{
                   oloff->enable();
                   timer->delayMicro(300);
                   currentOn = hss1->readIs();
       
                   oloff->disable();
                   timer->delayMicro(400);
                   currentOff = hss1->readIs();
                   diagStatus = diagnosisOff(currentOn, currentOff);
               }
               hss1->disableDiag();
               break;
   
           case 2:
               hss2->enableDiag();
               if(hss2->getSwitchStatus() == Hss::Status_t::POWER_ON){
                   diagStatus = hss2->diagRead();
               }
               else{
                   oloff->enable();
                   timer->delayMicro(300);
                   currentOn = hss2->readIs();
   
                   oloff->disable();
                   timer->delayMicro(400);
                   currentOff = hss2->readIs();
                   diagStatus = diagnosisOff(currentOn, currentOff);
               }
               hss2->disableDiag();
               break;
           
           case 3:
               hss3->enableDiag();
               if(hss3->getSwitchStatus() == Hss::Status_t::POWER_ON){
                   diagStatus = hss3->diagRead();
               }
               else{
                   oloff->enable();
                   timer->delayMicro(300);
                   currentOn = hss3->readIs();
   
                   oloff->disable();
                   timer->delayMicro(400);
                   currentOff = hss3->readIs();
                   diagStatus = diagnosisOff(currentOn, currentOff);
               }
               hss3->disableDiag();
               break;
           
           case 4:
               hss4->enableDiag();
               if(hss4->getSwitchStatus() == Hss::Status_t::POWER_ON){
                   diagStatus = hss4->diagRead();
               }
               else{
                   oloff->enable();
                   timer->delayMicro(300);
                   currentOn = hss4->readIs();
   
                   oloff->disable();
                   timer->delayMicro(400);
                   currentOff = hss4->readIs();
                   diagStatus = diagnosisOff(currentOn, currentOff);
               }
               hss4->disableDiag();
               break;
       }
       return diagStatus;
   }
   
   HssBoard::DiagStatus_t HssBoard::diagnosisOff(float currentOn, float currentOff)
   {
       if((currentOn > (0.0018 * btsVariant->kilis)) && (currentOn < (0.0044 * btsVariant->kilis))){
           if((currentOff > (0.0018 * btsVariant->kilis)) && (currentOff < (0.0044 * btsVariant->kilis))){
               return DiagStatus_t::SHORT_TO_VSS;
           }
           else{
               return DiagStatus_t::OPEN_LOAD;
           }
       }
       else{
           if((currentOn > (0.0044 * btsVariant->kilis))){
               return DiagStatus_t::SHORT_TO_GND;
           }
           else{
               return DiagStatus_t::NORMAL;
           }
       }
   }
   
   float HssBoard::readVss()
   {
       uint16_t adcResult = 0;
       float voltage = 0.0;
       
       adcResult = vBat->ADCRead();
       voltage = adcResult * ((float)5/(float)1024);  // Vmax/1024 LSB = Resolution of the ADC, 57/10 = Reverse Voltage devider to get the Supplyvoltage
       voltage = (voltage - vBatOffset) * vBatGain;
       voltage = voltage * ((float)57/(float)10);
   
       filterVbat->input(voltage);
       
       return filterVbat->output();
   }
   
   bool HssBoard::digitalReadButton()
   {
       if(pushButtonDigital->read() == GPIO::GPIO_LOW)
       return true;
       else
       return false;
   }
   
   bool HssBoard::analogReadButton()
   {
       uint16_t result = 0;
   
       result = pushButtonAnalog->ADCRead();
       if(result < 20){
           return true;
       }
       else{
           return false;
       }
   }
   
   
   
   
