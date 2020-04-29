/** 
 * @file        hss-arduino.hpp
 * @brief       Definition of the High-Side-Switch Class in Arduino 
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_ARDUINO_H_
#define HSS_ARDUINO_H_

#include "corelib/hss.hpp"
#include "framework/arduino/pal/gpio-arduino.hpp"
#include "framework/arduino/pal/adc-arduino.hpp"

class HssIno : public Hss
{
    public:
                    HssIno(uint8_t den, uint8_t in, uint8_t is, BtsVariants_t *variant);
                    ~HssIno(); 
};

#endif /** HSS_ARDUINO_H_ **/