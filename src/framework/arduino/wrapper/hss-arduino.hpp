/**
 * @file        hss-arduino.hpp
 * @brief       Definition of the High-Side-Switch Class in Arduino
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_ARDUINO_HPP_
#define HSS_ARDUINO_HPP_

#include "hss.hpp"
#include "hss-pal-gpio-ino.hpp"
#include "hss-pal-adc-ino.hpp"
#include "hss-pal-timer-ino.hpp"

/**
 * @brief Arduino class of the High-Side-Swich
 *
 */
class HssIno : public Hss
{
    public:

        HssIno(uint8_t den, uint8_t in, uint8_t is, BtsVariants_t *variant); // TODO: Remove this constructor
        HssIno(uint8_t den, uint8_t in, uint8_t is);
        HssIno(uint8_t den, uint8_t in, uint8_t dsel, uint8_t is);
        ~HssIno();
};

#endif /** HSS_ARDUINO_HPP_ **/