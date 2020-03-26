/** 
 * @file        hss-arduino.h
 * @brief       High-Side-Switch Arduino interface
 * 
 *  Wraps the Arduino GPIO Reference Language calls
 * 
 * @date        March 2020
 * @copyright   Copyright (c) 2020 Infineon Technologies AG
 */


#ifndef GPIO_ARDUINO_H
#define GPIO_ARDUINO_H

#include "../../common/hss.h"

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
    Error_t     write (VLevel_t level);
    Error_t     enable();
    Error_t     disable();
};

#endif
