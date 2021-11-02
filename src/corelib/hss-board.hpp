/**
 * @file        hss-board.hpp
 * @brief       Definition of the High-Side-Switch-Board class
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_BOARD_HPP_
#define HSS_BOARD_HPP_

#include "hss.hpp"
#include "hss-filter.hpp"

using namespace hss;

/**
 * @addtogroup hssCorelib
 * @{
 */

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
        Error_t deinit();

        Error_t switchHxOn(uint8_t x);
        Error_t switchHxOff(uint8_t x);
        Error_t switchesHxOn(bool h1 = false, bool h2 = false, bool h3 = false, bool h4 = false);
        Error_t switchesHxOff(bool h1 = false, bool h2 = false, bool h3 = false, bool h4 = false);
        DiagStatus_t readDiagx(uint8_t x);
        DiagStatus_t diagnosisOff(float currentOn, float currentOff);

        float readIsx(uint8_t x);

        float readVss();

        bool digitalReadButton();
        bool analogReadButton();

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

        const float         vBatGain = 1.0;
        const float         vBatOffset = 0.0;
    };

/** @} */

#endif /** HSS_BOARD_HPP_ **/
