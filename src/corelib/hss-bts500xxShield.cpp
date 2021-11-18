/** 
 * @file        hss-bts500xxShield.cpp
 * @brief       BTS500xx (12V) Shield Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "hss-bts500xxShield.hpp"

using namespace hss;

/**
 * @brief High-Side-Switch-Board constructor
 * Initialize all protected class pointers with a null pointer.
 */
Bts500xxShield::Bts500xxShield(Hss *hsw1)
{
    this->hss1 = hsw1;
}

/**
 * @brief Destructor of the High-Side-Switch-Board
 * 
 */
Bts500xxShield::~Bts500xxShield()
{

}

/**
 * @brief Initialize all necessary objects of the High-Side-Switch-Board
 * 
 * This function initializes all necessary objects of the High-Side-Switch-Board.
 * It retruns an error code to see if everything was initialized correctly.
 * 
 * @return Bts500xxShield::Error_t
 */
Error_t Bts500xxShield::init()
{
    Error_t err= OK;
     do
    {
        if(nullptr != led1)
        {
            err = led1->init();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

          if(nullptr != led2)
        {
            err = led2->init();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

        err= hss1->init();
            if (OK!=err)
            {
                break;
            }

       
    
        if(nullptr != pushButtonAnalog)
        {
            err = pushButtonAnalog->init();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != vBat)
        {
            err = vBat->init();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

    }
    while(0);

    return OK;
}

/**
 * @brief Deinitialize all necessary objects of the High-Side-Switch-Board
 * 
 * This function deinitializes all necessary objects of the High-Side-Switch-Board.
 * It retruns an error code to see if everything was deinitialized correctly.
 * 
 * @return Bts500xxShield::Error_t
 */
Error_t Bts500xxShield::deinit()
{

    Error_t err= OK;
     do
    {
        if(nullptr != led1)
        {
            err = led1->deinit();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

          if(nullptr != led2)
        {
            err = led2->deinit();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

        err= hss1->deinit();
            if (OK!=err)
            {
                break;
            }

       
    
        if(nullptr != pushButtonAnalog)
        {
            err = pushButtonAnalog->deinit();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

        if(nullptr != vBat)
        {
            err = vBat->deinit();
            if(OK!=err)
                break;
        }
        else
        {
            err = NULLPTR_ERROR;
            break;
        }

    }
    while(0);

    return OK;
}

/**
 * @brief Switch on the selected High-Side-Switch
 * 
 * This function turns on the desired High-Side-Switch.
 * It also turns on the corresponding LED of the switch.
 * 
 * @param[in]   x   Number of the Switch the should be turned on (1-4)      
 * @return          Bts500xxShield::Error_t 
 */
Error_t Bts500xxShield::switchHxOn(uint8_t x)
{
           Error_t err= OK;
            err=hss1->enable();
            if (NULL != led1)
                led1->enable();
       
    return err;
}

/**
 * @brief Switch off the selected High-Side-Switch
 * 
 * This function turns off the desired High-Side-Switch.
 * It also turns off the corresponding LED of the switch.
 * 
 * @param[in]   x   Number of the Switch the should be turned off (1-4)  
 * @return          Bts500xxShield::Error_t 
 */
Error_t Bts500xxShield::switchHxOff(uint8_t x)
{
    Error_t err= OK;
    err= hss1->disable();
    if (NULL != led1)
        led1->disable();    
    return err;
}


/**
 * @brief Read the desired current value of the chosen channel
 * 
 * This function reads the IS pin of the chosen High-Side-Switch
 * and calculates the current which is flowing through the switch
 * with the acquired ADC value.
 * 
 * @param[in]   x   Number of the desired channel (1)
 * @return          The value of the current in [A]      
 */
float Bts500xxShield::readIsx(uint8_t x)
{
    float isVal;
   
            hss1->enableDiag();
            isVal = getIs();
            hss1->disableDiag();
        
      
    return isVal;
}

/**
 * @brief Read the desired current value of the chosen channel
 * 
 * This function reads the IS pin of the chosen High-Side-Switch
 * and calculates the current which is flowing through the switch
 * with the acquired ADC value.
 * 
 * @return          The value of the current in [A]      
 */
float Bts500xxShield::getIs(uint8_t x)
{
    uint16_t adcResult;
    float amps, ampsCalib;
        
            adcResult = hss1->readIs();
            amps = ((float)adcResult/(float)1024) * (float)5;
            ampsCalib = hss1->calibrateIs(amps, btsVariant->kilis, btsVariant->ampsOffset, btsVariant->ampsGain);

    return ampsCalib;
}


/**
 * @brief Read the diagnosis of the chosen channel
 * 
 * This function uses the current signal of the channel to diagnose the channel.
 * It returns the different states depending on the channels condition.
 * 
 * @param[in]   x   Desired channel for the diagnosis (1)   
 * @return      Bts500xxShield::DiagStatus_t
 * 
 * @retval  -2  Not enabled
 * @retval  0   Switch is working fine
 * @retval  2   Short circuit to ground 
 * @retval  4   Short circuit to Vs
 * @retval  5   Open load detected  
 */
DiagStatus_t Bts500xxShield::readDiagx(uint8_t x)
{
    DiagStatus_t diagStatus = NORMAL;

    float currentOn = 0.0;

            if(hss1->getSwitchStatus() == POWER_ON){
                float vs=readVss();
                float vis=getIs();
                float v=vs-vis;
                if(v>5 || v=5)
                {
                    diagStatus = diagRead(vis);
                }
    }

    return diagStatus;
}


/**
 * @brief Reads the batter voltage
 * 
 * This functions is reading the attached voltage at the Profet-Board.
 * 
 * @return Value of the battery voltage in [V]
 */
float Bts500xxShield::readVss()
{
    uint16_t adcResult = 0;
    float voltage = 0.0;
    
    adcResult = vBat->ADCRead();
    voltage = adcResult * ((float)5/(float)1024);  // Vmax/1024 LSB = Resolution of the ADC, 57/10 = Reverse Voltage devider to get the Supplyvoltage
    voltage = (voltage - vBatOffset) * vBatGain;
    voltage = voltage * ((float)57/(float)10);

    filterVbat->input(voltage);
    
    return filterVbat->output();
}

bool Bts500xxShield::analogReadButton()
{
    uint16_t result = 0;

    result = pushButtonAnalog->ADCRead();
    if(result < 20){
        return true;
    }
    else{
        return false;
    }
}

/**
 * @brief Diagnosis of the Sensor
 * 
 * This function is using the IS signal to determine the state of the switch.
 * It returns an diagnosis state of the switch.
 * 
 * @param[in]   volt       Sensed voltage value from Iis pin

 * @return DiagStatus_t
 * 
 * @retval  -2  Not enabled
 * @retval  0   Switch is working fine
 * @retval  2   Short circuit to ground 
 * @retval  4   Short circuit to Vs
 * @retval  5   Open load detected
 * 
 * @note    This function should be called only after you get the Is value. 
 *          Also note, in case you are using shield with no channel differentiation, 
 *          then ignore the 'ch' parameter and this will default to NO_CHANNEL. 
 */
DiagStatus_t Bts500xxShield::diagRead(float volt)
{
    
   
        if(volt>IisFault){
            return DiagStatus_t::SHORT_TO_GND;
        }
        else if(volt<(Il/btsVariant->kilis))
        {
            return DiagStatus_t::SHORT_TO_VSS;
        }
        else if(volt==Iiso)
        {
            return DiagStatus_t::OPEN_LOAD;
        }
        else{
            return DiagStatus_t::NORMAL;
        }

    return diagStatus;
}