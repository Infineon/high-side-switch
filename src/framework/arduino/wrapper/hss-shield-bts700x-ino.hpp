/**
 * @file        hss-bts700xShield-ino.hpp
 * @brief       Class for BTS700x-1EPP (12V) Shield
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef HSS_SHIELD_BTS700X_INO_HPP_
#define HSS_SHIELD_BTS700X_INO_HPP_

#include "hss-arduino.hpp"
#include "hss-shield-bts700x.hpp"
#include "hss-variants.hpp"
#include "hss-shield-platf.hpp"

using namespace hss;

class Bts700xShieldIno : public Bts700xShield
{
    public:
                        Bts700xShieldIno(BtsVariants_t *variantSel);
                        Bts700xShieldIno(BtsVariants_t *variantSel, Bts700xHwConfig_t config);
                        ~Bts700xShieldIno();
};

#endif /** HSS_SHIELD_BTS700X_INO_HPP_ **/