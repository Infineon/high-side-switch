/**
 * @file        hss-shield-platf.cpp
 * @brief       Platform configurations for supported shields
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "hss-shield-platf.hpp"
#include <Arduino.h>

Bts700xHwConfig_t BTS700X_HWCONFIG
{
    .led1 = 4,                      //LED 1
    .led2 = 5,                      //LED 2
    .led3 = 12,                     //LED 3
    .led4 = 13,                     //LED 4

    .in1 = 9,                       //IN 1
    .in2 = 10,                      //IN 2
    .in3 = 11,                      //IN 3
    .in4 = 3,                       //IN 4

    .oloff = 7,                     //OLOFF

    .den1_den3 = 6,                 //DEN 1_3
    .den2_den4 = 8,                 //DEN 2_4

    .pushButtonDigital = 2,         //PUSHBUTTONDIGITAL

    .pushButtonAnalog = A0,         //PUSHBUTTONANALOG
    .vBat =             A1,         //VBAT
    .is1_is2 =          A2,         //IS 1_2
    .is3_is4 =          A3          //IS 3_4
};

Profet24VBTTHwConfig_t PROFET24VBTT_HWCONFIG
{
    //Profet0 - BTT6030 (2 channel) pin config
    .in0_0  = A3,
    .den_0  = A4,
    .dsel_0 = 2,
    .in1_0  = 3,
    .is_0   = A0,

    //Profet1 - BTT6030 (2 channel) pin config
    .in0_1  = 4,
    .den_1  = 5,
    .dsel_1 = 6,
    .in1_1  = 7,
    .is_1   = A1,

    //Profet2 - BTT6020 (1 channel) pin config
    .in0_2  = 8,
    .den_2  = 9,
    .is_2   = A2,
};

BTS500xxHwConfig_t BTS500XX_HWCONFIG
{
    .led1 = 4,                      //LED 1
    .led2 = 9,                      //LED 2

    .in = 6,                       //IN 1

    .pushButtonAnalog = A0,         //PUSHBUTTONANALOG
    .vBat =             A1,         //VBAT
    .is =         A2,             //IS 1
    
};