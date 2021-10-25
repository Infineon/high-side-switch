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

class Bts700xShield : HssShield
{
    public:
                        Bts700xShield();
                        ~Bts700xShield();

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
        GPIO *led3;
        GPIO *led4;
    
        Hss *hss1;
        Hss *hss2;
        Hss *hss3;
        Hss *hss4;
    
        Timer *timer;
    
        GPIO *oloff;
        GPIO *pushButtonDigital;
    
        AnalogDigitalConverter *pushButtonAnalog;
        AnalogDigitalConverter *vBat;
    
        const float vBatGain = 1.0;
        const float vBatOffset = 0.0;
        BtsVariants_t           *btsVariant;
};