/** 
 * @file        hss-bts700xShield.cpp
 * @brief       BTS700x-1EPP (12V) Shield Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "hss-bts700xShield-ino.hpp"

using namespace hss;
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

    btsVariant = variantSel;

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
 * @return Bts700xShieldIno::Error_t
 */
Error_t Bts700xShieldIno::deinit()
{
    Error_t err = OK;

    err = deinit();
    
    return err;
}