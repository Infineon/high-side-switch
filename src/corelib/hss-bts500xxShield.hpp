/**
 * @file        hss-bts500xxShield.hpp
 * @brief       Class for BTS700x-1EPP (12V) Shield
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "hss-arduino.hpp"
#include "hss-shield.hpp"
#include "variants.hpp"
#include "hss-shield-config.hpp"
#include "hss.hpp"

using namespace hss;

class Bts500xxShield : HssShield 
{
    public:
                    Bts500xxShield();

                    ~Bts500xxShield();


        Error_t         init();
        Error_t         deinit();
        Error_t         switchHxOn(uint8_t x, Channel_t ch=NULL_CHANNEL);
        Error_t         switchHxOff(uint8_t x, Channel_t ch=NULL_CHANNEL);
        DiagStatus_t    readDiagx(uint8_t x, Channel_t ch=NULL_CHANNEL);
        DiagStatus_t    diagnosisOff(float currentOn, float currentOff);
        float           readIsx(uint8_t x, Channel_t ch=NULL_CHANNEL);
        float           readVss();
    
    protected:
        ExponentialFilter *filterVbat;

        
        GPIO *led1;
        GPIO *led2;

        Hss *hss1;

    AnalogDigitalConverter *pushButtonAnalog;
    AnalogDigitalConverter *vBat;   
}