/** 
 * @file        hss-shield-config.hpp
 * @brief       Configurations for different shields
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_SHIELD_CONFIG_HPP_
#define HSS_SHIELD_CONFIG_HPP_

#include <stdint.h>

/**
 * @addtogroup arduinoWrapper
 * @{
 */


/**
 * @brief Struct with all necessary defines of the Profet-Shield
 * 
 */
struct Bts700xHwConfig_t
{
    uint8_t led1;
    uint8_t led2;
    uint8_t led3;
    uint8_t led4;

    uint8_t in1;
    uint8_t in2;
    uint8_t in3;
    uint8_t in4;

    uint8_t oloff;

    uint8_t den1_den3;
    uint8_t den2_den4;

    uint8_t pushButtonDigital;

    uint8_t pushButtonAnalog;
    uint8_t vBat;
    uint8_t is1_is2;
    uint8_t is3_is4;    
};

extern Bts700xHwConfig_t BTS700X_HWCONFIG;
/** @} */

#endif /** HSS_SHIELD_CONFIG_HPP_ **/