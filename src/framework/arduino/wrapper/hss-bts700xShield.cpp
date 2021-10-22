/** 
 * @file        hss-bts700xShield.cpp
 * @brief       BTS700x-1EPP (12V) Shield Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "hss-bts700xShield.hpp"

/**
 * @brief High-Side-Switch-Board constructor
 * Initialize all protected class pointers with a null pointer.
 */
Bts700xShieldIno::Bts700xShieldIno(BtsVariants_t *variantSel)
{
    led1 = ((ARDUINO_UNO.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(ARDUINO_UNO.led1, OUTPUT, GPIOIno::POSITIVE));
    led2 = ((ARDUINO_UNO.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(ARDUINO_UNO.led2, OUTPUT, GPIOIno::POSITIVE));
    led3 = ((ARDUINO_UNO.led3 == GPIOIno::unusedPin) ? NULL : new GPIOIno(ARDUINO_UNO.led3, OUTPUT, GPIOIno::POSITIVE));
    led4 = ((ARDUINO_UNO.led4 == GPIOIno::unusedPin) ? NULL : new GPIOIno(ARDUINO_UNO.led4, OUTPUT, GPIOIno::POSITIVE));

    hss1 = new HssIno(ARDUINO_UNO.den1_den3, ARDUINO_UNO.in1, ARDUINO_UNO.is1_is2, variantSel);
    hss2 = new HssIno(ARDUINO_UNO.den2_den4, ARDUINO_UNO.in2, ARDUINO_UNO.is1_is2, variantSel);
    hss3 = new HssIno(ARDUINO_UNO.den1_den3, ARDUINO_UNO.in3, ARDUINO_UNO.is3_is4, variantSel);
    hss4 = new HssIno(ARDUINO_UNO.den2_den4, ARDUINO_UNO.in4, ARDUINO_UNO.is3_is4, variantSel);

    timer = new TimerIno();
    
    oloff = new GPIOIno(ARDUINO_UNO.oloff, OUTPUT, GPIOIno::POSITIVE);
    pushButtonDigital = new GPIOIno(ARDUINO_UNO.pushButtonDigital, INPUT_PULLUP, GPIOIno::POSITIVE);

    pushButtonAnalog = new ADCIno(ARDUINO_UNO.pushButtonAnalog);
    vBat = new ADCIno(ARDUINO_UNO.vBat);

}

Bts700xShieldIno::Bts700xShieldIno(BtsVariants_t *variantSel, Bts700xHwConfig_t config)
{
    led1 = ((config.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led1, OUTPUT, GPIOIno::POSITIVE));
    led2 = ((config.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led2, OUTPUT, GPIOIno::POSITIVE));
    led3 = ((config.led3 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led3, OUTPUT, GPIOIno::POSITIVE));
    led4 = ((config.led4 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led4, OUTPUT, GPIOIno::POSITIVE));

    hss1 = new HssIno(config.den1_den3, config.in1, config.is1_is2, variantSel);
    hss2 = new HssIno(config.den2_den4, config.in2, config.is1_is2, variantSel);
    hss3 = new HssIno(config.den1_den3, config.in3, config.is3_is4, variantSel);
    hss4 = new HssIno(config.den2_den4, config.in4, config.is3_is4, variantSel);

    timer = new TimerIno();

    oloff = new GPIOIno(config.oloff, OUTPUT, GPIOIno::POSITIVE);
    pushButtonDigital = new GPIOIno(config.pushButtonDigital, INPUT_PULLUP, GPIOIno::POSITIVE);
    
    pushButtonAnalog = new ADCIno(config.pushButtonAnalog);
    vBat =  new ADCIno(config.vBat);
}

Bts700xShieldIno::Bts700xShieldIno()
{
    filterVbat = NULL;

    led1 = NULL;
    led2 = NULL;
    led3 = NULL;
    led4 = NULL;

    hss1 = NULL;
    hss2 = NULL;
    hss3 = NULL;
    hss4 = NULL;

    timer = NULL;

    oloff = NULL;
    pushButtonDigital = NULL;
    
    pushButtonAnalog = NULL;
    vBat = NULL;
}

/**
 * @brief Destructor of the High-Side-Switch-Board
 * 
 */
Bts700xShieldIno::~Bts700xShieldIno()
{

}

/**
 * @brief Initialize all necessary objects of the High-Side-Switch-Board
 * 
 * This function initializes all necessary objects of the High-Side-Switch-Board.
 * It retruns an error code to see if everything was initialized correctly.
 * 
 * @return Bts700xShieldIno::Error_t
 */
Error_t Bts700xShieldIno::init()
{
    hss1->init();
    hss2->init();
    hss3->init();
    hss4->init();

    timer->init();
    
    oloff->init();
    pushButtonDigital->init();

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
 * @return Bts700xShieldIno::Error_t
 */
Error_t Bts700xShieldIno::deinit()
{

    if (NULL != led1)
        led1->deinit();
    if (NULL != led2)
        led2->deinit();
    if (NULL != led3)
        led3->deinit();
    if (NULL != led4)
        led4->deinit();

    hss1->deinit();
    hss2->deinit();
    hss3->deinit();
    hss4->deinit();

    timer->deinit();

    oloff->deinit();
    pushButtonDigital->deinit();
    
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
 * @return          Bts700xShieldIno::Error_t 
 */
Error_t Bts700xShieldIno::switchHxOn(uint8_t x)
{
    switch(x)
    {
        case 1:
            hss1->enable();
            if (NULL != led1)
                led1->enable();
            break;
        
        case 2:
            hss2->enable();
            if (NULL != led2)
                led2->enable();
            break;
        
        case 3:
            hss3->enable();
            if (NULL != led3)
                led3->enable();
            break;
        
        case 4:
            hss4->enable();
            if (NULL != led4)
                led4->enable();
            break;
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
 * @return          Bts700xShieldIno::Error_t 
 */
Error_t Bts700xShieldIno::switchHxOff(uint8_t x)
{
    switch(x)
    {
        case 1:
            hss1->disable();
            if (NULL != led1)
                led1->disable();
            break;
        
        case 2:
            hss2->disable();
            if (NULL != led2)
                led2->disable();
            break;
        
        case 3:
            hss3->disable();
            if (NULL != led3)
                led3->disable();
            break;
        
        case 4:
            hss4->disable();
            if (NULL != led4) 
                led4->disable();
            break;
    }
    return OK;
}

/**
 * @brief Turn on the selected High-Side-Switches
 * 
 * This function is used to enable multiple switches at once.
 *  
 * @param[in] h1    Enable the first switch if h1 == true   
 * @param[in] h2    Enable the second switch if h2 == true 
 * @param[in] h3    Enable the third switch if h3 == true 
 * @param[in] h4    Enable the fourth switch if h4 == true 
 * @return          Bts700xShieldIno::Error_t 
 */
Error_t Bts700xShieldIno::switchesHxOn(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL)
{
    if(h1 == true){
        hss1->enable();
        if (NULL != led1)
            led1->enable();
    }

    if(h2 == true){
        hss2->enable();
        if (NULL != led2)
            led2->enable();
    }

    if(h3 == true){
        hss3->enable();
        if (NULL != led3)
            led3->enable();
    }

    if(h4 == true){
        hss4->enable();
        if (NULL != led4)
            led4->enable();
    }

    return OK;
}

/**
 * @brief Turn off the selected High-Side-Switches
 * 
 * This function is used to disable multiple switches at once.
 *  
 * @param[in] h1    Disable the first switch if h1 == true   
 * @param[in] h2    Disable the second switch if h2 == true 
 * @param[in] h3    Disable the third switch if h3 == true 
 * @param[in] h4    Disable the fourth switch if h4 == true 
 * @return          Bts700xShieldIno::Error_t 
 */
Error_t Bts700xShieldIno::switchesHxOff(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL)
{
    if(h1 == true){
        hss1->disable();
        if (NULL != led1)
            led1->disable();
    }

    if(h2 == true){
        hss2->disable();
        if (NULL != led2)
            led2->disable();
    }

    if(h3 == true){
        hss3->disable();
        if (NULL != led3)
            led3->disable();
    }

    if(h4 == true){
        hss4->disable();
        if (NULL != led4)
            led4->disable();
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
float Bts700xShieldIno::readIsx(uint8_t x)
{
    float result;
    switch (x)
    {
        case 1:
            hss1->enableDiag();
            result = hss1->readIs();
            hss1->disableDiag();
            break;
        
        case 2:
            hss2->enableDiag();
            result = hss2->readIs();
            hss2->disableDiag();
            break;
        
        case 3:
            hss3->enableDiag();
            result = hss3->readIs();
            hss3->disableDiag();
            break;

        case 4:
            hss4->enableDiag();
            result = hss4->readIs();
            hss4->disableDiag();
            break;
    }
    return result;
}

/**
 * @brief Read the diagnosis of the chosen channel
 * 
 * This function uses the current signal of the channel to diagnose the channel.
 * It returns the different states depending on the channels condition.
 * 
 * @param[in]   x   Desired channel for the diagnosis (1-4)   
 * @return      Bts700xShieldIno::DiagStatus_t
 * 
 * @retval      0   Everything works correctly
 * @retval      2   Short to ground
 * @retval      4   Short to battery
 * @retval      5   Open load     
 */
DiagStatus_t Bts700xShieldIno::readDiagx(uint8_t x)
{
    DiagStatus_t diagStatus = NORMAL;

    float currentOn = 0.0;
    float currentOff = 0.0;

    switch(x)
    {
        case 1:
            hss1->enableDiag();
            if(hss1->getSwitchStatus() == Hss::Status_t::POWER_ON){
               diagStatus = hss1->diagRead();
            }
            else{
                oloff->enable();
                timer->delayMicro(300);
                currentOn = hss1->readIs();
    
                oloff->disable();
                timer->delayMicro(400);
                currentOff = hss1->readIs();
                diagStatus = diagnosisOff(currentOn, currentOff);
            }
            hss1->disableDiag();
            break;

        case 2:
            hss2->enableDiag();
            if(hss2->getSwitchStatus() == Hss::Status_t::POWER_ON){
                diagStatus = hss2->diagRead();
            }
            else{
                oloff->enable();
                timer->delayMicro(300);
                currentOn = hss2->readIs();

                oloff->disable();
                timer->delayMicro(400);
                currentOff = hss2->readIs();
                diagStatus = diagnosisOff(currentOn, currentOff);
            }
            hss2->disableDiag();
            break;
        
        case 3:
            hss3->enableDiag();
            if(hss3->getSwitchStatus() == Hss::Status_t::POWER_ON){
                diagStatus = hss3->diagRead();
            }
            else{
                oloff->enable();
                timer->delayMicro(300);
                currentOn = hss3->readIs();

                oloff->disable();
                timer->delayMicro(400);
                currentOff = hss3->readIs();
                diagStatus = diagnosisOff(currentOn, currentOff);
            }
            hss3->disableDiag();
            break;
        
        case 4:
            hss4->enableDiag();
            if(hss4->getSwitchStatus() == Hss::Status_t::POWER_ON){
                diagStatus = hss4->diagRead();
            }
            else{
                oloff->enable();
                timer->delayMicro(300);
                currentOn = hss4->readIs();

                oloff->disable();
                timer->delayMicro(400);
                currentOff = hss4->readIs();
                diagStatus = diagnosisOff(currentOn, currentOff);
            }
            hss4->disableDiag();
            break;
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
 * @return Bts700xShieldIno::DiagStatus_t 
 */
DiagStatus_t Bts700xShieldIno::diagnosisOff(float currentOn, float currentOff)
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
float Bts700xShieldIno::readVss()
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

/**
 * @brief Read the button state
 * 
 * @retval true if button is pressed
 * @retval false if button is not pressed 
 */
bool Bts700xShieldIno::digitalReadButton()
{
    if(pushButtonDigital->read() == GPIO::GPIO_LOW)
    return true;
    else
    return false;
}

/**
 * @brief Read the button state (analog)
 * 
 * @retval true if button is pressed
 * @retval false if button is not pressed 
 */
bool Bts700xShieldIno::analogReadButton()
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