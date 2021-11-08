/**
 * @file        hss-bts700xShield.hpp
 * @brief       Class for BTS700x-1EPP (12V) Shield
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "hss-shield.hpp"
#include "hss-variants.hpp"
#include "hss.hpp"

using namespace hss;

class Bts700xShield : public HssShield
{
    public:
                        Bts700xShield(Hss *hsw1, Hss *hsw2, Hss *hsw3, Hss *hsw4);
                        ~Bts700xShield();

        Error_t         init();
        Error_t         deinit();
        Error_t         switchHxOn(uint8_t x);
        Error_t         switchHxOff(uint8_t x);
        Error_t         switchesHxOn(bool h1 = false, bool h2 = false, bool h3 = false, bool h4 = false);
        Error_t         switchesHxOff(bool h1 = false, bool h2 = false, bool h3 = false, bool h4 = false);
        DiagStatus_t    readDiagx(uint8_t x);
        DiagStatus_t    diagnosisOff(float currentOn, float currentOff);
        float           readIsx(uint8_t x);
        float           readVss();

        bool            digitalReadButton();
        bool            analogReadButton();

    protected:

        ExponentialFilter   *filterVbat;

        GPIOPAL             *led1;
        GPIOPAL             *led2;
        GPIOPAL             *led3;
        GPIOPAL             *led4;

        Hss                 *hss1;
        Hss                 *hss2;
        Hss                 *hss3;
        Hss                 *hss4;

        TimerPAL            *timer;

        GPIOPAL             *oloff;
        GPIOPAL             *pushButtonDigital;

        ADCPAL              *pushButtonAnalog;
        ADCPAL              *vBat;

        BtsVariants_t       *btsVariant;

        const float         vBatGain = 1.0;
        const float         vBatOffset = 0.0;

        float               getIs(uint8_t x);

};