
.. _program_listing_file_src_corelib_hss-shield-btt60xx.cpp:

Program Listing for File hss-shield-btt60xx.cpp
===============================================

|exhale_lsh| :ref:`Return to documentation for file <file_src_corelib_hss-shield-btt60xx.cpp>` (``src\corelib\hss-shield-btt60xx.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   
   #include "hss-shield-btt60xx.hpp"
   
   using namespace hss;
   
   Btt60xxShield::Btt60xxShield(Hss *hsw0, Hss *hsw1, Hss *hsw2)
   {
       switches[0] = hsw0;
       switches[1] = hsw1;
       switches[2] = hsw2;
   }
   
   Btt60xxShield::~Btt60xxShield()
   {
   
   }
   
   Error_t Btt60xxShield::init()
   {
       Error_t err = OK;
   
       for(uint8_t i = 0; i < hssNum; i++)
       {
           HSS_ASSERT_NULLPTR(switches[i]);
           err = switches[i]->init();
           HSS_ASSERT_RET(err);
       }
   
       return err;
   }
   
   Error_t Btt60xxShield::deinit()
   {
       Error_t err = OK;
   
       for(uint8_t i = 0; i < hssNum; i++)
       {
           HSS_ASSERT_NULLPTR(switches[i]);
           err = switches[i]->deinit();
           HSS_ASSERT_RET(err);
       }
   
       return err;
   }
   
   Error_t Btt60xxShield::switchHxOn(uint8_t x)
   {
       Error_t err = OK;
   
       Channel_t ch = (Channel_t)(x % 2);
       uint8_t hss  = x/2;
       HSS_ASSERT_NULLPTR(switches[hss]);
       err = switches[hss]->enable(ch);
   
       return err;
   }
   
   Error_t Btt60xxShield::switchHxOff(uint8_t x)
   {
       Error_t err = OK;
   
       Channel_t ch = (Channel_t)(x % 2);
       uint8_t hss  = x/2;
       HSS_ASSERT_NULLPTR(switches[x]);
       err = switches[hss]->disable(ch);
   
       return err;
   }
   
   Error_t Btt60xxShield::switchesHxOn(bool h0_0, bool h1_0, bool h0_1, bool h1_1, bool h2)
   {
       Error_t err = OK;
   
       if(h0_0 == true){
           HSS_ASSERT_NULLPTR(switches[0]);
           err = switches[0]->enable();
           HSS_ASSERT_RET(err);
       }
   
       if(h1_0 == true){
           HSS_ASSERT_NULLPTR(switches[0]);
           err = switches[0]->enable(CHANNEL1);
           HSS_ASSERT_RET(err);
       }
   
       if(h0_1 == true){
           HSS_ASSERT_NULLPTR(switches[1]);
           err = switches[1]->enable();
           HSS_ASSERT_RET(err);
       }
   
       if(h1_1 == true){
           HSS_ASSERT_NULLPTR(switches[1]);
           err = switches[1]->enable(CHANNEL1);
           HSS_ASSERT_RET(err);
       }
   
       if(h2 == true){
           HSS_ASSERT_NULLPTR(switches[2]);
           err = switches[2]->enable();
           HSS_ASSERT_RET(err);
       }
       return err;
   }
   
   Error_t Btt60xxShield::switchesHxOff(bool h0_0, bool h1_0, bool h0_1, bool h1_1, bool h2)
   {
       Error_t err = OK;
   
       if(h0_0 == true){
           HSS_ASSERT_NULLPTR(switches[0]);
           err = switches[0]->disable();
           HSS_ASSERT_RET(err);
       }
   
       if(h1_0 == true){
           HSS_ASSERT_NULLPTR(switches[0]);
           err = switches[0]->disable(CHANNEL1);
           HSS_ASSERT_RET(err);
       }
   
       if(h0_1 == true){
           HSS_ASSERT_NULLPTR(switches[1]);
           err = switches[1]->disable();
           HSS_ASSERT_RET(err);
       }
   
       if(h1_1 == true){
           HSS_ASSERT_NULLPTR(switches[1]);
           err = switches[1]->disable(CHANNEL1);
           HSS_ASSERT_RET(err);
       }
   
       if(h2 == true){
           HSS_ASSERT_NULLPTR(switches[2]);
           err = switches[2]->disable();
           HSS_ASSERT_RET(err);
       }
       return err;
   }
   
   float Btt60xxShield::readIsx(uint8_t x)
   {
       float iisCalib;
       uint8_t hss = x/2;
       Channel_t ch = Channel_t(x % 2);
   
       HSS_ASSERT_NULLPTR(switches[hss]);
       switches[hss]->enableDiag();
       iisCalib = switches[hss]->readIs(rSense, ch);
       switches[hss]->disableDiag();
   
       return iisCalib;
   }
   
   DiagStatus_t Btt60xxShield::readDiagx(uint8_t x)
   {
       DiagStatus_t diagStatus = NORMAL;
       float currentOn = 0.0;
   
       uint8_t hss  = x/2;
   
       switches[hss]->enableDiag();
       if(switches[hss]->getSwitchStatus() == POWER_ON){
           currentOn = readIsx(x);
           diagStatus = switches[hss]->diagRead(currentOn);
       }
       switches[hss]->disableDiag();
   
       return diagStatus;
   }
