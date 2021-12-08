/**
 * @file        hss-shield-btt60xx-ino.hpp
 * @brief       Profet (24V) BTT6030 Shield Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef HSS_SHIELD_BTT60XX_INO_HPP_
#define HSS_SHIELD_BTT60XX_INO_HPP_

#include "hss-arduino.hpp"
#include "hss-shield-btt60xx.hpp"
#include "hss-variants.hpp"
#include "hss-shield-platf.hpp"

using namespace hss;

class Btt60xxShieldIno : public Btt60xxShield
{
    public:
                        Btt60xxShieldIno();
                        Btt60xxShieldIno(Btt60xxHwConfig_t config);
                        ~Btt60xxShieldIno();
};

#endif /** HSS_SHIELD_BTT60XX_INO_HPP_ **/