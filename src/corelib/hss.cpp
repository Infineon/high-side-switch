/**
 * @file        hss.cpp
 * @brief       Definition of the High-Side-Switch class functions
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include <stdint.h>
#include "hss.hpp"

using namespace hss;

/**
 * @brief High-Side-Switch constructor
 *
 * This constructor is used to define all necessary pins and the variant
 * of the BTS5001x - 12V PROFET.
 *
 * @param[in]   den         Pin number of DEN
 * @param[in]   in          Pin number of IN
 * @param[in]   is          Pin number of IS
 */
Hss::Hss(GPIOPAL *in, ADCPAL *is, TimerPAL *timer)
{
    this->in = in;
    this->is = is;
    this->timer = timer;
    this->den = NULL;
    this->dsel = NULL;

    currentFilter = new ExponentialFilter(0.0, 0.3);

    status = UNINITED;
    diagStatus = NOT_ENABLED;
}

/**
 * @brief High-Side-Switch constructor
 *
 * This constructor is used to define all necessary pins and the variant
 * of the BTS700x - 12V PROFET.
 *
 * @param[in]   den         Pin number of DEN
 * @param[in]   in          Pin number of IN
 * @param[in]   is          Pin number of IS
 */
Hss::Hss(GPIOPAL *den, GPIOPAL *in, ADCPAL *is, TimerPAL *timer)
{
    this->den = den;
    this->in = in;
    this->is = is;
    this->dsel = NULL;

    this->timer = timer;

    currentFilter = new ExponentialFilter(0.0, 0.3);

    status = UNINITED;
    diagEnb = DIAG_DIS;
    diagStatus = NOT_ENABLED;
}

/**
 * @brief High-Side-Switch constructor
 *
 * This constructor is used to define all necessary pins
 * of the 24V PROFET.
 *
 * @param[in]   den         Pin number of DEN
 * @param[in]   in          Pin number of IN
 * @param[in]   dsel        Pin number of dsel
 * @param[in]   is          Pin number of IS
 */
Hss::Hss(GPIOPAL *den, GPIOPAL *in, GPIOPAL *dsel, ADCPAL *is, TimerPAL *timer)
{
    this->den = den;
    this->in = in;
    this->is = is;
    this->dsel = dsel;

    this->timer = timer;

    currentFilter = new ExponentialFilter(0.0, 0.3);

    status = UNINITED;
    diagEnb = DIAG_DIS;
    diagStatus = NOT_ENABLED;
}

/**
 * @brief Destructor of the High-Side-Switch class
 *
 */
Hss::~Hss()
{

}

/**
 * @brief Initialize the High-Side-Switch
 *
 * This function initializes all necessary objects of the High-Side-Switch.
 * It retruns an error code to see if everything was initialized correctly.
 *
 * @return Error_t
 */
Error_t Hss::init()
{
    Error_t err = OK;

    if(nullptr != den)
    {
        err = den->init();
        HSS_ASSERT_RET(err);
    }
    
    HSS_ASSERT_NULLPTR(in);
    err = in->init();
    HSS_ASSERT_RET(err);

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

    status = INITED;

    return err;
}

/**
 * @brief Deinitialize the High-Side-Switch
 *
 * @return Error_t
 */
Error_t Hss::deinit()
{
    Error_t err = OK;

    HSS_ASSERT_NULLPTR(den);
    err = den->deinit();
    HSS_ASSERT_RET(err);

    HSS_ASSERT_NULLPTR(in);
    err = in->deinit();
    HSS_ASSERT_RET(err);

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

    status = UNINITED;

    return err;
}

/**
 * @brief Enable the High-Side-Switch
 *
 * This function is turning on the High-Side-Switch.
 * It is also setting the status of the switch to ON.
 *
 * @return Error_t
 */
Error_t Hss::enable()
{
    Error_t err = OK;

    if(UNINITED != status)
    {
        HSS_ASSERT_NULLPTR(in);
        err = in->enable();
        HSS_ASSERT_RET(err);

        status = POWER_ON;
    }
    else
    {
        err = INIT_ERROR;
    }

    return err;
}

/**
 * @brief Disable the High-Side-Switch
 *
 * This function turns off the High-Side-Switch.
 * It is also setting the status of the switch to OFF.
 *
 * @return Error_t
 */
Error_t Hss::disable()
{
    Error_t err = OK;

    if(UNINITED != status)
    {
        HSS_ASSERT_NULLPTR(in);
        err = in->disable();
        HSS_ASSERT_RET(err);
        status = POWER_OFF;
    }
    else
    {
        err = INIT_ERROR;
    }

    return err;
}

/**
 * @brief Enable diagnosis function
 *
 * This funtion is enabling the diagnosis function of the High-Side-Switch.
 *
 * @return Error_t
 */
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

/**
 * @brief Disable diagnosis function
 *
 * This function is disabling the diagnosis function of the High-Side-Switch.
 *
 * @return Error_t
 */
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

/**
 * @brief Selects diagnosis channel for diagnosis
 *
 * This function is selecting the channel to perform diagnosis
 *
 * @param[in] ch    Channel number (in case of Profet 24V shield)
 * @note   This function is accessed only if the shield is Profet24V
 *
 * @return Error_t
 */
Error_t Hss::selDiagCh(Channel_t ch)
{
    Error_t err = OK;

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

    return err;
}

/**
 * @brief Reset the diagnostic
 *
 * This function resets the diagnostic function of the switch.
 * Any error, for example an overcurrent event, will set the internal
 * latch of the switch to "1". This function is reseting the latch.
 *
 * @return Error_t
 */
Error_t Hss::diagReset()
{
    Error_t err = OK;

    if(UNINITED != status)
    {
        HSS_ASSERT_NULLPTR(in);
        err = in->disable();
        HSS_ASSERT_RET(err);

        HSS_ASSERT_NULLPTR(timer);
        err = timer->delayMilli(100);
        HSS_ASSERT_RET(err);

        err = in->enable();
    }
    else
    {
        err = INIT_ERROR;
    }

    return err;
}

/**
 * @brief Get the switch status
 *
 * This function returns the current status of the switch.
 *
 * @return Hss::Status_t
 *
 * @retval  0   Uninitialized
 * @retval  1   Initialized
 * @retval  2   Power on
 * @retval  3   Power off
 */
Status_t Hss::getSwitchStatus()
{
    return status;
}

/**
 * @brief Read ADC value for IS
 *
 * This functions is reading the IS signal of the switch.
 * It returns the value in ADC, which is depending on the IS signal.
 *
 * @param[in]   ch  Channel number
 *
 * @note Before calling this function, ensure IS pin is initialized and
 *       you do not have to pass channel in case your shield does not support multiple channel
 *       and this would default to NO_CHANNEL applicable.
 *
 * @return Recorded ADC Value
 */
uint16_t Hss::readIs(Channel_t ch)
{
    uint16_t adcResult = 0;

    if(UNINITED != status)
    {
        if(NO_CHANNEL != ch)
        {
            selDiagCh(ch);
        }

        if(diagEnb == DIAG_EN)
        {
            timer->delayMilli(1);          //wait for 1ms to ensure that the Profet will provide a valid sense signal
            adcResult = is->ADCRead();
        }
    }

    return adcResult;
}

/**
 * @brief Calibrates sensed current value
 *
 * This function is performing calibration on sensed current value based on chip parameters
 *
 * @param[in] isVal      Sensed current value to be calibrated
 * @param[in] kilis      Current sense ration of selected chip variant
 * @param[in] ampsOffset Current offset value
 * @param[in] ampsGain   Current gain factor
 *
 * @return Calibrated current value for Is
 *
 * @note This function should be called only after readIs()
 */
float Hss::calibrateIs(float isVal, uint16_t kilis, float ampsOffset, float ampsGain)
{
    float calibVal = 0.0;
    calibVal = (isVal * kilis)/1000;
    calibVal = (calibVal - ampsOffset) * ampsGain;
    currentFilter->input(calibVal);
    return currentFilter->output();
}

/**
 * @brief Diagnosis of the Sensor
 *
 * This function is using the IS signal to determine the state of the switch.
 * It returns an diagnosis state of the switch.
 *
 * @param[in]   amps        Sensed current value
 * @param[in]   iisfault    Sensed current at fault condition
 * @param[in]   iisOl       Open load detection threshold
 * @param[in]   kilis       Current sense ratio
 * @param[in]   ch          Channel no. (*Optional)
 * @return DiagStatus_t
 *
 * @retval  -2  Not enabled
 * @retval  0   Switch is working fine
 * @retval  1   Overload detected
 * @retval  5   Open load detected
 *
 * @note    This function should be called only after you get the Is value.
 *          Also note, in case you are using shield with no channel differentiation,
 *          then ignore the 'ch' parameter and this will default to NO_CHANNEL.
 */
DiagStatus_t Hss::diagRead(float amps, float iisFault, float iisOl, uint16_t kilis, Channel_t ch)
{
    if(NO_CHANNEL != ch){
        selDiagCh(ch);
    }

    if(diagEnb == DIAG_EN)
    {
        if(amps > (iisFault*kilis))
        {
            return OVERLOAD;
        }
        else if(amps < (iisOl*kilis))
        {
            return OPEN_LOAD;
        }
        else
        {
            return NORMAL;
        }
    }
    else
    {
        return NOT_ENABLED;
    }

    return diagStatus;
}