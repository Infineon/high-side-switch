/**
 * @file        hss-bts700xShield.hpp
 * @brief       Class for BTS700x-1EPP (12V) Shield
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "hss-arduino.hpp"
#include "hss-shield.hpp"
#include "variants.hpp"
#include "hss-shield-config.hpp"

class Bts700xShieldIno : HssShield
{
    public:
                                Bts700xShieldIno(BtsVariants_t *variantSel);
                                Bts700xShieldIno(BtsVariants_t *variantSel, Bts700xHwConfig_t config);

        virtual Error_t         init();
        virtual Error_t         deinit();
        virtual Error_t         switchHxOn(uint8_t x, Channel_t ch);
        virtual Error_t         switchHxOff(uint8_t x, Channel_t ch);
        virtual DiagStatus_t    readDiagx(uint8_t x, Channel_t ch);
        virtual DiagStatus_t    diagnosisOff(float currentOn, float currentOff);
        virtual float           readIsx(uint8_t x, Channel_t ch);
        virtual float           readVss();

};