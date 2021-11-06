/** 
 * @file        hss.cpp
 * @brief       Definition of the High-Side-Switch class functions
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */


#include <Arduino.h>
#include <stdint.h>
#include "hss.hpp"

using namespace hss;
/**
 * @brief High-Side-Switch default constructor
 *          
 * Initialize all protected class pointers with a null pointer.
 * Also sets the class variables into a default state
 */
Hss::Hss()
{
    den = NULL;
    in  = NULL;
    is  = NULL;
    timer = NULL;
    currentFilter = NULL;
    status  = UNINITED;
    diagEnb = DIAG_DIS;
    diagStatus = NOT_ENABLED;
}

/**
 * @brief High-Side-Switch constructor
 * 
 * This constructor is used to define all necessary pins and the variant
 * of the 12V PROFET.
 * 
 * @param[in]   den         Pin number of DEN 
 * @param[in]   in          Pin number of IN
 * @param[in]   is          Pin number of IS
 * @param[in]   variant     Variant of the BTS700x
 */
Hss::Hss(GPIO *den, GPIO *in, AnalogDigitalConverter *is)
{
    this->den = den;
    this->in = in;
    this->is = is;

    timer = NULL;

    currentFilter = NULL;

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
 * @param[in]   is          Pin number of IS
 * @param[in]   variant     Variant of the BTS700x
 */
Hss::Hss(GPIO *den, GPIO *in, GPIO *dsel, AnalogDigitalConverter *is)
{
    this->den = den;
    this->in = in;
    this->is = is;
    this->dsel = dsel;

    timer = NULL;

    currentFilter = NULL;

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
    den = NULL;
    in = NULL;
    is = NULL;

    timer = NULL;

    currentFilter = NULL;

    status = UNINITED;
    diagEnb = DIAG_DIS;
    diagStatus = NOT_ENABLED;
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

    do
    {
        if(nullptr != den)
        {
            err = den->init();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != in)
        {
            err = in->init();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != is)
        {
            err = in->init();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != dsel)
        {
            err = dsel->init();
            if(OK!=err)
                break;
        }

        if(nullptr != timer)
        {
            err = timer->init();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }
        
    } while (0);

    currentFilter = new ExponentialFilter(0.0, 0.3);

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

    do
    {
        if(nullptr != den)
        {
            err = den->deinit();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != in)
        {
            err = in->deinit();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != is)
        {
            err = in->deinit();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != dsel)
        {
            err = dsel->deinit();
            if(OK!=err)
                break;
        }

        if(nullptr != timer)
        {
            err = timer->deinit();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }
        
    } while (0);

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
    
    in->enable();

    status = POWER_ON;
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

    in->disable();

    status = POWER_OFF;
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

    den->enable();
    diagEnb = DIAG_EN;
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

    den->disable();

    diagEnb = DIAG_DIS;
    return err;
}

/**
 * @brief Selects diagnosis channel for diagnosis
 * 
 * This function is selecting the channel to perform diagnosis
 * 
 * @return Error_t 
 */
Error_t Hss::selDiagCh(Channel_t ch)
{
    Error_t err = OK;

    if(CHANNEL0 == ch){
        dsel->disable();
    }
    else if(CHANNEL1 == ch){
        dsel->enable();
    }
    else 
        return INVALID_CH_ERROR;
    
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

    in->disable();

    timer->delayMilli(100);
    in->enable();

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
    uint16_t AnalogDigitalConverterResult = 0;

    if(NO_CHANNEL != ch){
        selDiagCh(ch);
    }
    
    if(diagEnb == DIAG_EN){
        timer->delayMilli(1);          //wait for 1ms to ensure that the Profet will provide a valid sense signal
        AnalogDigitalConverterResult = is->ADCRead();
    }
    return AnalogDigitalConverterResult;        
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
        if(amps > (iisFault*kilis)){
            return DiagStatus_t::OVERLOAD;
        }
        else if(amps < (iisOl*kilis)){
            return DiagStatus_t::OPEN_LOAD;
        }
        else{
            return DiagStatus_t::NORMAL;
        }
    }
    else
    {
        return DiagStatus_t::NOT_ENABLED;
    }

    return diagStatus;
}


