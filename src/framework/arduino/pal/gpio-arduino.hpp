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

#include "hss.hpp"

/**
 * @addtogroup arduinoPal
 * @{
 */


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

    static constexpr uint8_t  unusedPin = 0xFFU;

                GPIOIno();
                GPIOIno(uint8_t pin, uint8_t mode, VLogic_t logic);
                ~GPIOIno();
    Error_t     init();
    Error_t     deinit();
    VLevel_t    read();
    Error_t     write(VLevel_t level);
    Error_t     enable();
    Error_t     disable();
};
/** @} */

#endif /** GPIO_ARDUINO_H_ **/
