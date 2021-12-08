/**
 * @file        hss-arduino.hpp
 * @details     Definition of the High-Side-Switch Class in Arduino
 */

#ifndef HSS_ARDUINO_HPP_
#define HSS_ARDUINO_HPP_

#include "hss.hpp"
#include "hss-pal-gpio-ino.hpp"
#include "hss-pal-adc-ino.hpp"
#include "hss-pal-timer-ino.hpp"

/**
 * @class   HssIno
 * @details Arduino class of the High-Side-Swich
 */
class HssIno : public Hss
{
    public:
        HssIno(uint8_t in, uint8_t is, BtxVariants_t * btxVariant);
        HssIno(uint8_t den, uint8_t in, uint8_t is, BtxVariants_t * btxVariant);
        HssIno(uint8_t den, uint8_t in0, uint8_t in1, uint8_t dsel, uint8_t is, BtxVariants_t * btxVariant);
        ~HssIno();
};

#endif /** HSS_ARDUINO_HPP_ **/