/** 
 * @file        adc-arduino.cpp
 * @brief       Arduino PAL for the ADC
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include <Arduino.h>
#include "adc-arduino.hpp"

ADCIno::ADCIno() : pin(0)
{

}

ADCIno::ADCIno(uint8_t pin) : pin(pin)
{
    setReadResolution(12);
}

ADCIno::~ADCIno()
{

}

ADCIno::Error_t ADCIno::init()
{
    // pinMode(this->pin, INPUT);
    
    return OK;
}

ADCIno::Error_t ADCIno::deinit()
{
    return OK;
}

ADCIno::Error_t ADCIno::enable()
{
    return OK;
}

ADCIno::Error_t ADCIno::disable()
{
    return OK;
}


ADCIno::Error_t ADCIno::setReadResolution(uint8_t resolution)
{
    analogReadResolution(resolution);
    
    return OK;
}

ADCIno::Error_t ADCIno::setWriteResolution(uint8_t resolution)
{
    analogWriteResolution(resolution);
    
    return OK;
}

uint16_t ADCIno::ADCRead()
{
    uint16_t result = 0;

    result = analogRead(pin);

    return result;
}

ADCIno::Error_t ADCIno::ADCWrite(uint8_t value)
{
    analogWrite(pin, value);
    
    return OK;
}

