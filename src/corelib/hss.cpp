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
 * @param[in]   variant     Variant of the BTS700x
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
 * @param[in]   is          Pin number of IS
 * @param[in]   variant     Variant of the BTS700x
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

    do
    {
        if(nullptr != den){
            err = den->init();
            if(OK != err)
            break;
        }

        else{
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != in){
            err = in->init();
            if(OK != err)
            break;
        }
        else{
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != is){
            err = is->init();
            if(OK != err)
            break;
        }
        else{
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != dsel){
            err = dsel->init();
            if(OK != err)
            break;
        }

        if(nullptr != timer){
            err = timer->init();
            if(OK != err)
            break;
        }
        else{
            err = NULLPTR_ERROR;
            break;
        }

        status = INITED;

    } while (0);

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
        if(nullptr != den){
            err = den->deinit();
            if(OK != err)
            break;
        }
        else{
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != in){
            err = in->deinit();
            if(OK != err)
            break;
        }
        else{
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != dsel){
            err = dsel->deinit();
            if(OK != err)
            break;
        }

        if(nullptr != is){
            err = is->deinit();
            if(OK != err)
            break;
        }
        else{
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != timer){
            err = timer->deinit();
            if(OK != err)
            break;
        }
        else{
            err = NULLPTR_ERROR;
            break;
        }

        status = UNINITED;

    } while (0);

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

    if(UNINITED != status){
        if(nullptr != in){
            err = in->enable();

            if(OK != err)
            return err;

            status = POWER_ON;
        }
        else{
            err = NULLPTR_ERROR;
        }
    }
    else{
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

    if(UNINITED != status){
        if(nullptr != in){
            err = in->disable();

            if(OK != err)
            return err;

            status = POWER_OFF;
        }
        else{
            err = NULLPTR_ERROR;
        }
    }
    else{
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

    if(UNINITED != status){
        if(nullptr != den){
            err = den->enable();

            if(OK != err)
            return err;

            diagEnb = DIAG_EN;
        }
        else{
            err = NULLPTR_ERROR;
        }
    }
    else{
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

    if(UNINITED != status){
        if(nullptr != den){
            err = den->disable();

            if(OK != err)
            return err;

            diagEnb = DIAG_DIS;
        }
        else{
            err = NULLPTR_ERROR;
        }
    }
    else{
        err = INIT_ERROR;
    }

    return err;
}

/**
 * @brief Get den status
 *
 * This function is returning the status of diagnosis enable of High-Side-Switch.
 *
 * @return Error_t
 */
DiagEnable_t Hss::getEnDiagStatus()
{
    return diagEnb;
}

/**
 * @brief Enable channel0 for diagnosis
 *
 * This function is setting channel 0 of the chip
 * to perform diagnosis.
 *
 * @return Error_t
 * @note   This function is valid only for chips supporting multiple channels
 */
Error_t Hss::diagSelCh0()
{
    Error_t err = OK;

    if(UNINITED != status){
        if(nullptr != dsel){
            err = dsel->disable();

            if(OK != err)
            return err;
        }
        else{
            err = NULLPTR_ERROR;
        }
    }
    else{
        err = INIT_ERROR;
    }

    return err;
}

/**
 * @brief Enable channel1 for diagnosis
 *
 * This function is setting channel 1 of the chip
 * to perform diagnosis.
 *
 * @return Error_t
 */
Error_t Hss::diagSelCh1()
{
    Error_t err = OK;

    if(UNINITED != status){
        if(nullptr != dsel){
            err = dsel->enable();

            if(OK != err)
            return err;
        }
        else{
            err = NULLPTR_ERROR;
        }
    }
    else{
        err = INIT_ERROR;
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

    if(UNINITED != status){
        do
        {
            if(nullptr != in){
                err = in->disable();

                if(OK != err)
                break;
            }
            else{
                err = NULLPTR_ERROR;
                break;
            }

            if(nullptr != timer){
                err = timer->delayMilli(100);

                if(OK != err)
                break;
            }
            else{
                err = NULLPTR_ERROR;
                break;
            }

            err = in->enable();

        } while (0);
    }
    else{
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
 * @return Recorded ADC Value
 */
uint16_t Hss::readIs()
{
    uint16_t adcRes = 0;

    if(UNINITED != status){
        if(diagEnb == DIAG_EN){
            timer->delayMilli(1);          //wait for 1ms to ensure that the Profet will provide a valid sense signal
            adcRes = is->ADCRead();
        }
    }

    return adcRes;
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
 * @return DiagStatus_t
 *
 * @retval  -2  Not enabled
 * @retval  0   Switch is working fine
 * @retval  1   Overload detected
 * @retval  5   Open load detected
 */
DiagStatus_t Hss::diagRead(float amps, uint16_t kilis)
{
    if(diagEnb == DIAG_EN)
    {
        if(amps > (0.0044*kilis)){
            return DiagStatus_t::OVERLOAD;
        }
        else if(amps < (0.00002*kilis)){
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