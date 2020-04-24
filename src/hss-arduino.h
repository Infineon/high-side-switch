#ifndef HSS_ARDUINO_H
#define HSS_ARDUINO_H

#include "common/hss.h"

//this i would say you don´t need here... 
#include "pal/arduino/adc-arduino.h"
#include "pal/arduino/gpio-arduino.h"
//

class HssIno : public Hss
{
    public:
                    HssIno(uint8_t den, uint8_t in, uint8_t is, BtsVariants_t *variant);
                    ~HssIno(); 
};

#endif