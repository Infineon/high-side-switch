/**
 * @file        hss-bts500xxShield.hpp
 * @brief       Class for BTS700x-1EPP (12V) Shield
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "hss-shield.hpp"
#include "hss-variants.hpp"
#include "hss.hpp"

using namespace hss;

class Bts500xxShield : public HssShield
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

        ExponentialFilter   *filterVbat;


        GPIOPAL             *led1;
        GPIOPAL             *led2;

        Hss                 *hss1;

        TimerPAL            *timer;

        ADCPAL              *pushButtonAnalog;
        ADCPAL              *vBat;

};