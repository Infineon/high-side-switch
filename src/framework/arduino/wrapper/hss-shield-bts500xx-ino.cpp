/**
 * @file        hss-bts500xxShield-ino.cpp
 * @details     BTS700x-1EPP (12V) Shield Implementation
 */

#include "hss-shield-bts500xx-ino.hpp"
#include <Arduino.h>

using namespace hss;

/**
 * @brief    Bts500xxShield High-Side-Switch constructor
 * @details  Initializes all class pointers.
 */
Bts500xxShieldIno::Bts500xxShieldIno(BtxVariants_t *variantSel):
Bts500xxShield(hss1 = new HssIno(BTS500XX_HWCONFIG.in, BTS500XX_HWCONFIG.is, variantSel),
               led1 = ((BTS500XX_HWCONFIG.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS500XX_HWCONFIG.led1, OUTPUT, GPIOIno::POSITIVE)),
               led2 = ((BTS500XX_HWCONFIG.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(BTS500XX_HWCONFIG.led2, OUTPUT, GPIOIno::POSITIVE)),
               pushButton = new ADCIno(BTS500XX_HWCONFIG.pushButtonAnalog),
               vBat = new ADCIno(BTS500XX_HWCONFIG.vBat))
{

}

/**
 * @brief    Bts500xxShield High-Side-Switch constructor for custom configuration 
 * @details  Initialize all class pointers. This constructor allows to pass custom shield configuration.
 */
Bts500xxShieldIno::Bts500xxShieldIno(BtxVariants_t *variantSel, BTS500xxHwConfig_t config):
Bts500xxShield(hss1 = new HssIno(config.in, config.is, variantSel),
               led1 = ((config.led1 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led1, OUTPUT, GPIOIno::POSITIVE)),
               led2 = ((config.led2 == GPIOIno::unusedPin) ? NULL : new GPIOIno(config.led2, OUTPUT, GPIOIno::POSITIVE)),
               pushButton = new ADCIno(config.pushButtonAnalog),
               vBat = new ADCIno(config.vBat))
{

}


/**
 * @brief Destructor of the High-Side-Switch-Board
 *
 */
Bts500xxShieldIno::~Bts500xxShieldIno()
{

}

