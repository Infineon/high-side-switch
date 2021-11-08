/** 
 * @file        adc.hpp
 * @brief       PAL of the ADC 
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef AnalogDigitalConverter_HPP_
#define AnalogDigitalConverter_HPP_

#include <stdint.h>
#include "hss-types.hpp"

using namespace hss;

/**
 * @addtogroup hssPal 
 * @{
 */

class AnalogDigitalConverter
{
    public:

        virtual Error_t     init() = 0;
        virtual Error_t     deinit() = 0;
        virtual Error_t     enable() = 0;
        virtual Error_t     disable() = 0;
        virtual Error_t     setReadResolution(uint8_t resolution) = 0;
        virtual Error_t     setWriteResolution(uint8_t resolution) = 0;
        virtual uint16_t    ADCRead() = 0;
        virtual Error_t     ADCWrite(uint8_t value) = 0;
        Error_t             checkErrorStatus();

        private:

        Error_t errorStatus;
};
/** @} */

#endif /** AnalogDigitalConverter_HPP_ **/


