/** 
 * @file        hss.cpp
 * @brief       Definition of the High-Side-Switch class functions
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */


#include <Arduino.h>
#include <stdint.h>
#include "hss.hpp"

/**
 * @brief High-Side-Switch default constructor
 *          
 * Initialize all protected class pointers with a null pointer.
 * Also sets the class variables into a default state
 */
Hss::Hss()
{
    den = NULL;
    in = NULL;
    pwm = NULL;
    is = NULL;

    timer = NULL;

    currentFilter = NULL;

    btsVariant = NULL;
    status = UNINITED;
    diagEnb = DIAG_DIS;
    diagStatus = NOT_ENABLED;

    pwmMode = false;
}

/**
 * @brief High-Side-Switch constructor
 * 
 * This constructor is used to define all necessary pins and the variant
 * of the PROFET.
 * 
 * @param[in]   den         Pin number of DEN 
 * @param[in]   in          Pin number of IN
 * @param[in]   is          Pin number of IS
 * @param[in]   variant     Variant of the BTS700x
 */
Hss::Hss(GPIO *den, GPIO *in, AnalogDigitalConverter *is, BtsVariants_t *variant)
{
    this->den = den;
    this->in = in;
    this->pwm = NULL;
    this->is = is;

    timer = NULL;

    currentFilter = NULL;

    btsVariant = variant;
    status = UNINITED;
    diagEnb = DIAG_DIS;
    diagStatus = NOT_ENABLED;
    pwmMode = false;
}

/**
 * @brief High-Side-Switch constructor
 * 
 * This constructor is used to define all necessary pins and the variant
 * of the PROFET.
 * 
 * @param[in]   den         Pin number of DEN 
 * @param[in]   pwm         PWM instance
 * @param[in]   is          Pin number of IS
 * @param[in]   variant     Variant of the BTS700x
 */
Hss::Hss(GPIO *den, PWM *pwm, AnalogDigitalConverter *is, BtsVariants_t *variant)
{
    this->den = den;
    this->in = NULL;
    this->pwm = pwm;
    this->is = is;

    timer = NULL;

    currentFilter = NULL;

    btsVariant = variant;
    status = UNINITED;
    diagEnb = DIAG_DIS;
    diagStatus = NOT_ENABLED;
    pwmMode = false;
}

/**
 * @brief Destructor of the High-Side-Switch class
 * 
 */
Hss::~Hss()
{
    den = NULL;
    in = NULL;
    pwm = NULL;
    is = NULL;

    timer = NULL;

    currentFilter = NULL;

    status = UNINITED;
    diagEnb = DIAG_DIS;
    diagStatus = NOT_ENABLED;

    pwmMode = false;
}

/**
 * @brief Initialize the High-Side-Switch
 * 
 * This function initializes all necessary objects of the High-Side-Switch.
 * It retruns an error code to see if everything was initialized correctly.
 * 
 * @return Hss::Error_t 
 */
Hss::Error_t Hss::init()
{
    Error_t err = OK;

    if(NULL != den)
    {
        den->init();
    }
        
    if(NULL != in)
    {
        in->init();
    }

    if(NULL != pwm)
    {
        pwm->init();
    }

    if(NULL != in)
    {
        is->init();
    }

    if(NULL != timer)
    {
        timer->init();
    }

    currentFilter = new ExponentialFilter(0.0, 0.3);

    status = INITED;
    return err;
}

/**
 * @brief Deinitialize the High-Side-Switch
 * 
 * @return Hss::Error_t 
 */
Hss::Error_t Hss::deinit()
{
    Error_t err = OK;

    if(NULL != den)
    {
        den->deinit();
    }

    if(NULL != in)
    {
        in->deinit();
    }

    if(NULL != pwm)
    {
        pwm->deinit();
    }

    if(NULL != is)
    { 
        is->deinit();
    }

    if(NULL != timer)
    {
        timer->deinit();
    }

    status = UNINITED;
    return err;
}

/**
 * @brief Configures the PWM signal to be applied to the the High-Side-Switch input 
 * 
 * This function will enable the pwm mode if a pwm instance was provided
 * in the constructor
 * 
 * @param[in]   freq    PWM frequency (in Hz)
 * @param[in]   duty    PWM duty cycle (in percentage XX.X).
 *                      From 0.00 to 100.00.
 * 
 * @return Hss::Error_t 
 */
Hss::Error_t  Hss::configPWM(uint32_t freq, float duty)
{
    Error_t err = OK;

    if(NULL != pwm)
    {
        pwmMode = true;
        pwm->config(freq, duty);
    }

    return err;
}

/**
 * @brief Enable the High-Side-Switch
 * 
 * This function is turning on the High-Side-Switch.
 * It is also setting the status of the switch to ON.
 * 
 * @return Hss::Error_t 
 */
Hss::Error_t Hss::enable()
{
    Error_t err = OK;
    
    if( NULL != in)
    {
        in->enable();
    }
    else if(NULL != pwm && pwmMode)
    {
        pwm->enable();
    }

    status = POWER_ON;
    return err;
}

/**
 * @brief Disable the High-Side-Switch
 * 
 * This function turns off the High-Side-Switch.
 * It is also setting the status of the switch to OFF.
 * 
 * @return Hss::Error_t 
 */
Hss::Error_t Hss::disable()
{
    Error_t err = OK;

    if( NULL != in)
    {
        in->disable();
    }
    else if(NULL != pwm && pwmMode)
    {
        pwm->disable();
    }

    status = POWER_OFF;
    return err;
}

/**
 * @brief Enable diagnosis function
 * 
 * This funtion is enabling the diagnosis function of the High-Side-Switch.
 * 
 * @return Hss::Error_t 
 */
Hss::Error_t Hss::enableDiag()
{
    Error_t err = OK;

    if( NULL != den)
    {
        den->enable();
    }

    diagEnb = DIAG_EN;
    return err;
}

/**
 * @brief Disable diagnosis function
 * 
 * This function is disabling the diagnosis function of the High-Side-Switch.
 * 
 * @return Hss::Error_t 
 */
Hss::Error_t Hss::disableDiag()
{
    Error_t err = OK;

    if( NULL != den)
    {
        den->disable();
    }

    diagEnb = DIAG_DIS;
    return err;
}

/**
 * @brief Reset the diagnostic
 * 
 * This function resets the diagnostic function of the switch.
 * Any error, for example an overcurrent event, will set the internal
 * latch of the switch to "1". This function is reseting the latch.
 * 
 * @return Hss::Error_t 
 */
Hss::Error_t Hss::diagReset()
{
    Error_t err = OK;

    if( NULL != in)
    {
        in->disable();
    }

    if( NULL != timer)
    {
        timer->delayMilli(100);
    }

    if( NULL != in)
    {
        in->enable();
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
Hss::Status_t Hss::getSwitchStatus()
{
    return status;
}

/**
 * @brief Read IS
 * 
 * This functions is reading the IS signal of the switch.
 * It returns the calculated current, which is depending on the IS signal.
 * 
 * @return Value of the current flowing through the switch in [A] 
 */
float Hss::readIs()
{
    uint16_t AnalogDigitalConverterResult = 0;
    float amps = 0.0;

    if(diagEnb == DIAG_EN && NULL != is){
        timer->delayMilli(1);                                                       //wait for 1ms to ensure that the Profet will provide a valid sense signal
        AnalogDigitalConverterResult = is->ADCRead();
        amps = ((float)AnalogDigitalConverterResult/(float)1024) * (float)5;
        amps = (amps * btsVariant->kilis)/1000;
        amps = (amps - btsVariant->ampsOffset) * btsVariant->ampsGain;
        currentFilter->input(amps);
    }
    return currentFilter->output();
}

/**
 * @brief Diagnosis of the Sensor
 * 
 * This function is using the IS signal to determine the state of the switch.
 * It returns an diagnosis state of the switch.
 * 
 * @return Hss::DiagStatus_t
 * 
 * @retval  -2  Not enabled
 * @retval  0   Switch is working fine
 * @retval  1   Overload detected 
 * @retval  5   Open load detected
 
 */
Hss::DiagStatus_t Hss::diagRead()
{
    uint16_t AnalogDigitalConverterResult = 0;
    float amps = 0.0;

    if(diagEnb == DIAG_EN){
        amps = readIs();
        
        if(amps > (0.0044*btsVariant->kilis)){
            return Hss::DiagStatus_t::OVERLOAD;
        }
        else if(amps < (0.00002*btsVariant->kilis)){
            return Hss::DiagStatus_t::OPEN_LOAD;
        }
        else{
            return Hss::DiagStatus_t::NORMAL;
        }
    }

    else{
        return Hss::DiagStatus_t::NOT_ENABLED;
    }

    return diagStatus;
}


