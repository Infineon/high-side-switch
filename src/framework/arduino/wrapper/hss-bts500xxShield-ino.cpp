/** 
 * @file        hss-bts500xxShield.cpp
 * @brief       BTS500xx(12V) Shield Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "hss-bts500xxShield-ino.hpp"
#include <Arduino.h>

using namespace hss;
/**
 * @brief High-Side-Switch-Board constructor
 * Initialize all protected class pointers with a null pointer.
 */
Bts500xxShieldIno::Bts500xxShieldIno(BtsVariants_t *variantSel):
Bts500xxShield(hss1 = new HssIno(BTS500XX_HWCONFIG.in, BTS500XX_HWCONFIG.is))
{
    led1 = ((BTS500XX_HWCONFIG.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS500XX_HWCONFIG.led1, OUTPUT, GPIOIno::POSITIVE));
    led2 = ((BTS500XX_HWCONFIG.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS500XX_HWCONFIG.led2, OUTPUT, GPIOIno::POSITIVE));
   
    timer = new TimerIno();
   
    pushButtonAnalog = new ADCIno(BTS500XX_HWCONFIG.pushButtonAnalog);
    vBat = new ADCIno(BTS500XX_HWCONFIG.vBat);

    btsVariant = variantSel;

}

Bts500xxShieldIno::Bts500xxShieldIno(BtsVariants_t *variantSel, BTS500xxHwConfig_t config):
Bts500xxShield(hss1 = new HssIno(config.in, config.is))
{
    led1 = ((config.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led1, OUTPUT, GPIOIno::POSITIVE));
    led2 = ((config.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led2, OUTPUT, GPIOIno::POSITIVE));

    timer = new TimerIno();

    pushButtonAnalog = new ADCIno(config.pushButtonAnalog);
    vBat =  new ADCIno(config.vBat);
}


/**
 * @brief Destructor of the High-Side-Switch-Board
 * 
 */
Bts500xxShieldIno::~Bts500xxShieldIno()
{

}

