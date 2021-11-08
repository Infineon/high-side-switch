/** 
 * @file        adc.cpp
 * @brief       PAL of the ADC 
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "adc.hpp"

Error_t AnalogDigitalConverter::checkErrorStatus()
{
    return errorStatus;
}