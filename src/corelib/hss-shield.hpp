/**
 * @file        hss-shield.hpp
 * @brief       Defenition of the High-Side-Switch-Shield class
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_SHIELD_HPP_
#define HSS_SHIELD_HPP_

#include "hss-types.hpp"
#include <stdint.h>

using namespace hss;
/**
 * @addtogroup hssCorelib
 * @{
 */

/**
 * @brief High-Side-Switch-Board Class
 * This class is the base class for the PROFET-Shield with all it's functions.
 */

class HssShield : Hss
{
    public:
                            HssShield();
                            ~HssShield();
               
        virtual Error_t      init()   = 0;
        virtual Error_t      deinit() = 0;
        virtual Error_t      switchHxOn(uint8_t x, Channel_t ch)  = 0;
        virtual Error_t      switchHxOff(uint8_t x, Channel_t ch) = 0;
        virtual DiagStatus_t readDiagx(uint8_t x, Channel_t ch) = 0;
        virtual DiagStatus_t diagnosisOff(float currentOn, float currentOff) = 0;
        virtual float        readIsx(uint8_t x, Channel_t ch)= 0;
        virtual float        readVss()=0;
};

/** @} */

#endif /** HSS_SHIELD_HPP_ **/
