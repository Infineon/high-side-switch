/** 
 * @file        gpio-arduino.hpp
 * @brief       Arduino PAL for the GPIO
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */


#ifndef GPIO_ARDUINO_H_
#define GPIO_ARDUINO_H_

#include "../../../corelib/hss.hpp"

/**
 * @brief Arduino GPIO class
 * 
 */
class GPIOIno: virtual public GPIO
{
private:
    uint8_t     pin;
    uint8_t     mode;
    VLogic_t    logic;

public:
                GPIOIno();
                GPIOIno(uint8_t pin, uint8_t mode, VLogic_t logic);
                ~GPIOIno();
    Error_t     init();
    Error_t     deinit();
    VLevel_t    read();
    Error_t     write(VLevel_t level);
    // Error_t     writePWM(uint8_t dutycycle);
    Error_t     enable();
    Error_t     disable();
};

#endif /** GPIO_ARDUINO_H_ **/
