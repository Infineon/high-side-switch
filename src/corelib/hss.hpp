/** 
 * @file        hss.hpp
 * @brief       Defenition of the High-Side-Switch class fucntions
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
#include "../pal/gpio.hpp"
#include "../pal/adc.hpp"
#include "../config/variants.hpp"
#include "../pal/filter.hpp"

/**
 * @class Hss(High-Side-Switch)
 */

/**
 * @brief High-Side-Swithch class
 * This class defines the High-Side-Switch Class with all its functionality
 */
class Hss
{
    public:
    /**
     * @addtogroup HssData
     * @{
     */

    /**
     * @name Error codes
     * @{
     */
    enum Error_t{
        OK          = 0,     /**< No error */
        INTF_ERROR  = -1,    /**< Interface error */
        CONF_ERROR  = -2,    /**< Configuration error */
    };
    /** @} */

    /**
     * @name Status
     * @{
     */
    enum Status_t{
        UNINITED    = 0,    /**< Not initialized */
        INITED      = 1,    /**< Initiliazed */
        POWER_ON    = 2,    /**< Power on */
        POWER_OFF   = 3,    /**< Power off */
    };
    /** @} */

    /**
     * @name Diagnosis enabled
     * @{
     */
    enum DiagEnable_t{
        DIAG_EN      = 0,    /**< Enabled */
        DIAG_DIS     = 1,    /**< Disabled */
    };
    /** @} */

    /**
     * @name Diagnosis enabled
     * @{
     */
    enum DiagStatus_t{
        READ_ERROR = -1,        /**< Read Error */
        NOT_ENABLED = -2,       /**< Diagnosis not enabled */
        NORMAL = 0,             /**< Switch works correctly */
        OVERLOAD = 1,           /**< Overload of the Switch */
        SHORT_TO_GND = 2,       /**< Short to the ground */
        OVERTEMPERATURE = 3,    /**< Overtemperature */
        SHORT_TO_VSS = 4,       /**< Short to the supply voltage */
        OPEN_LOAD = 5,          /**< Open load detected */
        UNDER_LOAD = 6,         /**< Under load condition */
        INVERSE_CURRENT = 7,    /**< Inverse current */
    };
    /** @} */

                    Hss();
                    Hss(GPIO *den, GPIO *in, AnalogDigitalConverter *is, BtsVariants_t *variant);
                    ~Hss();
    Error_t         init();
    Error_t         deinit();
    Error_t         enable(uint8_t dutycycle = NULL);
    Error_t         disable();
    Error_t         enableDiag();
    Error_t         disableDiag();
    Error_t         diagReset();

    Status_t        getSwitchStatus();

    DiagStatus_t    diagRead();

    float           readIs();
    
    protected:
    GPIO                    *den;
    GPIO                    *in;
    AnalogDigitalConverter  *is;

    ExponentialFilter *currentFilter;

    BtsVariants_t   *btsVariant;
    Status_t        status;
    DiagEnable_t    diagEnb;
    DiagStatus_t    diagStatus;
    
};
/** @} */

#endif /** HSS_H_ **/
 