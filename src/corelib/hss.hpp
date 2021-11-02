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
#include "timer.hpp"
#include "gpio.hpp"
#include "adc.hpp"
#include "variants.hpp"
#include "filter.hpp"

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

                    Hss();
                    Hss(GPIO *den, GPIO *in, AnalogDigitalConverter *is);
                    Hss(GPIO *den, GPIO *in, GPIO *dsel, AnalogDigitalConverter *is);
                    ~Hss();
    Error_t         init();
    Error_t         deinit();
    Error_t         enable();
    Error_t         disable();
    Error_t         enableDiag();
    Error_t         disableDiag();
    Error_t         diagReset();

    Status_t        getSwitchStatus();
    DiagStatus_t    diagRead(float amps, float iisFault, float iisOl, uint16_t kilis, Channel_t ch=NO_CHANNEL);

    uint16_t        readIs();
    float           calibrateIs(float inVal, uint16_t kilis, float ampsOffset, float ampsGain);
    

    protected:
    GPIO                    *den;
    GPIO                    *in;
    GPIO                    *dsel;
    AnalogDigitalConverter  *is;

    Timer                   *timer;

    ExponentialFilter       *currentFilter;

    Status_t                status;
    DiagEnable_t            diagEnb;
    DiagStatus_t            diagStatus;

    Error_t     selDiagCh(Channel_t ch=NO_CHANNEL);


};
/** @} */

#endif /** HSS_H_ **/
