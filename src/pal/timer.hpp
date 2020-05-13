/** 
 * @file        timer.hpp
 * @brief       Timer Platform Abstraction Layer
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include <stdint.h>

#ifndef TIMER_HPP_
#define TIMER_HPP_

class Timer
{
    public:

        enum Error_t
        {
            OK          =  0,    /**< No error */
            INTF_ERROR  = -1,    /**< Interface error */
            CONF_ERROR  = -2,    /**< Configuration error */
        };

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
        virtual  Error_t         delay   (uint32_t timeout) = 0;
        
        /**
         * @brief       Introduces a delay during the specified time
         * @param[in]   timeout     Delay time in microseconds 
         * @return      Timer error code
         * @retval      OK if success
         * @retval      INIT_ERROR if hardware interface error
         */
        virtual  Error_t        delayMicroseconds(uint32_t timeout) = 0;
};

/** @} */

#endif /** HALL_PAL_TIMER_HPP_ **/
