/** 
 * @file        config.hpp
 * @brief       Configurations for the different platfroms
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include <stdint.h>

/**
 * @brief Struct with all necessary defines of the Profet-Shield
 * 
 */
struct hardwareconfig_t
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

extern hardwareconfig_t ARDUINO_UNO;

#endif /** CONFIG_HPP_ **/