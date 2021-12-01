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
 * of the 12V PROFET.
 *
 * @param[in]   den         Pin number of DEN
 * @param[in]   in          Pin number of IN
 * @param[in]   is          Pin number of IS
 */
Hss::Hss(GPIOPAL *den, GPIOPAL *in, ADCPAL *is, TimerPAL *timer, BtxVariants_t *btxVariant)
{
    this->den = den;
    this->in = in;
    this->is = is;
    this->dsel = NULL;

    this->timer = timer;

    this->btxVariant = btxVariant;

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
Hss::Hss(GPIOPAL *den, GPIOPAL *in, GPIOPAL *dsel, ADCPAL *is, TimerPAL *timer, BtxVariants_t *btxVariant)
{
    this->den = den;
    this->in = in;
    this->is = is;
    this->dsel = dsel;

    this->timer = timer;

    this->btxVariant = btxVariant;

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

    HSS_ASSERT_NULLPTR(den);
    err = den->init();
    HSS_ASSERT_RET(err);

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

    HSS_ASSERT_NULLPTR(btxVariant);

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

    HSS_ASSERT_NULLPTR(btxVariant);

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
 * It returns the calculated current, which is depending on the IS signal.
 *
 * @param[in]   rSense  Resistor value of the current sense resistor in [Ohm]
 * @param[in]   ch      Channel number
 *
 * @note Before calling this function, ensure IS pin is initialized and
 *       you do not have to pass channel in case your shield does not support multiple channel
 *       and this would default to NO_CHANNEL applicable.
 *
 * @return Value of the current flowing through the switch in [A]
 */
float Hss::readIs(uint16_t rSense, Channel_t ch)
{
    uint16_t isVoltage = 0;
    float isCurrent = 0;

    if(UNINITED != status)
    {
        if(NO_CHANNEL != ch)
        {
            selDiagCh(ch);
        }

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

/**
 * @brief Diagnosis of the Sensor
 *
 * This function is using the IS signal to determine the state of the switch.
 * It returns an diagnosis state of the switch.
 *
 * @param[in]   senseCurrent    Sensed current value
 * @param[in]   ch              Channel no. (*Optional)
 *
 * @return  DiagStatus_t
 *
 * @retval  -2  Not enabled
 * @retval   0  Switch is working fine
 * @retval   1  Fault condition detected
 *
 * @note    This function should be called only after you get the Is value.
 *          Also note, in case you are using shield with no channel differentiation,
 *          then ignore the 'ch' parameter and this will default to NO_CHANNEL.
 */
DiagStatus_t Hss::diagRead(float senseCurrent, Channel_t ch)
{

    if(NO_CHANNEL != ch){
        selDiagCh(ch);
    }

    if(DIAG_EN == diagEnb)
    {
        if(senseCurrent >= (btxVariant->issFault * btxVariant->kilis)){
            diagStatus = FAULT;
        }
        else if(senseCurrent < (btxVariant->issEn * btxVariant->kilis)){
            diagStatus = FAULT_OL_IC;
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

/**
 * @brief Set current offset
 *
 * This function can be used to change the value of the internal variable
 * of the current offset
 *
 * @param[in]   offset  Desired value of the current offset in [A]
 */
void Hss::setCurrentOffset(float offset)
{
    currentOffset = offset;
}