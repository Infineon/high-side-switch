/**
 * @file        hss-arduino.hpp
 * @brief       Definition of the High-Side-Switch Class in Arduino
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_ARDUINO_H_
#define HSS_ARDUINO_H_

#include "hss.hpp"
#include "gpio-arduino.hpp"
#include "adc-arduino.hpp"
#include "timer-arduino.hpp"

/**
 * @brief Arduino class of the High-Side-Swich
 *
 */
class HssIno : public Hss
{
    public:
    
        HssIno(uint8_t den, uint8_t in, uint8_t is, BtsVariants_t *variant);
        ~HssIno();
};

#endif /** HSS_ARDUINO_H_ **/