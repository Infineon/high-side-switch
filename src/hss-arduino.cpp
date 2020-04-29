/** 
 * @file        hss-arduino.cpp
 * @brief       Definition of the High-Side-Switch in Arduino 
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "hss-arduino.hpp"
#include <Arduino.h>

HssIno::HssIno(uint8_t den, uint8_t in, uint8_t is, BtsVariants_t *variant)
{
    HssIno::den = new GPIOIno(den, OUTPUT, GPIOIno::POSITIVE);
    HssIno::in = new GPIOIno(in, OUTPUT, GPIOIno::POSITIVE);
    HssIno::is = new ADCIno(is);
    HssIno::btsVariant = variant;
}

HssIno::~HssIno()
{

}