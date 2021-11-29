/**
 * @file        hss.hpp
 * @brief       Definition of the High-Side-Switch class functions
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef HSS_H_
#define HSS_H_

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "hss-types.hpp"
#include "hss-pal-timer.hpp"
#include "hss-pal-gpio.hpp"
#include "hss-pal-adc.hpp"
#include "hss-variants.hpp"
#include "hss-filter.hpp"

using namespace hss;

/**
 * @addtogroup hssCorelib
 * @{
 */

/**
 * @brief High-Side-Switch class
 * This class defines the High-Side-Switch Class with all its functionality
 */
class Hss
{
    public:

                            Hss(GPIOPAL *den, GPIOPAL *in, ADCPAL *is, TimerPAL *timer, BtxVariants_t *btxVariant);
                            Hss(GPIOPAL *den, GPIOPAL *in, GPIOPAL *dsel, ADCPAL *is, TimerPAL *timer, BtxVariants_t *btxVariant);
                            ~Hss();
        Error_t             init();
        Error_t             deinit();
        Error_t             enable();
        Error_t             disable();
        Error_t             enableDiag();
        Error_t             disableDiag();
        Error_t             diagReset();

        Status_t            getSwitchStatus();
        DiagStatus_t        diagRead(float senseCurrent, Channel_t ch=NO_CHANNEL);
        float               readIs(uint16_t rSense, Channel_t ch=NO_CHANNEL);

        void                setCurrentOffset(float offset);

    protected:

        GPIOPAL             *den;
        GPIOPAL             *in;
        GPIOPAL             *dsel;
        ADCPAL              *is;

        TimerPAL            *timer;

        ExponentialFilter   *currentFilter;

        BtxVariants_t       *btxVariant;
        Status_t            status;
        DiagEnable_t        diagEnb;
        DiagStatus_t        diagStatus;

        Error_t             selDiagCh(Channel_t ch=NO_CHANNEL);

    private:

        float               currentOffset = 0.0;

};

/** @} */

#endif /** HSS_H_ **/
