/** 
 * @file        adc-arduino.hpp
 * @brief       Arduino PAL for the ADC
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef ADC_ARDUINO_H_
#define ADC_ARDUINO_H_

#include "../../../corelib/hss.hpp"

/**
 * @brief Arduino ADC class
 * 
 */
class ADCIno : virtual public ADC
{
    private:
    uint8_t pin;

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

#endif /** ADC_ARDUINO_H_ **/