#ifndef ADC_ARDUINO_H
#define ADC_ARDUINO_H

#include <stdint.h>
#include "../../common/hss.h"

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
    Error_t     setReadResolution(uint8_t resolution);
    Error_t     setWriteResolution(uint8_t resolution);
    uint16_t    ADCRead();
    Error_t     ADCWrite(uint8_t value);
};

#endif