
.. _program_listing_file_src_corelib_hss-shield-bts700x.cpp:

Program Listing for File hss-shield-bts700x.cpp
===============================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_hss-shield-bts700x.cpp>` (``src\corelib\hss-shield-bts700x.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "hss-shield-bts700x.hpp"
   
   using namespace hss;
   Bts700xShield::Bts700xShield(GPIOPAL *led1, GPIOPAL *led2, GPIOPAL *led3, GPIOPAL *led4, Hss *hsw1, Hss *hsw2, Hss *hsw3, Hss *hsw4, TimerPAL *timer,
                                GPIOPAL *oloff, GPIOPAL *pushButtonDigital, ADCPAL *pushButtonAnalog, ADCPAL *vBat, BtxVariants_t* btxVariant)
   {
       this->led1 = led1;
       this->led2 = led2;
       this->led3 = led3;
       this->led4 = led4;
   
       this->hss1 = hsw1;
       this->hss2 = hsw2;
       this->hss3 = hsw3;
       this->hss4 = hsw4;
   
       this->timer = timer;
   
       this->oloff = oloff;
       this->pushButtonDigital = pushButtonDigital;
   
       this->pushButtonAnalog = pushButtonAnalog;
       this->vBat = vBat;
   
       this->btxVariant = btxVariant;
   }
   
   Bts700xShield::~Bts700xShield()
   {
   
   }
   
   Error_t Bts700xShield::init()
   {
       Error_t err = OK;
   
       do{
           if(NULL != led1){
               err = led1->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != led2){
               err = led2->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != led3){
               err = led3->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != led4){
               err = led4->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != hss1){
               err = hss1->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != hss2){
               err = hss2->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != hss3){
               err = hss3->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != hss4){
               err = hss4->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != timer){
               err = timer->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != oloff){
               err = oloff->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != pushButtonDigital){
               err = pushButtonDigital->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != pushButtonAnalog){
               err = pushButtonAnalog->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != vBat){
               err = vBat->init();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           filterVbat = new ExponentialFilter(0.0, 0.3);
   
           if(NULL == btxVariant){
               return NULLPTR_ERROR;
           }
   
       } while (0);
   
       return err;
   }
   
   Error_t Bts700xShield::deinit()
   {
       Error_t err = OK;
   
        do{
           if(NULL != led1){
               err = led1->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != led2){
               err = led2->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != led3){
               err = led3->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != led4){
               err = led4->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != hss1){
               err = hss1->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != hss2){
               err = hss2->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != hss3){
               err = hss3->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != hss4){
               err = hss4->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != timer){
               err = timer->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != oloff){
               err = oloff->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != pushButtonDigital){
               err = pushButtonDigital->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != pushButtonAnalog){
               err = pushButtonAnalog->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL != vBat){
               err = vBat->deinit();
               if(OK != err){
                   break;
               }
           }
           else{
               err = NULLPTR_ERROR;
               break;
           }
   
           if(NULL == btxVariant){
               return NULLPTR_ERROR;
           }
   
       } while (0);
   
       return err;
   }
   
   Error_t Bts700xShield::switchHxOn(uint8_t x)
   {
       Error_t err = OK;
   
       switch(x)
       {
           case 1:
               err = hss1->enable();
               if (NULL != led1 && OK == err)
                   err = led1->enable();
               break;
   
           case 2:
               err = hss2->enable();
               if (NULL != led2 && OK == err)
                   err = led2->enable();
               break;
   
           case 3:
               err = hss3->enable();
               if (NULL != led3 && OK == err)
                   err = led3->enable();
               break;
   
           case 4:
               err = hss4->enable();
               if (NULL != led4 && OK == err)
                   err = led4->enable();
               break;
       }
   
       return err;
   }
   
   Error_t Bts700xShield::switchHxOff(uint8_t x)
   {
       Error_t err = OK;
   
       switch(x)
       {
           case 1:
               err = hss1->disable();
               if (NULL != led1 && OK == err)
                   err = led1->disable();
               break;
   
           case 2:
               err = hss2->disable();
               if (NULL != led2 && OK == err)
                   err = led2->disable();
               break;
   
           case 3:
               err = hss3->disable();
               if (NULL != led3 && OK == err)
                   err = led3->disable();
               break;
   
           case 4:
               err = hss4->disable();
               if (NULL != led4 && OK == err)
                   err = led4->disable();
               break;
       }
   
       return err;
   }
   
   Error_t Bts700xShield::switchesHxOn(bool h1, bool h2, bool h3, bool h4)
   {
       Error_t err = OK;
   
       do{
           if(h1 == true){
               err = hss1->enable();
               if (NULL != led1 && OK == err)
                   err = led1->enable();
               else
                   break;
           }
   
           if(h2 == true){
               err = hss2->enable();
               if (NULL != led2 && OK == err)
                   err = led2->enable();
               else
                   break;
           }
   
           if(h3 == true){
               err = hss3->enable();
               if (NULL != led3 && OK == err)
                   err = led3->enable();
               else
                   break;
           }
   
           if(h4 == true){
               err = hss4->enable();
               if (NULL != led4 && OK == err)
                   err = led4->enable();
               else
                   break;
           }
       } while (0);
   
       return err;
   }
   
   Error_t Bts700xShield::switchesHxOff(bool h1, bool h2, bool h3, bool h4)
   {
       Error_t err = OK;
   
       do{
           if(h1 == true){
               err = hss1->disable();
               if (NULL != led1 && OK == err)
                   err = led1->disable();
               else
                   break;
           }
   
           if(h2 == true){
               err = hss2->disable();
               if (NULL != led2 && OK == err)
                   err = led2->disable();
               else
                   break;
           }
   
           if(h3 == true){
               err = hss3->disable();
               if (NULL != led3 && OK == err)
                   err = led3->disable();
               else
                   break;
           }
   
           if(h4 == true){
               err = hss4->disable();
               if (NULL != led4 && OK == err)
                   err = led4->disable();
               else
                   break;
           }
       } while (0);
   
       return err;
   }
   
   DiagStatus_t Bts700xShield::readDiagx(uint8_t x)
   {
       DiagStatus_t diagStatus = NORMAL;
   
       float currentOn = 0.0;
       float currentOff = 0.0;
   
       switch(x)
       {
           case 1:
               hss1->enableDiag();
               if(hss1->getSwitchStatus() == POWER_ON)
               {
                   currentOn = readIsx(1);
                   diagStatus = hss1->diagRead(currentOn);
               }
               else
               {
                   oloff->enable();
                   timer->delayMicro(300);
                   currentOn = readIsx(1);
   
                   oloff->disable();
                   timer->delayMicro(400);
                   currentOff = readIsx(1);
                   diagStatus = diagnosisOff(currentOn, currentOff);
               }
               hss1->disableDiag();
               break;
   
           case 2:
               hss2->enableDiag();
               if(hss2->getSwitchStatus() == POWER_ON)
               {
                   currentOn = readIsx(2);
                   diagStatus = hss2->diagRead(currentOn);
               }
               else
               {
                   oloff->enable();
                   timer->delayMicro(300);
                   currentOn = readIsx(2);
   
                   oloff->disable();
                   timer->delayMicro(400);
                   currentOff = readIsx(2);
                   diagStatus = diagnosisOff(currentOn, currentOff);
               }
               hss2->disableDiag();
               break;
   
           case 3:
               hss3->enableDiag();
               if(hss3->getSwitchStatus() == POWER_ON)
               {
                   currentOn = readIsx(3);
                   diagStatus = hss3->diagRead(currentOn);
               }
               else
               {
                   oloff->enable();
                   timer->delayMicro(300);
                   currentOn = readIsx(3);
   
                   oloff->disable();
                   timer->delayMicro(400);
                   currentOff = readIsx(3);
                   diagStatus = diagnosisOff(currentOn, currentOff);
               }
               hss3->disableDiag();
               break;
   
           case 4:
               hss4->enableDiag();
               if(hss4->getSwitchStatus() == POWER_ON)
               {
                   currentOn = readIsx(4);
                   diagStatus = hss4->diagRead(currentOn);
               }
               else
               {
                   oloff->enable();
                   timer->delayMicro(300);
                   currentOn = readIsx(4);
   
                   oloff->disable();
                   timer->delayMicro(400);
                   currentOff = readIsx(4);
                   diagStatus = diagnosisOff(currentOn, currentOff);
               }
               hss4->disableDiag();
               break;
       }
   
       return diagStatus;
   }
   
   float Bts700xShield::readIsx(uint8_t x)
   {
       float isVal = 0.0;
   
       switch (x)
       {
           case 1:
               hss1->enableDiag();
               isVal = hss1->readIs(rSense);
               hss1->disableDiag();
               break;
   
           case 2:
               hss2->enableDiag();
               isVal = hss2->readIs(rSense);
               hss2->disableDiag();
               break;
   
           case 3:
               hss3->enableDiag();
               isVal = hss3->readIs(rSense);
               hss3->disableDiag();
               break;
   
           case 4:
               hss4->enableDiag();
               isVal = hss4->readIs(rSense);
               hss4->disableDiag();
               break;
       }
   
       return isVal;
   }
   
   float Bts700xShield::readVss()
   {
       uint16_t adcResult = 0;
       float voltage = 0.0;
   
       adcResult = vBat->ADCRead();
       voltage = adcResult * ((float)5/(float)1024);   // Vmax/1024 LSB = Resolution of the ADC
       voltage = (voltage - vBatOffset);
       voltage = voltage * ((float)57/(float)10);      // 57/10 = Reverse Voltage devider to get the Supplyvoltage
   
       filterVbat->input(voltage);
   
       return filterVbat->output();
   }
   
   bool Bts700xShield::digitalReadButton()
   {
       if(pushButtonDigital->read() == GPIOPAL::GPIO_LOW){
           return true;
       }
       else{
           return false;
       }
   }
   
   bool Bts700xShield::analogReadButton()
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
   
   void Bts700xShield::setVoltageOffset(float offset)
   {
       vBatOffset = offset;
   }
   
   DiagStatus_t Bts700xShield::diagnosisOff(float currentOn, float currentOff)
   {
       if((currentOn > (btxVariant->iisOl * btxVariant->kilis)) && (currentOn < (btxVariant->iisFault * btxVariant->kilis))){
           if((currentOff > (btxVariant->iisOl * btxVariant->kilis)) && (currentOff < (btxVariant->iisFault * btxVariant->kilis))){
               return SHORT_TO_VSS;
           }
           else{
               return OPEN_LOAD;
           }
       }
       else{
           if((currentOn > (btxVariant->iisFault * btxVariant->kilis))){
               return SHORT_TO_GND_OR_OT;
           }
           else{
               return NORMAL;
           }
       }
   }
