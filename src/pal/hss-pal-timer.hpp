/**
 * @file        hss-pal-timer.hpp
 * @brief       Timer Platform Abstraction Layer
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include <stdint.h>
#include "hss-types.hpp"

#ifndef HSS_PAL_TIMER_HPP_
#define HSS_PAL_TIMER_HPP_

namespace hss
{

using namespace hss;
/**
 * @addtogroup hssPal
 * @{
 */

class TimerPAL
{
    public:

        /**
         * @brief   Initialize the timer
         * @return  Timer error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
        virtual  Error_t         init    () = 0;

        /**
         * @brief   Deinitialize the timer
         * @return  Timer error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
        virtual  Error_t         deinit   () = 0;

        /**
         * @brief   Starts the timer
         * @return  Timer error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
        virtual  Error_t         start   () = 0;

        /**
         * @brief       Elapsed time since the timer was started
         * @param[out]  elapsed Time in milliseconds
         * @return      Timer error code
         * @retval      OK if success
         * @retval      INIT_ERROR if hardware interface error
         */
        virtual  Error_t         elapsed (uint32_t &elapsed) = 0;

        /**
         * @brief   Stops the timer
         * @return  Timer error code
         * @retval  OK if success
         * @retval  INIT_ERROR if hardware interface error
         */
        virtual  Error_t         stop    () = 0;

        /**
         * @brief       Introduces a delay during the specified time
         * @param[in]   timeout    Delay time in milliseconds
         * @return      Timer error code
         * @retval      OK if success
         * @retval      INIT_ERROR if hardware interface error
         */
        virtual  Error_t        delayMilli (uint32_t timeout) = 0;

        /**
         * @brief       Introduces a delay during the specified time
         * @param[in]   timeout     Delay time in microseconds
         * @return      Timer error code
         * @retval      OK if success
         * @retval      INIT_ERROR if hardware interface error
         */
        virtual  Error_t        delayMicro  (uint32_t timeout) = 0;

};

/** @} */

}

#endif /** HSS_PAL_TIMER_HPP_ **/
