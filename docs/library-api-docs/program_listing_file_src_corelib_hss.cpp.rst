
.. _program_listing_file_src_corelib_hss.cpp:

Program Listing for File hss.cpp
================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_hss.cpp>` (``src\corelib\hss.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include <stdint.h>
   #include "hss.hpp"
   
   using namespace hss;
   
   Hss::Hss(GPIOPAL *den, GPIOPAL *in, ADCPAL *is, TimerPAL *timer, BtxVariants_t *btxVariant)
   {
       this->den = den;
       this->in0 = in;
       this->in1 = nullptr;
       this->is  = is;
       this->dsel = nullptr;
   
       this->timer = timer;
   
       this->btxVariant = btxVariant;
   
       currentFilter = new ExponentialFilter(0.0, 0.3);
   
       status = UNINITED;
       diagEnb = DIAG_DIS;
       diagStatus = NOT_ENABLED;
   }
   
   Hss::Hss(GPIOPAL *den, GPIOPAL *in0, GPIOPAL *in1,  GPIOPAL *dsel, ADCPAL *is, TimerPAL *timer, BtxVariants_t *btxVariant)
   {
       this->den = den;
       this->in0 = in0;
       this->in1 = in1;
       this->is = is;
       this->dsel = dsel;
   
       this->timer = timer;
   
       this->btxVariant = btxVariant;
   
        currentFilter = new ExponentialFilter(0.0, 0.3);
   
       status = UNINITED;
       diagEnb = DIAG_DIS;
       diagStatus = NOT_ENABLED;
   }
   
   Hss::~Hss()
   {
   
   }
   
   Error_t Hss::init()
   {
       Error_t err = OK;
   
       HSS_ASSERT_NULLPTR(den);
       err = den->init();
       HSS_ASSERT_RET(err);
   
       HSS_ASSERT_NULLPTR(in0);
       err = in0->init();
       HSS_ASSERT_RET(err);
   
       if(nullptr != in1)
       {
           err = in1->init();
           HSS_ASSERT_RET(err);
       }
   
       HSS_ASSERT_NULLPTR(is);
       err = is->init();
       HSS_ASSERT_RET(err);
   
       if(nullptr != dsel)
       {
           err = dsel->init();
           HSS_ASSERT_RET(err);
       }
   
       HSS_ASSERT_NULLPTR(timer);
       err = timer->init();
       HSS_ASSERT_RET(err);
   
       HSS_ASSERT_NULLPTR(btxVariant);
   
       status = INITED;
   
       return err;
   }
   
   Error_t Hss::deinit()
   {
       Error_t err = OK;
   
       HSS_ASSERT_NULLPTR(den);
       err = den->deinit();
       HSS_ASSERT_RET(err);
   
       HSS_ASSERT_NULLPTR(in0);
       err = in0->deinit();
       HSS_ASSERT_RET(err);
   
       if(nullptr != in1)
       {
           err = in1->deinit();
           HSS_ASSERT_RET(err);
       }
   
       if(nullptr != dsel)
       {
           err = dsel->deinit();
           HSS_ASSERT_RET(err);
       }
   
       HSS_ASSERT_NULLPTR(is);
       err = is->deinit();
       HSS_ASSERT_RET(err);
   
       HSS_ASSERT_NULLPTR(timer);
       err = timer->deinit();
       HSS_ASSERT_RET(err);
   
       HSS_ASSERT_NULLPTR(btxVariant);
   
       status = UNINITED;
   
       return err;
   }
   
   Error_t Hss::enable(Channel_t ch)
   {
       Error_t err = OK;
   
       if(UNINITED != status)
       {
           if(CHANNEL0 == ch || ALL_CHANNELS == ch)
           {
               HSS_ASSERT_NULLPTR(in0);
               err = in0->enable();
               HSS_ASSERT_RET(err);
               statusCh0 = POWER_ON;
           }
           if(CHANNEL1 == ch || ALL_CHANNELS == ch)
           {
               HSS_ASSERT_NULLPTR(in1);
               err = in1->enable();
               HSS_ASSERT_RET(err);
               statusCh1 = POWER_ON;
           }
   
           status = POWER_ON;
       }
       else
       {
           err = INIT_ERROR;
       }
   
       return err;
   }
   
   Error_t Hss::disable(Channel_t ch)
   {
       Error_t err = OK;
   
       if(UNINITED != status)
       {
   
           if(CHANNEL0 == ch || ALL_CHANNELS == ch)
           {
               HSS_ASSERT_NULLPTR(in0);
               err = in0->disable();
               HSS_ASSERT_RET(err);
               statusCh0 = POWER_OFF;
           }
           if(CHANNEL1 == ch || ALL_CHANNELS == ch)
           {
               HSS_ASSERT_NULLPTR(in1);
               err = in1->disable();
               HSS_ASSERT_RET(err);
               statusCh1 = POWER_OFF;
           }
   
           if((POWER_OFF == statusCh0) && (POWER_OFF == statusCh1))
           {
               status = POWER_OFF;
           }
       }
       else
       {
           err = INIT_ERROR;
       }
   
       return err;
   }
   
   Error_t Hss::enableDiag()
   {
       Error_t err = OK;
   
       if(UNINITED != status)
       {
           HSS_ASSERT_NULLPTR(den);
           err = den->enable();
           HSS_ASSERT_RET(err);
   
           diagEnb = DIAG_EN;
       }
       else
       {
           err = INIT_ERROR;
       }
   
       return err;
   }
   
   Error_t Hss::disableDiag()
   {
       Error_t err = OK;
   
       if(UNINITED != status)
       {
           HSS_ASSERT_NULLPTR(timer);
           err = den->disable();
           HSS_ASSERT_RET(err);
   
           diagEnb = DIAG_DIS;
       }
       else
       {
           err = INIT_ERROR;
       }
   
       return err;
   }
   
   Error_t Hss::selDiagCh(Channel_t ch)
   {
       Error_t err = OK;
   
       if(nullptr != dsel)
       {
           if(CHANNEL0 == ch)
           {
               err = dsel->disable();
           }
           else if(CHANNEL1 == ch){
               err = dsel->enable();
           }
           else
           {
               return INVALID_CH_ERROR;
           }
       }
   
       return err;
   }
   
   Status_t Hss::getSwitchStatus()
   {
       return status;
   }
   
   float Hss::readIs(uint16_t rSense, Channel_t ch)
   {
       uint16_t isVoltage = 0;
       float isCurrent = 0;
   
       if(UNINITED != status)
       {
           selDiagCh(ch);
   
           if(diagEnb == DIAG_EN)
           {
               timer->delayMilli(1);
               isVoltage = is->ADCRead();
               isVoltage = (float)(isVoltage/1024)*5.0;
               isCurrent = ((isVoltage*btxVariant->kilis)/rSense) - currentOffset;
               currentFilter->input(isCurrent);
           }
       }
   
       return currentFilter->output();
   }
   
   DiagStatus_t Hss::diagRead(float senseCurrent, Channel_t ch)
   {
       (void)ch;
   
       if(DIAG_EN == diagEnb)
       {
           if(senseCurrent >= (btxVariant->iisFault * btxVariant->kilis)){
               diagStatus = FAULT;
           }
           else if(btxVariant->type == BTS700X){
               if(senseCurrent <= (btxVariant->iisEn * btxVariant->kilis)){
                   diagStatus = FAULT_OL_IC;
               }
           }
           else if(btxVariant->type == BTS5001X){
               if(senseCurrent <= (btxVariant->iisO * btxVariant->kilis)){
                   diagStatus = FAULT_OL_IC;
               }
           }
           else if(btxVariant->type == BTT60X0){
               if(senseCurrent <= (btxVariant->iisOl * btxVariant->kilis)){
                   diagStatus = FAULT_OL_IC;
               }
           }
           else{
               diagStatus = NORMAL;
           }
       }
       else
       {
           diagStatus = NOT_ENABLED;
       }
   
       return diagStatus;
   }
   
   void Hss::setCurrentOffset(float offset)
   {
       currentOffset = offset;
   }
