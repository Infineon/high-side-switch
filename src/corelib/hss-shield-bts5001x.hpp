/**
 * @file        hss-shield-bts500xx.hpp
 * @details     Class for BTS500xx (12V) Shield Implementation
 */

#ifndef HSS_SHIELD_BTS5001X_HPP_
#define HSS_SHIELD_BTS5001X_HPP_

#include "hss-shield.hpp"
#include "hss-variants.hpp"
#include "hss.hpp"

using namespace hss;

class Bts5001xShield : public HssShield
{
    public:

                        Bts5001xShield(Hss * hsw1, GPIOPAL * led2, GPIOPAL * led3, ADCPAL * pushButton, ADCPAL * vBat);
                        ~Bts5001xShield();

        Error_t         init();
        Error_t         deinit();
        Error_t         switchHxOn(uint8_t x = 0);
        Error_t         switchHxOff(uint8_t x = 0);
        DiagStatus_t    readDiagx(uint8_t x = 0);

        float           readIsx(uint8_t x=1);
        float           readVss();
        bool            analogReadButton();

        void            setVoltageOffset(float offset);

    protected:

        ExponentialFilter *filterVbat;

        Hss      * hss1;
        GPIOPAL  * led2;
        GPIOPAL  * led3;
        ADCPAL   * pushButton;
        ADCPAL   * vBat;

    private:

        const uint16_t  rSense = 1000;
        float           vBatOffset = 0.0;

};

#endif /** HSS_SHIELD_BTS5001X_HPP_ */