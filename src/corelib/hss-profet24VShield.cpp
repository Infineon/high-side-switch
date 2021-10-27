/** 
 * @file        hss-profet24VShield.cpp
 * @brief       Profet (24V) Shield with BTT6030-2EKA and BTT6020-1EKA Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "hss-profet24VShield.hpp"

using namespace hss;

/**
 * @brief Profet 24V Shield constructor
 * Initialize all protected class pointers with a null pointer.
 */
Profet24VBTTShield::Profet24VBTTShield()
{

}

/**
 * @brief Destructor of the Profet 24V Shield
 * 
 */
Profet24VBTTShield::~Profet24VBTTShield()
{

}

/**
 * @brief Initialize all necessary objects of the Profet 24V Shield
 * 
 * This function initializes all necessary objects of the Profet 24V Shield.
 * It retruns an error code to see if everything was initialized correctly.
 * 
 * @return Profet24VShield::Error_t
 */
Error_t Profet24VBTTShield::init()
{
    hss0->init();
    hss1->init();
    hss2->init();
    hss3->init();
    hss4->init();

    timer->init();

    return OK;
}

/**
 * @brief Deinitialize all necessary objects of the Profet 24V Shield
 * 
 * This function deinitializes all necessary objects of the Profet 24V Shield.
 * It retruns an error code to see if everything was deinitialized correctly.
 * 
 * @return Profet24VShield::Error_t
 */
Error_t Profet24VBTTShield::deinit()
{

    hss0->deinit();
    hss1->deinit();
    hss2->deinit();
    hss3->deinit();
    hss4->deinit();

    timer->deinit();

    return OK;
}

/**
 * @brief Switch on the selected High-Side-Switch
 * 
 * This function turns on the desired High-Side-Switch.
 * 
 * @param[in]   x   Number of the Switch the should be turned on (1-5)      
 * @return          Error_t 
 */
Error_t Profet24VBTTShield::switchHxOn(uint8_t x, Channel_t ch)
{
    switch(x)
    {
        case 0:
            if(CHANNEL0 == ch)
                hss0->enable();
            if(CHANNEL1 == ch)
                hss1->enable();
            break;
        
        case 1:
            if(CHANNEL0 == ch)
                hss2->enable();
            if(CHANNEL1 == ch)
                hss3->enable();
            break;
        
        case 2:
            hss4->enable();
            break;
    }
    return OK;
}

/**
 * @brief Switch off the selected High-Side-Switch
 * 
 * This function turns off the desired High-Side-Switch.
 * 
 * @param[in]   x   Number of the Switch the should be turned off (1-4)  
 * @return          Error_t 
 */
Error_t Profet24VBTTShield::switchHxOff(uint8_t x, Channel_t ch)
{
    switch(x)
    {
        case 1:
            if(CHANNEL0 == ch)
                hss0->disable();
            if(CHANNEL1 == ch)
                hss1->disable();
            break;        
        
        case 2:
            if(CHANNEL0 == ch)
                hss2->disable();
            if(CHANNEL1 == ch)
                hss3->disable();
            break;
        
        case 3:
            hss4->disable();
            break;
    }
    return OK;
}

/**
 * @brief Turn on the selected High-Side-Switches
 * 
 * This function is used to enable multiple switches at once.
 * 
 * @param[in] h0    Enable the first switch if h0 == true 
 * @param[in] h1    Enable the first switch if h1 == true   
 * @param[in] h2    Enable the second switch if h2 == true 
 * @param[in] h3    Enable the third switch if h3 == true 
 * @param[in] h4    Enable the fourth switch if h4 == true 
 * 
 * @return          Error_t 
 */
Error_t Profet24VBTTShield::switchesHxOn(bool h1_0 = NULL, bool h2_0 = NULL, bool h1_1 = NULL, bool h2_1 = NULL, bool h2 = NULL)
{
    if(h1_0 == true){
        hss0->enable();
    }

    if(h2_0 == true){
        hss1->enable();
    }

    if(h1_1 == true){
        hss2->enable();
    }

    if(h2_1 == true){
        hss3->enable();
    }

    if(h2 == true){
        hss4->enable();
    }
    return OK;
}

/**
 * @brief Turn off the selected High-Side-Switches
 * 
 * This function is used to disable multiple switches at once.
 * 
 * @param[in] h0    Enable the first switch if h0 == true
 * @param[in] h1    Disable the first switch if h1 == true   
 * @param[in] h2    Disable the second switch if h2 == true 
 * @param[in] h3    Disable the third switch if h3 == true 
 * @param[in] h4    Disable the fourth switch if h4 == true 
 * 
 * @return          Error_t 
 */
Error_t Profet24VBTTShield::switchesHxOff(bool h1_0 = NULL, bool h2_0 = NULL, bool h1_1 = NULL, bool h2_1 = NULL, bool h2 = NULL)
{
    if(h1_0 == true){
        hss0->disable();
    }

    if(h2_0 == true){
        hss1->disable();
    }

    if(h1_1 == true){
        hss2->disable();
    }

    if(h2_1 == true){
        hss3->disable();
    }

    if(h2 == true){
        hss4->disable();
    }

    return OK;
}

/**
 * @brief Read the desired current value of the chosen channel
 * 
 * This function reads the IS pin of the chosen High-Side-Switch
 * and calculates the current which is flowing through the switch
 * with the acquired ADC value.
 * 
 * @param[in]   x   Number of the desired channel
 *              Possible values are:
 *              0   :   Profet 0 - Channel 0
 *              1   :   Profet 0 - Channel 1
 *              2   :   Profet 1 - Channel 0
 *              3   :   Profet 1 - Channel 1
 *              4   :   Profet 2 
 * @return          The value of the current in [A]      
 */
float Profet24VBTTShield::readIsx(uint8_t x, Channel_t ch)
{
    float iis_A = 0.0, vis_V = 0.0;
    float iisCalib;

    uint16_t adcResult;

    switch (x)
    {
        case 0:
            if(CHANNEL0 == ch)
            {
                hss0->enableDiag();
                hss0->diagSelCh0();
                adcResult = getIs(x,ch);
                hss0->disableDiag();
            }
            if(CHANNEL1 == ch)
            {
                hss1->enableDiag();
                hss1->diagSelCh1();
                adcResult = getIs(x,ch);
                hss1->disableDiag();
            }
            break;

        case 1:
            if(CHANNEL0 == ch)
            {
                hss2->enableDiag();
                hss2->diagSelCh0();
                adcResult = getIs(x,ch);
                hss2->disableDiag();
            }
            if(CHANNEL1 == ch)
            {
                hss3->enableDiag();
                hss3->diagSelCh1();
                adcResult = getIs(x,ch);
                hss3->disableDiag();
            }
            break;

        case 2:
            hss4->enableDiag();
            adcResult = getIs(x,ch);
            hss4->disableDiag();
            break;
    }

    iisCalib = getIs(x,ch);

    return iisCalib;
}

/**
 * @brief Read the desired current value of the chosen channel
 * 
 * This function reads the IS pin of the chosen High-Side-Switch
 * and calculates the current which is flowing through the switch
 * with the acquired ADC value.
 * 
 * @param[in]   x   Number of the desired channel (1-4)
 * @return          The value of the current in [A]      
 */
float Profet24VBTTShield::getIs(uint8_t x,Channel_t ch)
{
    uint16_t adcResult;
    float iis_A,vis_V, iisCalib;
    switch(x)
    {
        case 0:
            if(CHANNEL0 == ch)
            {
                adcResult = hss0->readIs();
                vis_V = ((float)adcResult/(float)1024) * (float)5;
                iis_A = vis_V/ris_Ohm;
                iisCalib = hss0->calibrateIs(iis_A,BTT6030.kilis,BTT6030.ampsOffset, BTT6030.ampsGain);
            }
            if(CHANNEL1 == ch)
            {
                adcResult = hss1->readIs();
                vis_V = ((float)adcResult/(float)1024) * (float)5;
                iis_A = vis_V/ris_Ohm;
                iisCalib = hss1->calibrateIs(iis_A,BTT6030.kilis,BTT6030.ampsOffset, BTT6030.ampsGain);
            }
  
        case 1:
            if(CHANNEL0 == ch)
            {
                adcResult = hss2->readIs();
                vis_V = ((float)adcResult/(float)1024) * (float)5;
                iis_A = vis_V/ris_Ohm;
                iisCalib = hss2->calibrateIs(iis_A,BTT6030.kilis,BTT6030.ampsOffset, BTT6030.ampsGain);
            }
            if(CHANNEL1 == ch)
            {
                adcResult = hss3->readIs();
                vis_V = ((float)adcResult/(float)1024) * (float)5;
                iis_A = vis_V/ris_Ohm;
                iisCalib = hss3->calibrateIs(iis_A,BTT6030.kilis,BTT6030.ampsOffset, BTT6030.ampsGain);
            }
            
        case 2:
            adcResult = hss2->readIs();
            vis_V = ((float)adcResult/(float)1024) * (float)5;
            iis_A = vis_V/ris_Ohm;
            iisCalib = hss4->calibrateIs(iis_A,BTT6020.kilis,BTT6020.ampsOffset, BTT6020.ampsGain);
    }
    return iisCalib;
}

/**
 * @brief Read the diagnosis of the chosen channel
 * 
 * This function uses the current signal of the channel to diagnose the channel.
 * It returns the different states depending on the channels condition.
 * 
 * @param[in]   x   Desired channel for the diagnosis (1-4)   
 * @return      Profet24VBTTShield::DiagStatus_t
 * 
 * @retval      0   Everything works correctly
 * @retval      2   Short to ground
 * @retval      4   Short to battery
 * @retval      5   Open load     
 */
DiagStatus_t Profet24VBTTShield::readDiagx(uint8_t x,Channel_t ch)
{
    DiagStatus_t diagStatus = NORMAL;

    float currentOn = 0.0;
    float currentOff = 0.0;

    switch(x)
    {
        case 0:
        if(CHANNEL0 == ch)
        {
            hss0->enableDiag();
            if(hss0->getSwitchStatus() == POWER_ON)
            {
                diagStatus = hss0->diagRead(getIs(0,ch), BTT6030.kilis);
            }
            hss0->disableDiag();
        }
        
        if(CHANNEL1 == ch)
        {
            hss1->enableDiag();
            if(hss1->getSwitchStatus() == POWER_ON)
            {
                diagStatus = hss1->diagRead(getIs(0,ch), BTT6030.kilis);
            }
            hss1->disableDiag();
        }
        break;

        case 1:
        if(CHANNEL0 == ch)
        {
            hss2->enableDiag();
            if(hss2->getSwitchStatus() == POWER_ON)
            {
                diagStatus = hss2->diagRead(getIs(1,ch), BTT6030.kilis);
            }
            hss2->disableDiag();
        }

        if(CHANNEL1== ch)
        {
            hss3->enableDiag();
            if(hss3->getSwitchStatus() == POWER_ON)
            {
                diagStatus = hss3->diagRead(getIs(1,ch), BTT6030.kilis);
            }
            hss2->disableDiag();
        }   
        break;

        case 2:
            hss4->enableDiag();
            if(hss4->getSwitchStatus() == POWER_ON)
            {
                diagStatus = hss4->diagRead(getIs(2), BTT6020.kilis);
            }
            hss4->disableDiag();
            break;
    }
    return diagStatus;
}
/**
 * @brief Calculates the diagnosis state
 * 
 * This functions determines the diagnosis state of the High-Side-Switch.
 * It uses the measrued currents with en- and disabled Open-Load-Detection.
 * 
 * @param[in]   currentOn   Measrued current with Open-Load-Detection on 
 * @param[in]   currentOff  Measrued current with Open-Load-Detection off 
 * @return      DiagStatus_t 
 */
DiagStatus_t Profet24VBTTShield::diagnosisOff(float currentOn, float currentOff)
{
    if((currentOn > (0.0018 * BTT6030.kilis)) && (currentOn < (0.0044 * BTT6030.kilis))){
        if((currentOff > (0.0018 * BTT6030.kilis)) && (currentOff < (0.0044 * BTT6030.kilis))){
            return DiagStatus_t::SHORT_TO_VSS;
        }
        else{
            return DiagStatus_t::OPEN_LOAD;
        }
    }
    else{
        if((currentOn > (0.0044 * BTT6030.kilis))){
            return DiagStatus_t::SHORT_TO_GND;
        }
        else{
            return DiagStatus_t::NORMAL;
        }
    }
}