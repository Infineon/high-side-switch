/** 
 * @file        hss-bts500xxShield.cpp
 * @brief       BTS700x-1EPP (12V) Shield Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "hss-bts500xxShield.hpp"

/**
 * @brief High-Side-Switch-Board constructor
 * Initialize all protected class pointers with a null pointer.
 */
Bts500xxShield::Bts500xxShield()
{

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
    if (NULL != led1)
    led1->init();
    if (NULL != led2)
    led2->init();
    hss1->init();


    timer->init();
    
    oloff->init();

    pushButtonAnalog->init();
    vBat->init();

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

    if (NULL != led1)
        led1->deinit();
    if (NULL != led2)
        led2->deinit();
   
    hss1->deinit();
   

    timer->deinit();

    oloff->deinit();
    
    pushButtonAnalog->deinit();
    vBat->deinit();

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
            if(x==1)
            {
            hss1->enable();
            if (NULL != led1)
                led1->enable();
             }
        
       
    return OK;
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
Error_t Bts500xxShield::switchHxoff(uint8_t x)
{
            if(x==1)
            {
            hss1->disable();
            if (NULL != led1)
                led1->disable();
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
 * @param[in]   x   Number of the desired channel (1-4)
 * @return          The value of the current in [A]      
 */
float Bts500xxShield::readIsx(uint8_t x)
{
    float isVal;
    uint16_t adcResult;

    if(x==1)
    {

    
            hss1->enableDiag();
            isVal = getIs(1);
            hss1->disableDiag();
    }  
        
      
    return isVal;
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
float Bts500xxShield::getIs(uint8_t x)
{
    uint16_t adcResult;
    float amps, ampsCalib;
     if(x==1)
    {
        
            adcResult = hss1->readIs();
            amps = ((float)adcResult/(float)1024) * (float)5;
            ampsCalib = hss1->calibrateIs(amps, btsVariant->kilis, btsVariant->ampsOffset, btsVariant->ampsGain);

    }
    return ampsCalib;
}


/**
 * @brief Read the diagnosis of the chosen channel
 * 
 * This function uses the current signal of the channel to diagnose the channel.
 * It returns the different states depending on the channels condition.
 * 
 * @param[in]   x   Desired channel for the diagnosis (1-4)   
 * @return      Bts500xxShield::DiagStatus_t
 * 
 * @retval      0   Everything works correctly
 * @retval      2   Short to ground
 * @retval      4   Short to battery
 * @retval      5   Open load     
 */
DiagStatus_t Bts500xxShield::readDiagx(uint8_t x)
{
    DiagStatus_t diagStatus = NORMAL;

    float currentOn = 0.0;
    float currentOff = 0.0;

    if(x==1)
    {
      
            hss1->enableDiag();
            if(hss1->getSwitchStatus() == Hss::Status_t::POWER_ON){
             diagStatus = hss1->diagRead(getIs(1), btsVariant->kilis);
          
            }
            else
            {
                oloff->enable();
                timer->delayMicro(300);
                currentOn = getIs(1);
    
                oloff->disable();
                timer->delayMicro(400);
                currentOff = getIs(1);
                diagStatus = diagnosisOff(currentOn, currentOff);
               }
            hss1->disableDiag();
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
 * @return Bts500xxShield::DiagStatus_t 
 */
DiagStatus_t Bts500xxShield::diagnosisOff(float currentOn, float currentOff)
{
    if((currentOn > (0.0018 * btsVariant->kilis)) && (currentOn < (0.0044 * btsVariant->kilis))){
        if((currentOff > (0.0018 * btsVariant->kilis)) && (currentOff < (0.0044 * btsVariant->kilis))){
            return DiagStatus_t::SHORT_TO_VSS;
        }
        else{
            return DiagStatus_t::OPEN_LOAD;
        }
    }
    else{
        if((currentOn > (0.0044 * btsVariant->kilis))){
            return DiagStatus_t::SHORT_TO_GND;
        }
        else{
            return DiagStatus_t::NORMAL;
        }
    }
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