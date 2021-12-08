/**
 * @file        hss-bts5001xShield.hpp
 * @brief       Class for BTS5001x
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef HSS_SHIELD_BTS5001X_INO_HPP_
#define HSS_SHIELD_BTS5001X_INO_HPP_

#include "hss-arduino.hpp"
#include "hss-shield-bts5001x.hpp"
#include "hss-variants.hpp"
#include "hss-shield-platf.hpp"

using namespace hss;

class Bts5001xShieldIno : public Bts5001xShield
{
    public:
                        Bts5001xShieldIno(BtxVariants_t *variantSel);
                        Bts5001xShieldIno(BtxVariants_t *variantSel, BTS5001xHwConfig_t config);
                        ~Bts5001xShieldIno();

};

#endif /** HSS_SHIELD_BTS5001X_INO_HPP_ **/
