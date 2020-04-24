#include "hss-arduino.h"

HssIno::HssIno(uint8_t den, uint8_t in, uint8_t is, BtsVariants_t *variant)
{
    HssIno::den = new GPIOIno(den, OUTPUT, GPIOIno::POSITIVE);
    HssIno::in = new GPIOIno(in, OUTPUT, GPIOIno::POSITIVE);
    HssIno::is = new ADCIno(is);
    HssIno::btsVariant = variant;
}

HssIno::~HssIno()
{

}