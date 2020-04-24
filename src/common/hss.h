/**
 * @file hss.h
 * @brief High-Side-Switch Abstraction Layer
 * @date March 2020
 * @copyright Copyright (c) 2020 Infineon Technologies AG
*/

#ifndef HSS_H
#define HSS_H

#include <Arduino.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "gpio.h"
#include "adc.h"
#include "variants.h"

/**
 * @class Hss(High-Side-Switch)
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
        DIAG_EN      = 0,    /**< Disabled */
        DIAG_DIS     = 1,    /**< Enabled */
    };
    /** @} */
    /**
     * @name Diagnosis enabled
     * @{
     */

    enum DiagStatus_t{
        READ_ERROR = -1,
        NOT_ENABLED = -2,
        NORMAL = 0,
        OVERLOAD = 1,
        SHORT_TO_GND = 2,
        OVERTEMPERATURE = 3,
        SHORT_TO_VSS = 4,
        OPEN_LOAD = 5,
        UNDER_LOAD = 6,
        INVERSE_CURRENT = 7,
    };
    /** @} */

                    Hss();
                    Hss(GPIO *den, GPIO *in, ADC *is, BtsVariants_t *variant);
                    ~Hss();
    Error_t         init();
    Error_t         deinit();
    Error_t         enable();
    Error_t         disable();
    Error_t         enableDiag();
    Error_t         disableDiag();
    Error_t         diagReset();

    //TODO: Include the PWM functionality

    float           readIs();
    DiagStatus_t    diagRead();
    
    protected:
    GPIO            *den;
    GPIO            *in;
    ADC             *is;

    BtsVariants_t   *btsVariant;
    Status_t        status;
    DiagEnable_t    diagEnb;
    DiagStatus_t    diagStatus;
    
};
/** @} */

#endif /** HSS_H **/
 