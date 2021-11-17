/** 
 * @file        hss-bts700xShield-ino.cpp
 * @brief       BTS700x-1EPP (12V) Shield Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "hss-shield-bts700x-ino.hpp"
#include <Arduino.h>

using namespace hss;

/**
 * @brief BTS700x Shield constructor
 * Initialize all protected class pointers.
 */
Bts700xShieldIno::Bts700xShieldIno(BtsVariants_t *variantSel):
Bts700xShield   (
                    hss1 = new HssIno(BTS700X_HWCONFIG.den1_den3, BTS700X_HWCONFIG.in1, BTS700X_HWCONFIG.is1_is2),
                    hss2 = new HssIno(BTS700X_HWCONFIG.den2_den4, BTS700X_HWCONFIG.in2, BTS700X_HWCONFIG.is1_is2),
                    hss3 = new HssIno(BTS700X_HWCONFIG.den1_den3, BTS700X_HWCONFIG.in3, BTS700X_HWCONFIG.is3_is4),
                    hss4 = new HssIno(BTS700X_HWCONFIG.den2_den4, BTS700X_HWCONFIG.in4, BTS700X_HWCONFIG.is3_is4)
                )
{
    led1 = ((BTS700X_HWCONFIG.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS700X_HWCONFIG.led1, OUTPUT, GPIOIno::POSITIVE));
    led2 = ((BTS700X_HWCONFIG.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS700X_HWCONFIG.led2, OUTPUT, GPIOIno::POSITIVE));
    led3 = ((BTS700X_HWCONFIG.led3 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS700X_HWCONFIG.led3, OUTPUT, GPIOIno::POSITIVE));
    led4 = ((BTS700X_HWCONFIG.led4 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS700X_HWCONFIG.led4, OUTPUT, GPIOIno::POSITIVE));

    timer = new TimerIno();
    
    oloff = new GPIOIno(BTS700X_HWCONFIG.oloff, OUTPUT, GPIOIno::POSITIVE);

    pushButtonDigital = new GPIOIno(BTS700X_HWCONFIG.pushButtonDigital, INPUT_PULLUP, GPIOIno::POSITIVE);

    pushButtonAnalog = new ADCIno(BTS700X_HWCONFIG.pushButtonAnalog);
    vBat = new ADCIno(BTS700X_HWCONFIG.vBat);

    btsVariant = variantSel;

}

/**
 * @brief BTS700x Shield constructor
 * Initialize all class pointers. This constructor allows to pass custom shield configuration. 
 */
Bts700xShieldIno::Bts700xShieldIno(BtsVariants_t *variantSel, Bts700xHwConfig_t config):
Bts700xShield   (
                    hss1 = new HssIno(config.den1_den3, config.in1, config.is1_is2),
                    hss2 = new HssIno(config.den2_den4, config.in2, config.is1_is2),
                    hss3 = new HssIno(config.den1_den3, config.in3, config.is3_is4),
                    hss4 = new HssIno(config.den2_den4, config.in4, config.is3_is4)
                )
{
    led1 = ((config.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led1, OUTPUT, GPIOIno::POSITIVE));
    led2 = ((config.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led2, OUTPUT, GPIOIno::POSITIVE));
    led3 = ((config.led3 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led3, OUTPUT, GPIOIno::POSITIVE));
    led4 = ((config.led4 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led4, OUTPUT, GPIOIno::POSITIVE));

    timer = new TimerIno();

    oloff = new GPIOIno(config.oloff, OUTPUT, GPIOIno::POSITIVE);
    pushButtonDigital = new GPIOIno(config.pushButtonDigital, INPUT_PULLUP, GPIOIno::POSITIVE);
    
    pushButtonAnalog = new ADCIno(config.pushButtonAnalog);
    vBat =  new ADCIno(config.vBat);

    btsVariant = variantSel;
}

/**
 * @brief Destructor of the BTS700x Shield
 * 
 */
Bts700xShieldIno::~Bts700xShieldIno()
{

}