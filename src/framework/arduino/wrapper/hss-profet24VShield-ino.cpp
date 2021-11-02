/** 
 * @file        hss-profet24VShield-ino.cpp
 * @brief       Profet (24V) BTT6030 Shield Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "hss-profet24VShield-ino.hpp"
#include <Arduino.h>

using namespace hss;

/**
 * @brief Profet (24V) BTT6030 Shield constructor
 * Initialize all protected class pointers.
 */
Profet24VBTTShieldIno::Profet24VBTTShieldIno():
Profet24VBTTShield  (
                        hss0 = new HssIno(PROFET24VBTT_HWCONFIG.den_0, PROFET24VBTT_HWCONFIG.dsel_0, PROFET24VBTT_HWCONFIG.in0_0, PROFET24VBTT_HWCONFIG.is_0),
                        hss1 = new HssIno(PROFET24VBTT_HWCONFIG.den_0, PROFET24VBTT_HWCONFIG.dsel_0, PROFET24VBTT_HWCONFIG.in1_0, PROFET24VBTT_HWCONFIG.is_0),
                        hss2 = new HssIno(PROFET24VBTT_HWCONFIG.den_1, PROFET24VBTT_HWCONFIG.dsel_1, PROFET24VBTT_HWCONFIG.in0_1, PROFET24VBTT_HWCONFIG.is_1),
                        hss3 = new HssIno(PROFET24VBTT_HWCONFIG.den_1, PROFET24VBTT_HWCONFIG.dsel_1, PROFET24VBTT_HWCONFIG.in1_1, PROFET24VBTT_HWCONFIG.is_1),
                        hss4 = new HssIno(PROFET24VBTT_HWCONFIG.den_2, PROFET24VBTT_HWCONFIG.in0_2, PROFET24VBTT_HWCONFIG.is_2)
                    )
{
    

    timer = new TimerIno();
}

/**
 * @brief Profet (24V) BTT6030 Shield constructor
 * Initialize all class pointers. This constructor allows to pass custom shield configuration. 
 */
Profet24VBTTShieldIno::Profet24VBTTShieldIno(Profet24VBTTHwConfig_t config):
Profet24VBTTShield  (
                        hss0 = new HssIno(config.den_0, config.dsel_0, config.in0_0, config.is_0),
                        hss1 = new HssIno(config.den_0, config.dsel_0, config.in1_0, config.is_0),
                        hss2 = new HssIno(config.den_1, config.dsel_1, config.in0_1, config.is_1),
                        hss3 = new HssIno(config.den_1, config.dsel_1, config.in1_1, config.is_1),
                        hss4 = new HssIno(config.den_2, config.in0_2, config.is_2)
                    )
{
    timer = new TimerIno();
}

/**
 * @brief Destructor of the Profet (24V) BTT6030 Shield
 * 
 */
Profet24VBTTShieldIno::~Profet24VBTTShieldIno()
{

}