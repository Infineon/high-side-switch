/**
 * @file        hss-pal-adc-ino.hpp
 * @details     Ino PAL for the ADC
 */

#ifndef HSS_PAL_ADC_INO_HPP
#define HSS_PAL_ADC_INO_HPP

#include "hss-pal-adc.hpp"

using namespace hss;

/**
 * @addtogroup arduinoPal
 * @{
 */

/**
 * @class  ADC ino class
 * @details Class implementing arduino ADC functionality
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