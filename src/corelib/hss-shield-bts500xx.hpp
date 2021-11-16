/**
 * @file        hss-shield-bts500xx.hpp
 * @brief       BTS500xx Shield Implementation
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_SHIELD_BTS500XX_HPP_
#define HSS_SHIELD_BTS500XX_HPP_

#include "hss-shield.hpp"
#include "hss-variants.hpp"
#include "hss.hpp"

using namespace hss;

class Bts500xxShield : public HssShield
{
    public:

                        Bts500xxShield(Hss * hsw1, GPIOPAL * led1, GPIOPAL * led2, TimerPAL * timer, ADCPAL * pushButton, ADCPAL * vBat, BtsVariants_t * btsVariant);
                        ~Bts500xxShield();

        Error_t         init();
        Error_t         deinit();
        Error_t         switchHxOn(uint8_t x);
        Error_t         switchHxOff(uint8_t x);
        DiagStatus_t    readDiagx(uint8_t x=1);   // TODO: To be implemented in next ticket
        DiagStatus_t    diagnosisOff(float currentOn, float currentOff);
        float           readIsx(uint8_t x=1);
        float           readVss();
        bool            analogReadButton();
    
    protected:
        ExponentialFilter *filterVbat;

        Hss      * hss1;
        GPIOPAL  * led1;
        GPIOPAL  * led2;
        // TimerPAL * timer;
        GPIOPAL  * pushButton;
        ADCPAL   * vBat;   

        BtsVariants_t          *btsVariant;
        const float vBatGain = 1.0;
        const float vBatOffset = 0.0;

        float  getIs(uint8_t x=1);

};

#endif /** HSS_SHIELD_BTS500XX_HPP_ */