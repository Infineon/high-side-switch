#include "hss-arduino.h"

HssIno::HssIno(uint8_t den, uint8_t in, uint8_t is)
{
    HssIno::den = new GPIOIno(den, OUTPUT, GPIOIno::POSITIVE);
    HssIno::in = new GPIOIno(in, OUTPUT, GPIOIno::POSITIVE);
    HssIno::is = new ADCIno(is);
}

HssIno::~HssIno()
{

}

// HssIno::Error_t HssIno::init()
// {

// }

// HssIno::Error_t HssIno::deinit()
// {

// }

// HssIno::Error_t HssIno::enable()
// {

// }

// HssIno::Error_t HssIno::disable()
// {

// }

// HssIno::Error_t HssIno::enableDiag()
// {

// }

// HssIno::Error_t HssIno::disableDiag()
// {

// }

// HssIno::Error_t HssIno::diagReset()
// {

// }

// HssIno::DiagStatus_t HssIno::diagRead()
// {

// }

