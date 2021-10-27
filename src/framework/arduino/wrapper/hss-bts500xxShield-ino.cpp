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
Bts500xxShieldIno::Bts500xxShieldIno(BtsVariants_t *variantSel)
{
    led1 = ((ARDUINO_UNO.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(ARDUINO_UNO.led1, OUTPUT, GPIOIno::POSITIVE));
    led2 = ((ARDUINO_UNO.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(ARDUINO_UNO.led2, OUTPUT, GPIOIno::POSITIVE));
   
    hss1 = new HssIno(ARDUINO_UNO.den1_den3, ARDUINO_UNO.in1, ARDUINO_UNO.is1_is2, variantSel);
   
    timer = new TimerIno();
   
    pushButtonAnalog = new ADCIno(ARDUINO_UNO.pushButtonAnalog);
    vBat = new ADCIno(ARDUINO_UNO.vBat);

    btsVariant = variantSel;

}

Bts500xxShieldIno::Bts500xxShieldIno(BtsVariants_t *variantSel, BTS500xxHwConfig_t config))
{
    led1 = ((config.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led1, OUTPUT, GPIOIno::POSITIVE));
    led2 = ((config.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led2, OUTPUT, GPIOIno::POSITIVE));
    
    hss1 = new HssIno(config.den1_den3, config.in1, config.is1_is2, variantSel);
    
    timer = new TimerIno();

    pushButtonAnalog = new ADCIno(config.pushButtonAnalog);
    vBat =  new ADCIno(config.vBat);
}

Bts500xxShieldIno::Bts500xxShieldIno()
{
    filterVbat = NULL;

    led1 = NULL;
    led2 = NULL;
   
    hss1 = NULL;

    timer = NULL;

    pushButtonAnalog = NULL;
    vBat = NULL;
}

/**
 * @brief Destructor of the High-Side-Switch-Board
 * 
 */
Bts500xxShieldIno::~Bts500xxShieldIno()
{

}

/**
 * @brief Initialize all necessary objects of the High-Side-Switch-Board
 * 
 * This function initializes all necessary objects of the High-Side-Switch-Board.
 * It retruns an error code to see if everything was initialized correctly.
 * 
 * @return Bts500xxShieldIno:Error_t
 */
Error_t Bts500xxShieldIno::init_shield()
{
    Error_t err = OK;

    err = init();

    return err;
}

/**
 * @brief Deinitialize all necessary objects of the High-Side-Switch-Board
 * 
 * This function deinitializes all necessary objects of the High-Side-Switch-Board.
 * It retruns an error code to see if everything was deinitialized correctly.
 * 
 * @return Bts500xxShieldIno::Error_t
 */
Error_t Bts500xxShieldIno::deinit_shield()
{
    Error_t err = OK;

    err = deinit();
    
    return err;
}