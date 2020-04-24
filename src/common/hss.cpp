/** 
 * @file        hss.cpp
 * @brief       High Side Switch Hardware Abstraction Layer
 *              Features: 
 * 
 * @date        March 2020
 * @copyright   Copyright (c) 2020 Infineon Technologies AG
 */

#include "hss.h"


/**
 * @addtogroup hallswitchcpphal
 * @{
 */

/**
 * @brief High Side Switch default constructor
 *          
 * 
 */

Hss::Hss()
{
    den = NULL;
    in = NULL;
    is = NULL;
    btsVariant = NULL;
    status = UNINITED;
    diagEnb = DIAG_DIS;
    diagStatus = NOT_ENABLED;
}

Hss::Hss(GPIO *den, GPIO *in, ADC *is, BtsVariants_t *variant)
{
    this->den = den;
    this->in = in;
    this->is = is;
    btsVariant = variant;
    status = UNINITED;
    diagEnb = DIAG_DIS;
    diagStatus = NOT_ENABLED;
}

Hss::~Hss()
{
    den = NULL;
    in = NULL;
    is = NULL;
    status = UNINITED;
    diagEnb = DIAG_DIS;
    diagStatus = NOT_ENABLED;
}

Hss::Error_t Hss::init()
{
    Error_t err = OK;

    den->init();
    in->init();
    is->init();

    status = INITED;
    if(den->checkErrorStatus() != OK && in->checkErrorStatus() != OK
    && is->checkErrorStatus() != OK) return err = CONF_ERROR;                  //Only return Error if something went wrong

    return err;
}

Hss::Error_t Hss::deinit()
{
    Error_t err = OK;

    den->deinit();
    in->deinit();
    is->deinit();
    
    
    if(den->checkErrorStatus() != OK && in->checkErrorStatus() != OK
    && is->checkErrorStatus() != OK) return err = CONF_ERROR;                  //Only return Error if something went wrong
    
    status = UNINITED;
    return err;
}

Hss::Error_t Hss::enable()
{
    Error_t err = OK;

    in->enable();

    if(in->checkErrorStatus() != OK) return err = CONF_ERROR;

    status = POWER_ON;
    return err;
}

Hss::Error_t Hss::disable()
{
    Error_t err = OK;

    in->disable();
    if(in->checkErrorStatus() != OK) return err = CONF_ERROR;

    status = POWER_OFF;
    return err;
}

Hss::Error_t Hss::enableDiag()
{
    Error_t err = OK;

    den->enable();
    //if(den->checkErrorStatus() != OK) return err = CONF_ERROR;
    
    diagEnb = DIAG_EN;
    return err;
}

Hss::Error_t Hss::disableDiag()
{
    Error_t err = OK;

    den->disable();
    if(den->checkErrorStatus() != OK) return err = CONF_ERROR;

    diagEnb = DIAG_DIS;
    return err;
}

Hss::Error_t Hss::diagReset()
{
    Error_t err = OK;

    in->disable();
    if(in->checkErrorStatus() != OK) return err = CONF_ERROR;
    sleep(100);
    in->enable();
    if(in->checkErrorStatus() != OK) return err = CONF_ERROR;

    return err;
}

float Hss::readIs()
{
    uint16_t ADCResult = 0;
    float amps = 0.0;

    if(diagEnb == DIAG_EN){
        delay(1);                                                       //wait for 1ms to ensure that the Profet will provide a valid sense signal
        ADCResult = is->ADCRead();

        amps = float(ADCResult/4096) * 5.0;
        amps = (amps * btsVariant->kilis)/1000;
        amps = (amps - btsVariant->ampsOffset) * btsVariant->ampsGain;
        //TODO: Include filter for the current measurement
    }
    return amps;
}

Hss::DiagStatus_t Hss::diagRead()
{
    uint16_t ADCResult = 0;
    float amps = 0.0;

    if(diagEnb == DIAG_EN){
        delay(1);                                                       //wait for 1ms to ensure that the Profet will provide a valid sense signal
        ADCResult = is->ADCRead();

        amps = float(ADCResult/4096) * 5.0;
        amps = (amps * btsVariant->kilis)/1000;
        amps = (amps - btsVariant->ampsOffset) * btsVariant->ampsGain;
        //TODO: Include Filter

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


