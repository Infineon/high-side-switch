/** 
 * @file        hss-board.hpp
 * @brief       Defenition of the High-Side-Switch-Board class
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_BOARD_HPP_
#define HSS_BOARD_HPP_

#include <Arduino.h>
#include "hss.hpp"
#include "../pal/filter.hpp"


/**
 * @brief High-Side-Switch-Board Class
 * This class defines the the PROFET-Shield with all it's functions. 
 */
class HssBoard : Hss
{
    public:

    HssBoard();
    ~HssBoard();
    Error_t init();

    Error_t switchHxOn(uint8_t x);
    //Error_t switchHxOnPWM(uint8_t x, uint8_t dutycycle); tbd
    Error_t switchHxOff(uint8_t x);
    Error_t switchesHxOn(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL);
    Error_t switchesHxOff(bool h1 = NULL, bool h2 = NULL, bool h3 = NULL, bool h4 = NULL);
    DiagStatus_t readDiagx(uint8_t x);
    DiagStatus_t diagnosisOff(float currentOn, float currentOff);
    
    float readIsx(uint8_t x);
    
    float readVss();

    bool digitalReadButton();
    bool analogReadButton();

    protected:
    
    ExponentialFilter *filterVbat;

    GPIO *led1;
    GPIO *led2;
    GPIO *led3;
    GPIO *led4;

    Hss *hss1;
    Hss *hss2;
    Hss *hss3;
    Hss *hss4;

    GPIO *oloff;
    GPIO *pushButtonDigital;

    AnalogDigitalConverter *pushButtonAnalog;        //only if a push button is assambled
    AnalogDigitalConverter *vBat;

    const float vBatGain = 1.045;
    const float vBatOffset = 0.0;
};

#endif /** HSS_BOARD_HPP_ **/