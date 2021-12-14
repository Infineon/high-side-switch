/**
 * @file        hss-pal-adc.hpp
 * @brief       ADC platform abstraction layer class
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_PAL_ADC_HPP_
#define HSS_PAL_ADC_HPP_

#include <stdint.h>
#include "hss-types.hpp"

namespace hss
{

/**
 * @addtogroup hssPal
 * @{
 */

/**
 * @class   ADCPAL
 * @brief   ADC abstract API
 */
class ADCPAL
{
    public:

        /**
		 * @brief       Initializes the ADC
		 * @return      Error_t    
		 */
        virtual Error_t     init() = 0;

        /**
		 * @brief       Deinitializes the ADC
		 * @return      Error_t      
		 */
        virtual Error_t     deinit() = 0;

        /**
         * @brief       Enable the ADC
         * @return      Error_t      
         */
        virtual Error_t     enable() = 0;

        /**
         * @brief       Disable the ADC
         * @return      Error_t      
         */
        virtual Error_t     disable() = 0;

        /**
         * @brief       Set the read resolution of the ADC
         * @param[in]   resolution  Desired read resolution of the ADC
         * @return      Error_t     
         */
        virtual Error_t     setReadResolution(uint8_t resolution) = 0;

        /**
         * @brief       Set the write resolution of the ADC
         * @param[in]   resolution  Desired write resolution of the ADC
         * @return      Error_t     
         */
        virtual Error_t     setWriteResolution(uint8_t resolution) = 0;

        /**
         * @brief       Reads the analog value on the ADC
         * @return      Analog value of the ADC (uint16_t)
         */
        virtual uint16_t    ADCRead() = 0;

        /**
         * @brief       Write a desired analog value
         * @param[in]   value       Desired analog value
         * @return      Error_t     
         */
        virtual Error_t     ADCWrite(uint8_t value) = 0;

};

/** @} */

}

#endif /** HSS_PAL_ADC_HPP_ **/


