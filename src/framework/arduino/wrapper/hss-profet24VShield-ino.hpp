/**
 * @file        hss-profet24VShield-ino.hpp
 * @brief       Profet (24V) BTT6030 Shield Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef HSS_PROFET24VSHIELD_INO_HPP_
#define HSS_PROFET24VSHIELD_INO_HPP_

#include "hss-arduino.hpp"
#include "hss-profet24VShield.hpp"
#include "variants.hpp"
#include "hss-shield-config.hpp"

using namespace hss;

class Profet24VBTTShieldIno : public Profet24VBTTShield
{
    public:
                        Profet24VBTTShieldIno();
                        Profet24VBTTShieldIno(Profet24VBTTHwConfig_t config);
                        ~Profet24VBTTShieldIno();
};

#endif /**HSS_PROFET24VSHIELD_INO_HPP_*/