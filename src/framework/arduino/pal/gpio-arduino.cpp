/** 
 * @file        gpio-arduino.hpp
 * @brief       Arduino PAL for the GPIO
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include <Arduino.h>
#include "gpio-arduino.hpp"

GPIOIno::GPIOIno() : pin(0), mode(OUTPUT), logic(POSITIVE)
{

}

GPIOIno::GPIOIno(uint8_t pin, uint8_t mode, VLogic_t logic)
: pin(pin), mode(mode), logic(logic)
{

}

GPIOIno::Error_t GPIOIno::init()
{
    pinMode(this->pin, this->mode);
    return OK;
}

GPIOIno::Error_t GPIOIno::deinit()
{
    return OK;
}

GPIOIno::VLevel_t GPIOIno::read()
{
    return (VLevel_t) digitalRead(this->pin);
}

GPIOIno::Error_t GPIOIno::write(VLevel_t level)
{
    digitalWrite(this->pin, level);
    return OK;
}

GPIOIno::Error_t GPIOIno::enable()
{
    if(this->logic == POSITIVE){
        digitalWrite(this->pin, GPIO_HIGH);
    }
    else if(this->logic == NEGATIVE){
        digitalWrite(this->pin, GPIO_LOW);
    }
    return OK;
}

GPIOIno::Error_t GPIOIno::disable()
{
    if(this->logic == POSITIVE){
        digitalWrite(this->pin, GPIO_LOW);
    }
    else if(this->logic == NEGATIVE){
        digitalWrite(this->pin, GPIO_HIGH);
    }
    return OK;
}





