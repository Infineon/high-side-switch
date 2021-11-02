/**
 * @file        hss-pal-adc-ino.hpp
 * @brief       Arduino PAL for the ADC
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef HSS_PAL_ADC_INO_HPP
#define HSS_PAL_ADC_INO_HPP

#include "hss-pal-adc.hpp"

/**
 * @addtogroup arduinoPal
 * @{
 */

/**
 * @brief Arduino ADC class
 *
 */
class ADCIno : virtual public ADCPAL
{
    private:

        uint8_t     pin;

    public:

                    ADCIno();
                    ADCIno(uint8_t pin);
                    ~ADCIno();
        Error_t     init();
        Error_t     deinit();
        Error_t     enable();
        Error_t     disable();
        Error_t     setReadResolution(uint8_t resolution);
        Error_t     setWriteResolution(uint8_t resolution);
        uint16_t    ADCRead();
        Error_t     ADCWrite(uint8_t value);
};

/** @} */

#endif /** HSS_PAL_ADC_INO_HPP **/