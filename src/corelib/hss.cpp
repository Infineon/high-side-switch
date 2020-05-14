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
 * @addtogroup hallswitchcpphal
 * @{
 */

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
    is = NULL;

    timer = NULL;

    currentFilter = NULL;

    btsVariant = NULL;
    status = UNINITED;
    diagEnb = DIAG_DIS;
    diagStatus = NOT_ENABLED;
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
    this->is = is;

    timer = NULL;

    currentFilter = NULL;

    btsVariant = variant;
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
 * @return Hss::Error_t 
 */
Hss::Error_t Hss::init()
{
    Error_t err = OK;

    den->init();
    in->init();
    is->init();

    timer->init();

    currentFilter = new ExponentialFilter(0.0, 0.3);

    status = INITED;
    // if(den->checkErrorStatus() != OK && in->checkErrorStatus() != OK
    // && is->checkErrorStatus() != OK) return err = CONF_ERROR;                  //Only return Error if something went wrong
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

    den->deinit();
    in->deinit();
    is->deinit();
    
    timer->deinit();
    //if(den->checkErrorStatus() != OK && in->checkErrorStatus() != OK
    //&& is->checkErrorStatus() != OK) return err = CONF_ERROR;                  //Only return Error if something went wrong
    
    status = UNINITED;
    return err;
}

/**
 * @brief Enable the High-Side-Switch
 * 
 * This function is turning on the High-Side-Switch.
 * If no dutycycle is set, the dutycycle is set to 100%
 * It is also setting the status of the switch to ON.
 * 
 * @return Hss::Error_t 
 */
Hss::Error_t Hss::enable(uint8_t dutycycle = NULL)
{
    Error_t err = OK;
    
    if(dutycycle == NULL){
        in->enable();
    }
    // else
    // {
    //    // in->writePWM(dutycycle);
    // }
    //if(in->checkErrorStatus() != OK) return err = CONF_ERROR;
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

    in->disable();
    //if(in->checkErrorStatus() != OK) return err = CONF_ERROR;

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

    den->enable();
    //if(den->checkErrorStatus() != OK) return err = CONF_ERROR;
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

    den->disable();
    //if(den->checkErrorStatus() != OK) return err = CONF_ERROR;

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

    in->disable();
    //if(in->checkErrorStatus() != OK) return err = CONF_ERROR;
    timer->delayMilli(100);
    in->enable();
    //if(in->checkErrorStatus() != OK) return err = CONF_ERROR;

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

    if(diagEnb == DIAG_EN){
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


