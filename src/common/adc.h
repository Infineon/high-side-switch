#include "gpio.h"


/**
 * @class ADC
 */
/**
 * @addtogroup hallswitchhwi
 * @{
 */ 
class ADC: public GPIO
{
    public:
    virtual Error_t     setReadResolution(uint8_t resolution) = 0;
    virtual Error_t     setWriteResolution(uint8_t resolution) = 0;
    virtual uint16_t    ADCRead() = 0;
    virtual Error_t     ADCWrite(uint8_t value) = 0;
};
/** @} */



