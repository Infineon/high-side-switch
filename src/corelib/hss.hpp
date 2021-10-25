/**
 * @file        hss.hpp
 * @brief       Definition of the High-Side-Switch class functions
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef HSS_H_
#define HSS_H_

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "timer.hpp"
#include "gpio.hpp"
#include "adc.hpp"
#include "variants.hpp"
#include "filter.hpp"

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

                    Hss();
                    Hss(GPIO *den, GPIO *in, AnalogDigitalConverter *is, BtsVariants_t *variant);
                    ~Hss();
    Error_t         init();
    Error_t         deinit();
    Error_t         enable();
    Error_t         disable();
    Error_t         enableDiag();
    Error_t         disableDiag();
    Error_t         diagReset();

    Status_t        getSwitchStatus();

    DiagStatus_t    diagRead_BTS();

    float           readIs_BTS();

    protected:
    GPIO                    *den;
    GPIO                    *in;
    GPIO                    *dsel;
    AnalogDigitalConverter  *is;

    Timer                   *timer;

    ExponentialFilter       *currentFilter;
    BtsVariants_t           *btsVariant;

    Status_t                status;
    DiagEnable_t            diagEnb;
    DiagStatus_t            diagStatus;

};
/** @} */

#endif /** HSS_H_ **/
