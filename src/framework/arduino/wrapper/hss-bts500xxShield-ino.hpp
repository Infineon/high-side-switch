/**
 * @file        hss-bts500xxShield.hpp
 * @brief       Class for BTS500xx-1EPP (12V) Shield
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "hss-arduino.hpp"
#include "hss-bts500xxShield.hpp"
#include "variants.hpp"
#include "hss-shield-config.hpp"

class Bts500xxShieldIno : Bts500xxShield
{
    public:
                        Bts500xxShieldIno(BtsVariants_t *variantSel);
                        Bts500xxShieldIno(BtsVariants_t *variantSel, BTShardwareconfig_t config);
                        ~Bts500xxShieldIno();
        Error_t         init();
        Error_t         deinit();

};