#include "hss-arduino.h"

HssIno::HssIno(uint8_t den, uint8_t in, uint8_t is)
:hss_ino(new GPIOIno(den, INPUT_PULLUP, GPIO::POSITIVE),
         new GPIOIno(in, INPUT_PULLUP, GPIO::POSITIVE),
         new ADCIno(is))
{
    
}

HssIno::~HssIno()
{
    hss_ino.~Hss();
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

