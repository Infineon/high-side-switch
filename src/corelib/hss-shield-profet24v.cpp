/**
 * @file        hss-shield-profet24V.cpp
 * @brief       Profet (24V) Shield with BTT6030-2EKA and BTT6020-1EKA Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "hss-shield-profet24v.hpp"

using namespace hss;

/**
 * @brief   Profet 24V BTT6030 Shield constructor
 */
Profet24VBTTShield::Profet24VBTTShield(Hss *hsw0, Hss *hsw1, Hss *hsw2)
{
    switches[0] = hsw0;
    switches[0] = hsw1;
    switches[0] = hsw2;
}

/**
 * @brief   Destructor of the Profet 24V Shield
 *
 */
Profet24VBTTShield::~Profet24VBTTShield()
{

}

/**
 * @brief   Initialize all necessary objects of the Profet 24V Shield
 *
 * This function initializes all necessary objects of the Profet 24V Shield.
 * It returns an error code to see if everything was initialized correctly.
 *
 * @return  Error_t
 */
Error_t Profet24VBTTShield::init()
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

/**
 * @brief   Deinitialize all necessary objects of the Profet 24V Shield
 *
 * This function deinitializes all necessary objects of the Profet 24V Shield.
 * It retruns an error code to see if everything was deinitialized correctly.
 *
 * @return Profet24VShield::Error_t
 */
Error_t Profet24VBTTShield::deinit()
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

/**
 * @brief Switch on the selected High-Side-Switch
 *
 * This function turns on the desired High-Side-Switch.
 *
 * @param[in]   x    Number of the Switch the should be turned on (0-4). Possible values:
 *                    Switch 0    -   Profet 0 (BTT6030 - channel 0)
 *                    Switch 1    -   Profet 0 (BTT6030 - channel 1)
 *                    Switch 2    -   Profet 1 (BTT6030 - channel 0)
 *                    Switch 3    -   Profet 1 (BTT6030 - channel 1)
 *                    Switch 4    -   Profet 2 (Single channel)
 *
 * @return          Error_t
 */
Error_t Profet24VBTTShield::switchHxOn(uint8_t x)
{
    Error_t err = OK;

    Channel_t ch = (Channel_t)(x % 2);
    uint8_t hss  = x/2;
    HSS_ASSERT_NULLPTR(switches[hss]);
    err = switches[hss]->enable(ch);

    return err;
}

/**
 * @brief   Switch off the selected High-Side-Switch
 *
 * This function turns off the desired High-Side-Switch.
 *
 * @param[in]   x    Number of the Switch the should be turned on (0-4). Possible values:
 *                    Switch 0    -   Profet 0 (BTT6030 - channel 0)
 *                    Switch 1    -   Profet 0 (BTT6030 - channel 1)
 *                    Switch 2    -   Profet 1 (BTT6030 - channel 0)
 *                    Switch 3    -   Profet 1 (BTT6030 - channel 1)
 *                    Switch 4    -   Profet 2 (Single channel)
 *
 * @return          Error_t
 */
Error_t Profet24VBTTShield::switchHxOff(uint8_t x)
{
    Error_t err = OK;

    Channel_t ch = (Channel_t)(x % 2);
    uint8_t hss  = x/2;
    HSS_ASSERT_NULLPTR(switches[x]);
    err = switches[hss]->disable(ch);

    return err;
}

/**
 * @brief Turn on the selected High-Side-Switches
 *
 * This function is used to enable multiple switches at once.
 *
 * @param[in] h0_0    Enable the Switch 0 - channel 0 if h0_0 = true
 * @param[in] h1_0    Enable the Switch 0 - channel 1 if h1_0 = true
 * @param[in] h0_1    Enable the Switch 1 - channel 0 if h0_1 = true
 * @param[in] h1_1    Enable the Switch 1 - channel 1 if h1_1 = true
 * @param[in] h2      Enable the Switch 2 - channel 0 if h2   = true
 *
 * @return            Error_t
 */
Error_t Profet24VBTTShield::switchesHxOn(bool h0_0, bool h1_0, bool h0_1, bool h1_1, bool h2)
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

/**
 * @brief Turn off the selected High-Side-Switches
 *
 * This function is used to disable multiple switches at once.
 *
 * @param[in] h0_0    Disable the Switch 0 - channel 0 if h0_0 = true
 * @param[in] h1_0    Disable the Switch 0 - channel 1 if h1_0 = true
 * @param[in] h0_1    Disable the Switch 1 - channel 0 if h0_1 = true
 * @param[in] h1_1    Disable the Switch 1 - channel 1 if h1_1 = true
 * @param[in] h2      Disable the Switch 2 - channel 0 if h2   = true
 *
 * @return          Error_t
 */
Error_t Profet24VBTTShield::switchesHxOff(bool h0_0, bool h1_0, bool h0_1, bool h1_1, bool h2)
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

/**
 * @brief Read the desired current value of the chosen channel
 *
 * This function:
 *      - Enables diagnosis for the channel
 *      - Selects the channel through dsel
 *      - Calls function to get the calibrated sensed current value on chosen channel
 *      - Disables diagnosis pin post operation completion
 *
 * @param[in]   x    Number of the Switch the should be turned on (0-4). Possible values:
 *                    Switch 0    -   Profet 0 (BTT6030 - channel 0)
 *                    Switch 1    -   Profet 0 (BTT6030 - channel 1)
 *                    Switch 2    -   Profet 1 (BTT6030 - channel 0)
 *                    Switch 3    -   Profet 1 (BTT6030 - channel 1)
 *                    Switch 4    -   Profet 2 (Single channel)
 * @return          The calibrated value of the current in [A]
 */
float Profet24VBTTShield::readIsx(uint8_t x)
{
    float iisCalib;
    uint8_t hss = x/2;

    HSS_ASSERT_NULLPTR(switches[hss]);
    switches[hss]->enableDiag();
    iisCalib = getIs(x);
    switches[hss]->disableDiag();

    return iisCalib;
}

/**
 * @brief   Get Is value
 *
 * This function:
 *  - Reads the IS pin of the chosen High-Side-Switch to get ADC stored value
 *  - Converts raw ADC value to voltage and in-turn to sensed current
 *  - Performs current calibration
 *
 * @param[in]   x    Number of the Switch the should be turned on (0-4). Possible values:
 *                    Switch 0    -   Profet 0 (BTT6030 - channel 0)
 *                    Switch 1    -   Profet 0 (BTT6030 - channel 1)
 *                    Switch 2    -   Profet 1 (BTT6030 - channel 0)
 *                    Switch 3    -   Profet 1 (BTT6030 - channel 1)
 *                    Switch 4    -   Profet 2 (Single channel)
 *
 * @param[out]  iisCalib    Calibrated sensed current value
 *
 * @return          Error_t
 */
float  Profet24VBTTShield::getIs(uint8_t x)
{
    uint16_t adcResult;
    float iis_A, vis_V, iisCalib;
    BtxVariants_t * v;

    Channel_t ch = (Channel_t)(x % 2);
    uint8_t hss  = x/2;

    if(4 == x)
    {
        v  = &BTT6020;
    }
    else
    {
        v  = &BTT6030;
    }

    // adcResult = switches[hss]->readIs(ch);
    vis_V = ((float)adcResult/(float)1024) * (float)5;
    iis_A = vis_V/ris_Ohm;
    iisCalib = 0; //switches[hss]->calibrateIs(iis_A,v.kilis,v.ampsOffset, v.ampsGain);

    return iisCalib;
}

/**
 * @brief Read the diagnosis of the chosen channel
 *
 * This function uses the current signal of the channel to diagnose perform diagnosis.
 * It returns the different states depending on the channels condition.
 *
 * @param[in]   x           Number of the Switch the should be turned on (0-4). Possible values:
 *                          Switch 0    -   Profet 0 (BTT6030 - channel 0)
 *                          Switch 1    -   Profet 0 (BTT6030 - channel 1)
 *                          Switch 2    -   Profet 1 (BTT6030 - channel 0)
 *                          Switch 3    -   Profet 1 (BTT6030 - channel 1)
 *                          Switch 4    -   Profet 2 (Single channel)
 *
 * @return      DiagStatus_t
 *
 * @retval      0   Everything works correctly
 * @retval      2   Short to ground
 * @retval      4   Short to battery
 * @retval      5   Open load
 */
DiagStatus_t Profet24VBTTShield::readDiagx(uint8_t x)
{
    DiagStatus_t diagStatus = NORMAL;
    BtxVariants_t * v;
    float iisOl;

    uint8_t hss  = x/2;

    if(4 == x)
    {
        iisOl = iisOl_btt6020;
        v  = &BTT6020;
    }
    else
    {
        iisOl = iisOl_btt6030;
        v  = &BTT6030;
    }
    switches[hss]->enableDiag();
    if(switches[hss]->getSwitchStatus() == POWER_ON){
        diagStatus = NORMAL; //switches[hss]->diagRead(getIs(ch), iisFault, iisOl, BTT6030.kilis, CHANNEL0);
    }
    switches[hss]->disableDiag();

    return diagStatus;
}