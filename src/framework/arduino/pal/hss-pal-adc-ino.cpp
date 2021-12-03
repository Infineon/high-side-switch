/**
 * @file        hss-pal-adc-ino.hpp
 * @details     Arduino PAL for the ADC
 */

#include <Arduino.h>
#include "hss-pal-adc-ino.hpp"

/**
 * @brief Default constructor of the Arduino ADC class
 */
ADCIno::ADCIno() : pin(0)
{

}

/**
 * @brief    Constructor of the Arduino ADC class
 * @details  This constructor takes the number of the pin.
 * @param[in]   pin Number of the desired ADC pin
 */
ADCIno::ADCIno(uint8_t pin) : pin(pin)
{

}

/**
 * @brief Default constructor of the Arduino ADC
 *
 */
ADCIno::~ADCIno()
{

}

/**
 * @brief  ADC initialization
 * @return Error_t
 */
Error_t ADCIno::init()
{
    return OK;
}

/**
 * @brief ADC deinitialization
 * @return Error_t
 */
Error_t ADCIno::deinit()
{
    return OK;
}

/**
 * @brief ADC enable
 * @return Error_t
 */
Error_t ADCIno::enable()
{
    return OK;
}


/**
 * @brief ADC disable
 * @return Error_t
 */
Error_t ADCIno::disable()
{
    return OK;
}

/**
 * @brief   Set resolution of the ADC
 * @details This function sets the resolution of the ADC.
 *          The available resolutions are depending on the ADC of the device
 *          and have be looked up in the datasheet.
 *          The default resolution is set to 12 Bit, see constructor.
 * @param[in]   resolution  Value of the read resolution, default = 10 Bit
 * @return  Error_t
 */
Error_t ADCIno::setReadResolution(uint8_t resolution)
{
    // analogReadResolution(resolution);

    return OK;
}

/**
 * @brief   Set the write resolution of the ADC
 * @details This function sets the write resolution of the ADC.
 * @param[in]   resolution  Value of the write resolution of the ADC
 * @return  Error_t
 */
Error_t ADCIno::setWriteResolution(uint8_t resolution)
{
    // analogWriteResolution(resolution);

    return OK;
}

/**
 * @brief Read the current ADC-Value
 * @return uint16_t ADC value
 */
uint16_t ADCIno::ADCRead()
{
    uint16_t result = 0;

    result = analogRead(pin);

    return result;
}

/**
 * @brief   Wirte on an analog pin
 * @details This functions writes the given value to the analog pin
 * @param[in] value Value to write
 * @return  Error_t
 */
Error_t ADCIno::ADCWrite(uint8_t value)
{
    analogWrite(pin, value);

    return OK;
}

