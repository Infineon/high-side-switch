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

/**
 * @brief Constructor of the Arduino High-Side-Switch class
 * 
 * This functions is the default constructor of the Arduino High-Side-Switch class.
 * There are different variants of the High-Side-Switch, therefore you have to chose one.
 * 
 * @param[in]   den         Pin number of the diagnostic enable pin 
 * @param[in]   in          Pin number of the input pin
 * @param[in]   is          Pin number of the sense current output 
 * @param[in]   variant     Variant identifier (see variants.cpp)  
 */
HssIno::HssIno(uint8_t den, uint8_t in, uint8_t is, BtsVariants_t *variant)
{
    HssIno::den = new GPIOIno(den, OUTPUT, GPIOIno::POSITIVE);
    HssIno::in = new GPIOIno(in, OUTPUT, GPIOIno::POSITIVE);
    HssIno::is = new ADCIno(is);
    HssIno::btsVariant = variant;
    HssIno::timer = new TimerIno();
}

/**
 * @brief Destructor of the Arduino High-Side-Switch
 * 
 */
HssIno::~HssIno()
{

}