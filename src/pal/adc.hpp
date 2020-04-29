/** 
 * @file        adc.hpp
 * @brief       PAL of the ADC 
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef ADC_HPP_
#define ADC_HPP_

#include <stdint.h>

/**
 * @class ADC
 */
/**
 * @addtogroup hallswitchhwi
 * @{
 */ 
class ADC
{
    public:

    enum Error_t
    {
        OK          =  0,    /**< No error */
        INTF_ERROR  = -1,    /**< Interface error */
        CONF_ERROR  = -2,    /**< Configuration error */
        READ_ERROR  = -3,    /**< Read error */
        WRITE_ERROR = -4,    /**< Write error */
    };

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

#endif /** ADC_HPP_ **/


