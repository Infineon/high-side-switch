/**
 * @file        hss-bts700xShield.hpp
 * @brief       Class for BTS700x-1EPP (12V) Shield
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "hss-arduino.hpp"
#include "hss-bts700xShield.hpp"
#include "variants.hpp"
#include "hss-shield-config.hpp"

class Bts700xShieldIno : Bts700xShield
{
    public:
                        Bts700xShieldIno(BtsVariants_t *variantSel);
                        Bts700xShieldIno(BtsVariants_t *variantSel, Bts700xHwConfig_t config);
                        ~Bts700xShieldIno();
        Error_t         init_shield();
        Error_t         deinit_shield();

};