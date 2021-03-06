/** 
 * @file        config.cpp
 * @brief       Configurations for the different Platfroms
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "config.hpp"
#include <Arduino.h>

hardwareconfig_t ARDUINO_UNO
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