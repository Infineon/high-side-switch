/** 
 * @file        PWM.hpp
 * @brief       PWM Platform Abstraction Layer
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include <stdint.h>

#ifndef PWM_HPP_
#define PWM_HPP_

/**
 * @addtogroup hssPal 
 * @{
 */

class PWM
{
    public:

        enum Error_t
        {
            OK          =  0,    /**< No error */
            INTF_ERROR  = -1,    /**< Interface error */
            CONF_ERROR  = -2,    /**< Configuration error */
        };

        /**
         * @brief   Initialize the PWM
         * @return  PWM error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
        virtual  Error_t        init       () = 0;

        /**
         * @brief   Deinitialize the PWM
         * @return  PWM error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
        virtual  Error_t        deinit      () = 0;

        /**
         * @brief       Configures the PWM
         * @param[in]   freq    PWM frequency (in Hz)
         * @param[in]   duty    PWM duty cycle (in percentage XX.X).
         *                      From 0.00 to 100.00.
         * @return  PWM error code
         * @retval  OK if success
         * @retval  CONFIG_ERROR if invalid configuration
         * @retval  INIT_ERROR if hardware interface error
         */
        virtual Error_t         config      (uint32_t freq, float duty) = 0;

        /**
         * @brief   Enables the PWM
         * @return  PWM error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
        virtual  Error_t        enable     () = 0;

        /**
         * @brief   Disables the PWM
         * @return  PWM error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
        virtual  Error_t        disable    () = 0;
};

/** @} */

#endif /** PWM_HPP_ **/
